#include <iostream>

// Seach function
bool search(int x, int N, int A[]) {
    // Base-case
    if (N == 0) {
        return false;
    }

    // Checking if x matches with A[N-1]
    if (x == A[N - 1]) {
        return true;
    }

    // Recursive case
    return search(x, N - 1, A);
}

int main() {
    //  constant size for the array.
    const int N = 10; 
    // the Array with size of N.
    int A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Searching in array.
    bool result1 = search(1, N, A); // true
    bool result2 = search(5, N, A); // true
    bool result3 = search(10, N, A); // true
    bool result4 = search(11, N, A); // false
    bool result5 = search(20, N, A); // false
    bool result6 = search(30, N, A); // false

    // printing result true = 1, false = 0.
    std::cout << "Result of test 1: " << (result1) << std::endl;
    std::cout << "Result of test 2: " << (result2) << std::endl;
    std::cout << "Result of test 3: " << (result3) << std::endl;
    std::cout << "Result of test 4: " << (result4) << std::endl;
    std::cout << "Result of test 5: " << (result5) << std::endl;
    std::cout << "Result of test 6: " << (result6) << std::endl;

    std::cout << "does a[10] exist? " << (A[10]) << std::endl;

    return 0;
}
