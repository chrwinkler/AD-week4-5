#include <iostream>

using namespace std;
// Regular printing will only print one page per sheet.
void RegularPrint(int StartPage, int EndPage)
{
    // For loop print the pages and the count number sheets.
    for (int i = 1; StartPage <= EndPage; i++)
    {
        cout << "Sheet " << i << " contains pages: " << StartPage << endl;
        StartPage++;
    }
}

// We assume that the number of pages is multiple of four.
// Booklet printing will print four pages per sheet.
void BookletPrint(int StartPage, int EndPage)
{
    // For loop to print the pages with four pages on each sheet and the number sheets.
    for (int i = 1; StartPage <= EndPage; i++)
    {
        cout << "Sheet " << i << " contains pages: "
             << StartPage << ", "
             << StartPage + 1 << ", "
             << EndPage - 1 << ", "
             << EndPage << endl;
        // So we start skip to the third StartPage and third EndPage.
        StartPage = StartPage + 2;
        EndPage = EndPage - 2;
    }
}

// Test-cases
int main()
{

    cout << "Regular printing" << endl;
    cout << "book 1" << endl;
    RegularPrint(1, 8);
    cout << endl;
    cout << "book 2" << endl;
    RegularPrint(1, 24);

    cout << endl;
    cout << endl;

    cout << "Booklet printing" << endl;
    cout << "book 1" << endl;
    BookletPrint(1, 8);
    cout << endl;
    cout << "book 2" << endl;
    BookletPrint(1, 24);

    return 0;
}
