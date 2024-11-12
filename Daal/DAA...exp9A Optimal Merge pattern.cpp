// EXP 9A: Optimal Merge Pattren
#include <iostream>
#include <climits>
#define MAX 100
using namespace std;

int mergeFiles(int files[], int size) {
    int total_cost = 0;

    for (int i = 1; i < size; i++) {
        // finding the initial smallest values
        int min1 = INT_MAX, min2 = INT_MAX;
        int min1_index = -1, min2_index = -1;  //storing the position where the smallest value are stored, initialised to -1

        for (int j = 0; j < size; j++) {
            if (files[j] != -1 && files[j] < min1) {  // marking merged file as -1 so that can be sorted again
                min2 = min1;
                min2_index = min1_index;
                min1 = files[j];
                min1_index = j;
            } else if (files[j] != -1 && files[j] < min2) {
                min2 = files[j];
                min2_index = j;
            }
        }

        // merging the two smallest files
        int cost = min1 + min2;
        total_cost += cost;

        // marking the merged files
        files[min1_index] = cost;
        files[min2_index] = -1;

        cout << "Merging files with sizes " << min1 << " and " << min2 << " (cost: " << cost << ")\n";
    }
    return total_cost;
}

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    int files[MAX];
    cout << "Enter the sizes of the files:\n";
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }
    int total_cost = mergeFiles(files, n);

    cout << "Total minimum cost of merging files: " << total_cost << endl;
    return 0;
}

