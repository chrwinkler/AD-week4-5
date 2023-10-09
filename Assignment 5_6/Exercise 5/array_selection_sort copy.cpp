#include <iostream>

using namespace std;

// found out i was using array at should be using vector.
// also it had to be a template function.
// inside of test_sort.cpp.

template <typename AnyType>
// Selection sort function that take in array.
void SelectionSort(AnyType a[], int size)
{
    // Loop through the array.
    for (int i = 0; i < size - 1; i++)
    {
        int MinNum = i;
        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[MinNum])
            {
                MinNum = j;
            }
        }
        // Swap a[i] and arr[MinNum]
        T temp = a[i];
        a[i] = a[MinNum];
        a[MinNum] = temp;
    }
}

template <typename T>
// Printing the array.
void PrintArray(const T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Test-case function.
int main()
{
    // Test the selectionSort function.
    int a1[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int a2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int a4[] = {1};
    int a5[] = {};

    // Get the size of the arrays.
    int size_a1 = sizeof(a1) / sizeof(a1[0]);
    int size_a2 = sizeof(a2) / sizeof(a2[0]);
    int size_a3 = sizeof(a3) / sizeof(a3[0]);
    int size_a4 = sizeof(a4) / sizeof(a4[0]);
    int size_a5 = sizeof(a5) / sizeof(a5[0]);

    // Print the Arrays.
    cout << "Array 1" << endl;
    cout << "Before sorting a1: ";
    PrintArray(a1, size_a1);
    SelectionSort(a1, size_a1);
    cout << "After sorting a1: ";
    PrintArray(a1, size_a1);
    cout << endl;

    cout << "Array 2" << endl;
    cout << "Before sorting a2: ";
    PrintArray(a2, size_a2);
    SelectionSort(a2, size_a2);
    cout << "After sorting a2: ";
    PrintArray(a2, size_a2);
    cout << endl;

    cout << "Array 3" << endl;
    cout << "Before sorting a3: ";
    PrintArray(a3, size_a3);
    SelectionSort(a3, size_a3);
    cout << "After sorting a3: ";
    PrintArray(a3, size_a3);
    cout << endl;

    cout << "Array 4" << endl;
    cout << "Before sorting a4: ";
    PrintArray(a4, size_a4);
    SelectionSort(a4, size_a4);
    cout << "After sorting a4: ";
    PrintArray(a4, size_a4);
    cout << endl;

    cout << "Array 5" << endl;
    cout << "Before sorting a5: ";
    PrintArray(a5, size_a5);
    SelectionSort(a5, size_a5);
    cout << "After sorting a5: ";
    PrintArray(a5, size_a5);
    cout << endl;

    return 0;
}
