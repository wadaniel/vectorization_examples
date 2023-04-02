CXX=g++
CXXFLAGS=-Wall

all: example1 example2 example3


example1:
	${CXX} example1.cpp -o example1_base.out ${CXXFLAGS}
	${CXX} example1.cpp -o example1.out -O3 ${CXXFLAGS}
	${CXX} example1_restrict.cpp -o example1_restrict.out -O3 ${CXXFLAGS}
	${CXX} example1_ivdep.cpp -o example1_ivdep.out -O3 ${CXXFLAGS}
	${CXX} example1_omp.cpp -o example1_omp.out -O3 -fopenmp ${CXXFLAGS}

example2:
	${CXX} example2.cpp -o example2_base.out ${CXXFLAGS}
	${CXX} example2.cpp -o example2.out -O3 ${CXXFLAGS}
	${CXX} example2_ivdep.cpp -o example2_ivdep.out -O3 ${CXXFLAGS}
	
example3:
	${CXX} example3.cpp -o example3_base.out ${CXXFLAGS}
	${CXX} example3.cpp -o example3.out -O3 ${CXXFLAGS}
	${CXX} example3.cpp -o example3_unsafe.out -O3 -funsafe-math-optimizations ${CXXFLAGS}
	${CXX} example3_avx.cpp -o example3_avx.out -O3 -mavx2 -mfma ${CXXFLAGS}


.PHONY: all

clean:
	rm *.out
	rm *.s


