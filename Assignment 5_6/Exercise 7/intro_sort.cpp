#include <stdlib.h>
#include <vector>
#include <math.h>
#include <iostream> //Any ideas for more includes?
#include <assert.h>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;
/*
    useInsertion checks the size of vector/partition
    So the function can determine whether
    to use insertion sort, or quick sort
*/

bool useInsertion(int begin, int end)
{
    return (end - begin <= 16);
}

// From here until line 69 is insertion sort
// Which has not been touched

template <typename Comparable>
void insertionSort(vector<Comparable> &a)
{
    for (int p = 1; p < a.size(); ++p)
    {
        Comparable tmp = std::move(a[p]);

        int j;
        for (j = p; j > 0 && tmp < a[j - 1]; --j)
        {
            a[j] = std::move(a[j - 1]);
        }
        a[j] = std::move(tmp);
    }
}

/*
 * This is the more public version of insertion sort.
 * It requires a pair of iterators and a comparison
 * function object.
 */

template <typename Iterator, typename Comparator>
void insertionSort(const Iterator &begin, const Iterator &end, Comparator less)
{
    if (begin == end)
        return;

    for (Iterator j, p = begin + 1; p != end; ++p)
    {
        auto tmp = std::move(*p);
        for (j = p; j != begin && less(tmp, *(j - 1)); --j)
            *j = std::move(*(j - 1));
        *j = std::move(tmp);
    }
}

/*
 * The two-parameter version calls the three parameter version, using C++11.
 */
template <typename Iterator>
void insertionSort(const Iterator &begin, const Iterator &end)
{
    insertionSort(begin, end, less<decltype(*begin)>{});
}

// quick_sort starts here
// Comments clarify which code we have written

/**
 * Order left, center, and right and hide the pivot.
 * Then compute partition, restore the pivot and return its position.
 */
template <typename Comparable>
int partition(vector<Comparable> &a, int left, int right)
{
    int center = (left + right) / 2;

    if (a[center] < a[left])
        std::swap(a[left], a[center]);
    if (a[right] < a[left])
        std::swap(a[left], a[right]);
    if (a[right] < a[center])
        std::swap(a[center], a[right]);

    // Place pivot at position right - 1
    std::swap(a[center], a[right - 1]);

    // Now the partitioning
    Comparable &pivot = a[right - 1];
    int i = left, j = right - 1;
    do
    {
        while (a[++i] < pivot)
            ;
        while (pivot < a[--j])
            ;
        if (i < j)
        {
            std::swap(a[i], a[j]);
        }
    } while (i < j);

    std::swap(a[i], a[right - 1]); // Restore pivot
    return i;
}

/**
 * Internal quicksort method that makes recursive calls.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quickSort(vector<Comparable> &a, int left, int right)
{

    // New code!
    if (useInsertion(left, right))
    {
        // Function checks if vector/partition is less than size 16
        // If true, pass it to insertion sort
        // Convert left, right to iterators
        vector<int>::iterator begin = a.begin() + left;
        vector<int>::iterator end = a.begin() + right;
        // cout << "partition size 16 reached" << endl; Test that this is done
        return insertionSort(begin, end);
    }
    // End of new code!

    if (right - left > 1)
    {
        int i = partition(a, left, right);
        quickSort(a, left, i - 1);  // Sort small elements
        quickSort(a, i + 1, right); // Sort large elements
    }
    else
    { // Do an insertion sort on the subarray
        if (a[left] > a[right])
        {
            std::swap(a[left], a[right]);
        }
    }
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quickSort(vector<Comparable> &a)
{
    quickSort(a, 0, a.size() - 1);
}

/*
    Returns true if depth limit is less
    or equal to 16, false otherwise
*/

// New code from here on!
template <typename Comparable>
void introSort(vector<Comparable> &a)
{
    // Driver to start sorting
    // Assert that the vector is of valid size
    assert(a.begin() != a.end());
    assert(a.size() > 0);
    // Pass it onto quick sort
    quickSort(a);
}

// Function for testing
// Prints elements of vector
template <typename T>
void print_vector(const vector<T> a)
{
    string sep = " ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << sep;
    }
    cout << endl;
}

// Test
int main()
{
    int n;
    cin >> n;
    vector<int> values(n); // Creates a vector

    auto f = []() -> int
    { return rand() % 1000; }; // Returns a random value

    generate(values.begin(), values.end(), f); // Fills vector with random values

    /*
    cout << "Vector before sort: ";
    print_vector(values);
    */
    // Test to see if vector is being sorted.

    auto start = high_resolution_clock::now(); // Starts recording time

    introSort(values); // Sorting function is called

    auto stop = high_resolution_clock::now(); // Ends recording time

    /*
    cout << "Vector after sort: ";
    print_vector(values);
    */
    // Test to see if vector is being sorted.

    // Calculates the duration
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}