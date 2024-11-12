// EXP 9B: Optimal Merge Pattern (Multiplier and 500 below)
#include <iostream>
#include <climits>
#define MAX 100
using namespace std;

struct File {
    int size;
    float multiplier;
};

int optimalMerge(File files[], int size) {
    int total_cost = 0;

    for (int i = 1; i < size; i++) {
        // finding the initial smallest values
        int min1 = INT_MAX, min2 = INT_MAX;
        int min1_index = -1, min2_index = -1;    // storing the positions of the smallest values

        for (int j = 0; j < size; j++) {
            if (files[j].size != -1 && files[j].size < min1) {  // marking merged file as -1 so it can be ignored in the future
                min2 = min1;
                min2_index = min1_index;
                min1 = files[j].size;
                min1_index = j;
            } else if (files[j].size != -1 && files[j].size < min2) {
                min2 = files[j].size;
                min2_index = j;
            }
        }

        // ensuring the merge does not exceed 500 GB
        if (min1 + min2 > 500) {
            cout << "Cannot merge files exceeding 500 GB." << endl;
            break;
        }

        // calculating the merging cost
        float cost = (min1 * files[min1_index].multiplier) + (min2 * files[min2_index].multiplier);
        total_cost += cost;

        // averaging the multiplier for the merged file
        float new_multiplier = (files[min1_index].multiplier + files[min2_index].multiplier) / 2;

        // merging the files and update the array
        files[min1_index].size = min1 + min2;
        files[min1_index].multiplier = new_multiplier;  // update with the new average multiplier
        files[min2_index].size = -1; 

        cout << "Merging files with sizes " << min1 << " and " << min2 
             << " (cost: " << cost << ", new multiplier: " << new_multiplier << ")\n";
    }

    return total_cost;
}

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    File files[MAX];
    cout << "Enter the sizes of the files and their cost multipliers:\n";
    for (int i = 0; i < n; i++) {
        cin >> files[i].size >> files[i].multiplier;
    }
    
    int total_cost = optimalMerge(files, n);
    cout << "Total minimum cost of merging files: " << total_cost << endl;
    
    return 0;
}

