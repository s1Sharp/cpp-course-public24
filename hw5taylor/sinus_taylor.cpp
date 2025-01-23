#include "sinus_taylor.hpp"
#include <iostream>
#include <cmath>

namespace sinus_taylor {
    float sin(float x) {
        float result = 0.0f; 
        float term = x;
        int count = 1;

        while (std::abs(term) > 1e-6f) {
            result += term;
            term *= -x * x / ((2 * count) * (2 * count + 1));
            count++;
        }
        return result;
    }
    double sin(double x) {
        double result = 0.0;
        double term = x;
        int count = 1;

        while (std::abs(term) > 1e-6) {
            result += term;
            term *= -x * x / ((2 * count) * (2 * count + 1));
            count++;
        }
        return result;
    }
    long double sin(long double x) {
        long double result = 0.0;
        long double term = x;
        int count = 1;

        while (std::abs(term) > 1e-6) {
            result += term;
            term *= -x * x / ((2 * count) * (2 * count + 1));
            count++;
        }
        return result;
    }
    void print_sin(float x) {
        std::cout << "sin = " << sin(x) << " with type float" << std::endl;
    }
    void print_sin(double x) {
        std::cout << "sin = " << sin(x) << " with type double" << std::endl;
    }
    void print_sin(long double x) {
        std::cout << "sin = " << sin(x) << " with type long double" << std::endl;
    }
}