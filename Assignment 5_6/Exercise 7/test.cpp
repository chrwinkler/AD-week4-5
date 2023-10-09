#include "quick_sort1.h"
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int b[10];
    std::vector<int> a(20);
    for (int i = 20; i > 0; i--)
    {
        a.push_back(i);
    }
    introSort(a);
    return 0;
}