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

int main(int argc, char* argv[])
{
    Vector v(5);
    for (int i=0; i<v.size(); ++i)
    {
        v.set(i,1.1*i);
        cout << "v[" << i << "]==" << v.get(i) << "\n";
    }
}
