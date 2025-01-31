#pragma once

#include <stdexcept>
#include <iterator>

int* LowerBound(int* first, int* last, int value)
{
    int* iterator;
    std::ptrdiff_t count, step;
    count = std::distance(first, last);

    while (count > 0)
    {
        iterator = first;
        step = count / 2;
        std::advance(iterator, step);
        if (*iterator < value)
        {
            first = ++iterator;
            count -= step + 1;
        }
        else
        {
            count = step;
        }
    }
    return first;
}