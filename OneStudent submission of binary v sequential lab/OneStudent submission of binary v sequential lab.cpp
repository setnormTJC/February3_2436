#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <cmath>    

using namespace std;

// The array of even numbers from 0 to 50
void generateEvenNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
}

void printArray(const int arr[], int size) {
    cout << "Generated Even Numbers:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << "\n\n";
}

// Sequential search 
int sequentialSearch(const int arr[], int size, int target, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == target) {
            return i; // Return the index where the value was found
        }
    }
    return -1; // Not found
}

// Binary search 
int binarySearch(const int arr[], int size, int target, int& comparisons) {
    int left = 0, right = size - 1;
    comparisons = 0;
    while (left <= right) {
        comparisons++;
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid; // Found the target
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

int main() {
    srand(time(0)); // rng 

    const int size = 26;
    int evenNumbers[size];

    generateEvenNumbers(evenNumbers, size);

    printArray(evenNumbers, size);

    int totalSequentialComparisons = 0;
    int totalBinaryComparisons = 0;

    for (int i = 0; i < 5; i++) {
        int randomIndex = rand() % size;  // Pick a random index
        int target = evenNumbers[randomIndex]; // Pick a random even number

        int sequentialComparisons = 0;
        int binaryComparisons = 0;

        // Use sequential search
        sequentialSearch(evenNumbers, size, target, sequentialComparisons);

        // Use binary search
        binarySearch(evenNumbers, size, target, binaryComparisons);

        // Print out array


        // Print out the results 
        cout << "\nTarget number: " << target
            << "\nNumber of sequential searches needed: " << sequentialComparisons
            << "\nNumber of binary searches needed: " << binaryComparisons << endl;

        // Accumulate total comparisons
        totalSequentialComparisons += sequentialComparisons;
        totalBinaryComparisons += binaryComparisons;
    }

    // Calculate and print average of comparisons
    double avgSequential = totalSequentialComparisons / 2;
    double avgBinary = totalBinaryComparisons / 2;

    cout << "\nTotal comparisons:\n";
    cout << "Sequential Search: " << avgSequential << endl;
    cout << "Binary Search: " << avgBinary << endl;

    cout << "\nAverage comparisons:\n";
    cout << "Sequential Search: " << avgSequential << endl;
    cout << "Binary Search: " << avgBinary << endl;

    return 0;
}
