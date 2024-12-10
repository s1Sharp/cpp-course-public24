#include <cmath>
#include <iostream>
#include "sinus_taylor.hpp"

int main() {
    sinus_taylor::print_sin(std::sin((double)1));
    sinus_taylor::print_sin(sinus_taylor::sin((float)1));
    sinus_taylor::print_sin(sinus_taylor::sin((double)1));
    sinus_taylor::print_sin(sinus_taylor::sin((long double)1));
    
    return 0;
}