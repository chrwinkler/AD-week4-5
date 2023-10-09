#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    int n;
    cin >> n;
    vector<int> values(n); // Creates a vector

    auto f = []() -> int
    { return rand() % 1000; }; // Returns a random value

    generate(values.begin(), values.end(), f); // Fills vector with random values

    auto start = high_resolution_clock::now(); // Starts recording time

    sort(values.begin(), values.end()); // Sorting function is called

    auto stop = high_resolution_clock::now(); // Ends recording time

    // Calculates the duration
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}