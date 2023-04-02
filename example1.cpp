#include <chrono> // timing
#include <cstdio> // rand
#include <cstdlib> //printf

#include "helpers.hpp"

void foo(int n, int *a, int *b, int *c) 
{ 
for (int i = 0; i < n; ++i) 
a[i] = b[i] + c[i]; 
}

int main() {

 std::srand(0xC0FF33);
 
 int M = 10000;
 int N = 100;
 int a[N];
 int b[N];
 int c[N];

 fillVec(a,N);
 fillVec(b,N);
 fillVec(c,N);

 const auto start = std::chrono::steady_clock::now(); 
 for(int m = 0; m < M; ++m)
 {
    foo(N, a, b, c);
 }
 const auto end = std::chrono::steady_clock::now(); 
 const auto duration =
 std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() /
 1e3; 

 printVec(a,N);

 printf("Duration %lfms\n", duration);
 printf("Iterations per ms %lf\n", M/duration);
}
