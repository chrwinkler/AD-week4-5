#include <iostream>

/*      Same as before      */
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

// finding the maximum element in A
int FindMax(int N, int A[]) {
    // Base-case
    if (N == 1) {
        return A[0];
    }
    // Recursive case
    int MaxRest = FindMax(N - 1, A);

    // Compares the maximum of the rest with the current element
    return (MaxRest > A[N - 1]) ? MaxRest : A[N - 1];
}


// Finding minimum element in A
int FindMin(int N, int A[]) {
    // Base-case
    if (N == 1) {
        return A[0];
    }
    // Recursive case
    int MinRest = FindMin(N - 1, A);

    // Compares the minimum of the rest with the current element
    return (MinRest < A[N - 1]) ? MinRest : A[N - 1];
}

int main() {
    int N = 10;
    int A[] = {1, 9, 3, 7, 5, 8, 6, 4, 2, 10};


    bool result1 = search(1, N, A); // true
    bool result2 = search(10, N, A); // true
    bool result3 = search(11, N, A); // false

    // printing result true = 1, false = 0.
    std::cout << "Result of test 1: " << (result1) << std::endl;
    std::cout << "Result of test 2: " << (result2) << std::endl;
    std::cout << "Result of test 3: " << (result3) << std::endl;

    // My Max and and Min Elements
    int maxElement = FindMax(N, A); // 10
    int minElement = FindMin(N, A); // 1

    std::cout << "Maximum element: " << maxElement << std::endl;
    std::cout << "Minimum element: " << minElement << std::endl;

    return 0;
}