// EXP 1: Linear Search and Binary Searching
#include <iostream>
#include <cstdlib>
#include <chrono>  // for timing measurements
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n);
int linearSearch(int arr[], int n, int x);
int binarysearch(int arr[], int beg, int end, int m);

int main() {
    int n;
    cout << "Enter how many numbers you want: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
    }

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    // Sort the array using bubble sort
    bubbleSort(arr, n);
    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    int choice;
    while (true) {
        cout << "\nChoose the search method:" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            // Performing linear search with timing
            int searchElement;
            cout << "\nEnter which number to be found (for linear search): ";
            cin >> searchElement;
			// timing measurement
            auto startLinear = high_resolution_clock::now();
            int resultLinear = linearSearch(arr, n, searchElement);
            auto stopLinear = high_resolution_clock::now();
            auto durationLinear = duration_cast<microseconds>(stopLinear - startLinear);

            if (resultLinear != -1) {
                cout << "\nElement found at index " << resultLinear << " using linear search.";
            } else {
                cout << "\nElement not found using linear search.";
            }
            cout << "\nTime taken for linear search: " << durationLinear.count() << " microseconds" << endl;
        } 
		else if (choice == 2) {
            // Perform binary search with timing
            int searchElement;
            cout << "\nEnter which number to be found (for binary search): ";
            cin >> searchElement;

            auto startBinary = high_resolution_clock::now();
            int resultBinary = binarysearch(arr, 0, n - 1, searchElement);
            auto stopBinary = high_resolution_clock::now();
            auto durationBinary = duration_cast<microseconds>(stopBinary - startBinary);

            if (resultBinary != -1) {
                cout << "Element found at index " << resultBinary << " using binary search.";
            } else {
                cout << "Element not found using binary search.";
            }
            cout << "\nTime taken for binary search: " << durationBinary.count() << " microseconds" << endl;
        } 
		else if (choice == 3) {
            break;
        } 
		else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[], int beg, int end, int m) {
    while (beg <= end) {
        int mid = (beg + end) / 2;
        if (arr[mid] == m) {
            return mid;
        } else if (arr[mid] > m) {
            return binarysearch(arr, beg, mid - 1, m);
        } else {
            return binarysearch(arr, mid + 1, end, m);
        }
    }
    return -1;
}



/*
// binary and linear search
#include <iostream>
using namespace std;

int n, i, arr[100], flag = 0, count = 0, a;

int binarysearch(int arr[], int beg, int end, int m) {
    while (beg <= end) {
        int mid = (beg + end) / 2;
        if (arr[mid] == m) {
            return mid;
        } else if (arr[mid] > m) {
            return binarysearch(arr, beg, mid - 1, m);
        } else {
            return binarysearch(arr, mid + 1, end, m);
        }
    }
    return -1;
}

int linear_search(int a) {  // linear searching the element in the array
    for (i = 0; i < n; i++) {
        if (arr[i] == a) {
            cout << a << " is present at location " << i + 1 << endl;
            count++;
        }
    }
    return count > 0 ? count : -1;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int choice, m, k, result, result1;
    // Taking input of the array
    cout << "Enter the total number of elements=" << endl;
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "Enter the element for the array=" << endl;
        cin >> arr[i];
    }

    // Printing the array
    cout << "Array=" << endl;
    for (i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

	while (true) {
		cout << "Choose the search method:" << endl;
	    cout << "1. Linear Search" << endl;
	    cout << "2. Binary Search" << endl;
	    cout << "3. Exit" << endl;
	    cin >> choice;
	
	    if (choice == 1) {
	        // Linear search
	        cout << "Enter the number to search in the array=" << endl;
	        cin >> k;
	        result1 = linear_search(k);
	        if (result1 == -1) {
	            cout << "\nSorry! Element not found" << endl;
	        } else {
	            cout << k << " is present " << count << " times in array." << endl;
	        }
	    } else if (choice == 2) {
	        // Sorting the array for binary search
	        bubbleSort(arr, n);
			cout << "Sorted Array=" << endl;
    			for (i = 0; i < n; i++) {
        			cout << arr[i] << endl;
    			}
	        // Binary search
	        cout << "Enter the number to search in the array=" << endl;
	        cin >> m;
	        result = binarysearch(arr, 0, n - 1, m);
	        if (result == -1) {
	            cout << "\nSorry! Element not found" << endl;
	        } else {
	            cout << "\nElement present at position= " << result + 1 << endl;
	        }
	    } else if (choice==3) {
	    	break;
		} else {
	        cout << "Invalid choice!" << endl;
	    }
	}
    
    return 0;
}
//
