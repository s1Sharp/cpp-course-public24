#include "template_vector.hpp"

#include <chrono>
#include <iostream>

#include <deque>
#include <list>
#include <vector>


template <class T>
int benchmark(T& c)
{
    const int N = 1000000;

    int res = 0;

    for (int j = 0; j < 20; ++j)
    {
        for (int i = 0; i < N / 2; ++i){
            c.push_back(i + j);
        }

        for (int i : c){
            res += i;
        }

        c.resize(N / 4);

        for (int i : c){
            res += i;
        }

        c.resize(N);

        for (int i : c){
            res += i;
        }

        for (int i = 0; i < N / 2; ++i){
            c.pop_back();
        }

        for (int i : c){
            res += i;
        }

        for (int i = 0; i < N / 2; ++i){
            c.push_back(i + j);
        }

        for (int i : c){
            res += i;
        }

        c.clear();
    }

    return res;
}


class Timer
{
public:
    Timer() : start_(std::chrono::high_resolution_clock::now()) {}

    ~Timer(){
        const auto finish = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start_).count() << " ms" << std::endl;
    }

private:
    const std::chrono::high_resolution_clock::time_point start_;
};


int main()
{
    int res = 0;

    {
        std::vector<int> v;
        res += benchmark(v);
    }

    {
        std::cout << "Vector<int>: ";
        Timer t;
        Vector<int> v;
        res += benchmark(v);
    }

    {
        std::cout << "std::vector<int>: ";
        Timer t;
        std::vector<int> v;
        res += benchmark(v);
    }

    {
        std::cout << "std::deque<int>: ";
        Timer t;
        std::deque<int> v;
        res += benchmark(v);
    }

    {
        std::cout << "std::list<int>: ";
        Timer t;
        std::list<int> v;
        res += benchmark(v);
    }
	
	std::cout << "Completed\n";
    return res;
}
