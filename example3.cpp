#include <chrono> // timing
#include <cstdio> // rand
#include <cstdlib> //printf

#include "helpers.hpp"

float foo(int n, float *a, float *b) 
{ 
float diffsum = 0.;
for (int i = 0; i < n; ++i) 
diffsum += (a[i] - b[i]); 
return diffsum;
}

int main() {

 std::srand(0xC0FF33);
 
 int M = 10000;
 int N = 128;
 float a[N];
 float b[N];

 fillVecFloats(a,N);
 fillVecFloats(b,N);

 const auto start = std::chrono::steady_clock::now(); 
 float totDiff = 0.;
 for(int m = 0; m < M; ++m)
 {
    totDiff += foo(N, a, b);
 }
 const auto end = std::chrono::steady_clock::now(); 
 const auto duration =
 std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() /
 1e3; 

 printf("Totdiff %f\n", totDiff);
 printf("Duration %lfms\n", duration);
 printf("Iterations per ms %lf\n", M/duration);
}
