#include <iostream>
#include "simple.h"
using namespace std;
void simple(int n, int k)
{
    if (n < 0 && k > 10000 && n+1>k)
    {
        std::cout<<"Error"<< std::endl;
    }
    else{
        for (int i=n; i < k; i++)
        {
            int colvd = 0;
            for (int j = 2; j < i; j++)
            {
                if (i%j==0)
                {
                    colvd++;
                }
            }
            if (colvd==0)
            {
                std::cout << i << " " << std::endl;
            }
        }
    }
    std::cout << std::endl;
}