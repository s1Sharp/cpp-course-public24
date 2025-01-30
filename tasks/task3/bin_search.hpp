#pragma once

int* LowerBound(int* first, int* last, int value) {
	int* left = first;
    int* right = last;
    while (left < right) {
        int* mid = left + (right - left) / 2;
        if (*mid < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
