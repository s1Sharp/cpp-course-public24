#include <iostream>
#pragma once
#include <stdexcept>

int* LowerLimit(int* first, int* last, int value) {
 while (first < last){
  int* midValue = first + (last - first) / 2;

  if (*midValue < value){
   first = midValue + 1;
  } else {
   last = midValue;
  }
 }
 return first;
}