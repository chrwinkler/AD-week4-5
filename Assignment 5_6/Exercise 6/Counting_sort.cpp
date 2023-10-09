#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Counting sort function that takes in vector.
void CountingSort(vector<int> &a, int k)
{
    // Size of vector
    int n = a.size();

    // Create a counter with size k+1 and initialize it from 0
    vector<int> count(k + 1, 0);

    // Counts the occurrences of elements in the array
    for (int i = 0; i < n; ++i)
    {
        ++count[a[i]];
    }

    // Reconstructs sorted array from the count array
    int Num = 0;
    for (int i = 0; i <= k; ++i)
    {
        // If it is not zero, then add it to vector
        while (count[i] > 0)
        {
            a[Num++] = i;
            --count[i];
        }
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

// Test also used in exercise 5.
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
    CountingSort(v1, 10);
    cout << "After sorting v1: ";
    PrintVector(v1);
    cout << endl;

    cout << "Vector 2" << endl;
    cout << "Before sorting v2: ";
    PrintVector(v2);
    CountingSort(v2, 11);
    cout << "After sorting v2: ";
    PrintVector(v2);
    cout << endl;

    cout << "Vector 3" << endl;
    cout << "Before sorting v3: ";
    PrintVector(v3);
    CountingSort(v3, 10);
    cout << "After sorting v3: ";
    PrintVector(v3);
    cout << endl;

    cout << "Vector 4" << endl;
    cout << "Before sorting v4: ";
    PrintVector(v4);
    CountingSort(v4, 1);
    cout << "After sorting v4: ";
    PrintVector(v4);
    cout << endl;

    cout << "Vector 5" << endl;
    cout << "Before sorting v5: ";
    PrintVector(v5);
    CountingSort(v5, 1);
    cout << "After sorting v5: ";
    PrintVector(v5);
    cout << endl;

    return 0;
}
