#include <iostream>
using namespace std;

class Vector {
    int sz;
    double* elem;
public:
    Vector(int s): sz{s}, elem{new double[s]}
    {
        for (int i = 0; i < s; ++i)
            elem[i] = 0;
    }

    ~Vector() { delete[] elem; }

    int size() const { return sz; }
    double get(int n) const { return elem[n]; }
    void set(int n, double v) { elem[n]=v; }

};
