all:
	mpic++ -O0 -Wall -shared -std=c++14 -fPIC -undefined dynamic_lookup `python2 -m pybind11 --includes` logi.cpp -o logi.so
