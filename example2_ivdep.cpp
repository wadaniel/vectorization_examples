#include <chrono> // timing
#include <cstdio> // rand
#include <cstdlib> //printf
#include <string>  //stoi

#include "helpers.hpp"

void bar(int *a, const int k, const int c, const int m)
{
#pragma GCC ivdep
 for (int i = 0; i < m; i++)
 a[i+k] = a[i] * c;
}

int main(int argc, char **argv) {

 const int shift = argc > 1 ? std::stoi(argv[1]) : 0;
 std::srand(0xC0FF33);
 
 const int M = 100000;
 const int N = 1000;
 int a[N];

 fillVec(a,N);

 const auto start = std::chrono::steady_clock::now(); 
 for(int m = 0; m < M; ++m)
 {
    bar(a, N/2, 2, N/2);
    //bar(a, shift, 2, N/2);
 }
 const auto end = std::chrono::steady_clock::now(); 
 const auto duration =
 std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() /
 1e3; 

 printVec(a,20);

 printf("Shift %d\n", shift);
 printf("Duration %lfms\n", duration);
 printf("Iterations per ms %lf\n", M/duration);
}
