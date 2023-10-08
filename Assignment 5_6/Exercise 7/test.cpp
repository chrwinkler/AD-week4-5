#include "quick_sort.h"
#include <stdlib.h>
#include <vector>

int main()
{
    std::vector<int> a(20);
    for (int i = 20; i > 0; i--)
    {
        a.push_back(i);
    }
    introSort(a);

    return 0;
}