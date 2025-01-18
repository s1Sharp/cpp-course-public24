#pragma once

int* LowerBound(int *first, int *last, int value) {
    while (first < last) {
        int *mid = first + (last - first) / 2;
        *mid < value ? first = mid + 1 : last = mid;
    }
    return first;
}