#include "sinus_taylor.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

#define TERMS 3

namespace sinus_taylor {
    long double factorial(int n) {
        long double result = 1.0;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    float sin(float x) {
        float result = 0.0f;
        for (int n = 0; n < TERMS; ++n) {
            int sign = (n % 2 == 0) ? 1 : -1;
            result += sign * std::pow(x, 2 * n + 1) / (factorial(2 * n + 1));
        }
        return result;
    }

    double sin(double x) {
        double result = 0.0;
        for (int n = 0; n < TERMS; ++n) {
            int sign = (n % 2 == 0) ? 1 : -1;
            result += sign * std::pow(x, 2 * n + 1) / factorial(2 * n + 1);
        }
        return result;
    }

    long double sin(long double x) {
        long double result = 0.0L;
        for (int n = 0; n < TERMS; ++n) {
            int sign = (n % 2 == 0) ? 1 : -1;
            result += sign * std::pow(x, 2 * n + 1) / factorial(2 * n + 1);
        }
        return result;
    }

    void print_sin(float x) {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "sin = " << x << " with type float\n";
    }

    void print_sin(double x) {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "sin = " << x << " with type double\n";
    }

    void print_sin(long double x) {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "sin = " << x << " with type long double\n";
    }

}