//EXP 2: QUICK SORT
// First subarray is arr[l..m] and second subarray is arr[m+1..r]
// not printing duplicate elements in the sorted array
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//not printing repeating elements
void printArray1(int arr[], int size) {
    if (size > 0) {
        cout << arr[0] << " ";
    }
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int partition(int arr[], int low, int high, int &pass) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    pass++;
    cout << "Pass " << pass << " (Pivot: " << pivot << "): ";
    printArray(arr, high - low + 1);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int &pass) {
    if (low < high) {
        int pi = partition(arr, low, high, pass);

        quickSort(arr, low, pi - 1, pass);
        quickSort(arr, pi + 1, high, pass);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    int n;

    cout << "Enter the number of elements you want to sort: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; // Random values between 1 and 100
    }

    cout << "Initial array: ";
    printArray(arr, n);

    int pass = 0;

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1, pass);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted array without repetition: ";
    printArray1(arr, n);

    cout << "Time taken for Quick Sort: " << duration.count() << " microseconds" << endl;

    return 0;
}


/*

//STRING INPUT
#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

void printArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Not printing repeating elements
void printArray1(char arr[], int size) {
    if (size > 0) {
        cout << arr[0] << " ";
    }
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int partition(char arr[], int low, int high, int &pass) {
    char pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    pass++;
    cout << "Pass " << pass << " (Pivot: " << pivot << "): ";
    printArray(arr, high - low + 1);
    return (i + 1);
}

void quickSort(char arr[], int low, int high, int &pass) {
    if (low < high) {
        int pi = partition(arr, low, high, pass);

        quickSort(arr, low, pi - 1, pass);
        quickSort(arr, pi + 1, high, pass);
    }
}

int main() {
    string input;

    cout << "Enter the string you want to sort: ";
    cin >> input;

    int n = input.length();
    char arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = input[i];
    }

    cout << "Initial array: ";
    printArray(arr, n);

    int pass = 0;

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1, pass);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted array without repetition: ";
    printArray1(arr, n);

    cout << "Time taken for Quick Sort: " << duration.count() << " microseconds" << endl;

    return 0;
}

*/
