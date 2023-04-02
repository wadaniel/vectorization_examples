#include <chrono> // timing
#include <cstdlib> //printf
#include <immintrin.h> //__m256, _mm256_load_ps, _mm256_add_ps, _mm256_sub_ps

#include "helpers.hpp"

const size_t SIMD_WIDTH = 256;
const size_t SIMD_WIDTH_BYTES = SIMD_WIDTH / 8;
const size_t SIMD_WIDTH_FLOATS = SIMD_WIDTH_BYTES / sizeof(float);

float foo(int n, float *a, float *b) 
{ 
__m256 diffsum = {0., 0., 0., 0., 0., 0., 0., 0.};
for (int i = 0; i < n; i+=SIMD_WIDTH_FLOATS) 
{
               __m256 va = _mm256_load_ps(a+i);
               __m256 vb = _mm256_load_ps(b+i);
               diffsum = _mm256_add_ps(diffsum, va);
               diffsum = _mm256_sub_ps(diffsum, vb);
}
return diffsum[0] + diffsum[1] + diffsum[2] + diffsum[3] + diffsum[4] +
diffsum[5] + diffsum[6] + diffsum[7];
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

 printf("SIMD WIDTH FLOAT %zu\n", SIMD_WIDTH_FLOATS);
 printf("Totdiff %f\n", totDiff);
 printf("Duration %lfms\n", duration);
 printf("Iterations per ms %lf\n", M/duration);
}
