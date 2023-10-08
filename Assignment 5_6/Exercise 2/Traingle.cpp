#include <iostream>

using namespace std;

// Prints '*' n times
void PrintStars(int NumStars)
{
    // Base-case
    if (NumStars <= 0)
    {
        return;
    }
    cout << "* ";

    // Recursive case
    PrintStars(NumStars - 1);
}

// Prints a triangle of '*' from m to n
// n must be greateror or equal to m else no '*' will be printed.
void triangle(int m, int n)
{
    // Base-case
    if (m <= n)
    {
        PrintStars(m);
        cout << "\n"
             << endl;

        // Recursive case
        triangle(m + 1, n);

        // Prints again to reverse the pattern
        PrintStars(m);
        cout << "\n"
             << endl;
    }
}

// Test cases
int main()
{
    cout << "Test case 1: triangle(4,6) " << endl;
    triangle(4, 6);
    cout << "Test case 2: triangle(2,8) " << endl;
    triangle(2, 8);
    cout << "Test case 3: triangle(5,5) " << endl;
    triangle(5, 5);
    cout << "Test case 4: triangle(6,4) " << endl;
    triangle(6, 4);
    cout << "No '*' becaurse m is greater then n." << endl;
    cout << "Test case 5: triangle(6,10) " << endl;
    triangle(6, 10);
    return 0;
}
