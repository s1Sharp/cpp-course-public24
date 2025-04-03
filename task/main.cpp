#include "simple.h"
#include "iostream"
int main(int argc, char* argv[])
{
    int n = std::stoi(argv[1]);
    int k = std::stoi(argv[2]);
    simple(n,k);
}