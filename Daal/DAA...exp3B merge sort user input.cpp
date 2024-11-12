//EXP 3B: MERGE SORT user input for the array
#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void printarray(int arr[], int n) {
    for(int i = 0; i < n; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void printarray1(int arr[], int n) {
    if (n > 0) {
        cout << arr[0] << " "; // print the first element
        for(int i = 1; i < n; i++) {
            if (arr[i] != arr[i-1]) {
                cout << arr[i] << " ";
            }
        }
    }
    cout << endl;
}

void merge(int arr[], int l, int m, int r, int &pass) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    cout << "\nPass " << pass << ": ";
    pass++;
    printarray(arr, r - l + 1);
}

void mergesort(int arr[], int l, int r, int &pass) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergesort(arr, l, m, pass);
        mergesort(arr, m + 1, r, pass);

        merge(arr, l, m, r, pass);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements that you want in the array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the element: ";
        cin >> arr[i];
    }
    
    cout << "\nPrinting unsorted array: " << endl;
    printarray(arr, n);
    
    int pass = 1;
    auto start = high_resolution_clock::now();
    mergesort(arr, 0, n - 1, pass);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "\nSorted array without repetition: " << endl;
    printarray1(arr, n);
    
    cout << "\nTime taken for merge sort: " << duration.count() << " microseconds" << endl;
    
    return 0;
}

