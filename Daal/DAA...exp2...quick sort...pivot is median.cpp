//EXP2...quick sort but pivot is median of first, middle and last element
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

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);
    return mid;
}

int partition(int arr[], int low, int high, int &pass) {
    int pivotIndex = medianOfThree(arr, low, high);
    swap(arr[pivotIndex], arr[high]);
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

    cout << "Sorted array: ";
    printArray1(arr, n);

    cout << "Time taken for Quick Sort: " << duration.count() << " microseconds" << endl;

    return 0;
}

