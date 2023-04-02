#include <cstdio> // rand

void printVec(int* vec, int n)
{ 
for (int i = 0; i < n; ++i) 
    printf("%d\n", vec[i]);
}

void fillVec(int* vec, int n)
{ 
for (int i = 0; i < n; ++i) 
    vec[i]=std::rand();
}

void fillVecFloats(float* vec, int n)
{ 
for (int i = 0; i < n; ++i) 
    vec[i]=std::rand()/127.;
}


