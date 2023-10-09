#include <iostream>
#include <vector>

// Testing if it could work in it self.
// Now i have to implent it in test_sort.cpp.

using namespace std;

template <typename AnyType>
// Selection sort function that take in vector.
void SelectionSort(vector<AnyType> &a)
{
    int n = a.size();
    // Loop through the vector.
    for (int i = 0; i < n - 1; i++)
    {
        int MinNum = i;
        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++)
        {
            // If the element is smaller than the minimum element.
            if (a[j] < a[MinNum])
            {
                MinNum = j;
            }
        }
        // Swapping found minimum element with the first element
        swap(a[i], a[MinNum]);
    }
}

// Printing the vector.
void PrintVector(const vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Random vector
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(1);
    v1.push_back(5);
    v1.push_back(9);
    v1.push_back(2);
    v1.push_back(6);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(5);
    // Normal vector
    vector<int> v2;
    for (int i = 1; i <= 10; i++)
    {
        v2.push_back(i);
    }
    // Reverse the vector
    vector<int> v3;
    for (int i = 10; i >= 1; i--)
    {
        v3.push_back(i);
    }
    // One element vector
    vector<int> v4;
    v4.push_back(1);
    // Empty vector
    vector<int> v5;

    // Test the SelectionSort function.
    cout << "Vector 1" << endl;
    cout << "Before sorting v1: ";
    PrintVector(v1);
    SelectionSort(v1);
    cout << "After sorting v1: ";
    PrintVector(v1);
    cout << endl;

    cout << "Vector 2" << endl;
    cout << "Before sorting v2: ";
    PrintVector(v2);
    SelectionSort(v2);
    cout << "After sorting v2: ";
    PrintVector(v2);
    cout << endl;

    cout << "Vector 3" << endl;
    cout << "Before sorting v3: ";
    PrintVector(v3);
    SelectionSort(v3);
    cout << "After sorting v3: ";
    PrintVector(v3);
    cout << endl;

    cout << "Vector 4" << endl;
    cout << "Before sorting v4: ";
    PrintVector(v4);
    SelectionSort(v4);
    cout << "After sorting v4: ";
    PrintVector(v4);
    cout << endl;

    cout << "Vector 5" << endl;
    cout << "Before sorting v5: ";
    PrintVector(v5);
    SelectionSort(v5);
    cout << "After sorting v5: ";
    PrintVector(v5);
    cout << endl;

    return 0;
}
