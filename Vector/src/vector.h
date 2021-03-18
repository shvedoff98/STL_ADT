// Vector class implementation

#include <algorithm>

using namespace std;

class Vector {
    int sz;
    double* elem;

public:

    Vector(const Vector&);

    Vector(int s);

    ~Vector() { delete[] elem; } // Destructor to free 
                                 // the allocated memory
    
    int size() const { return sz; } // Size of the vector 

    double get(int n) const { return elem[n]; } // To derive certain
                                                //element of the vector

    void set(int n, double v) { elem[n]=v; } // Initialize some element
                                        // of the vector with certain value

};

Vector::Vector(int s)
    : sz{s}, elem {new double [s]}
{
    for (int i=0; i<sz; ++i)
    {
        elem[i] = 0;
    }
}

Vector::Vector(const Vector& arg)
/* places the elements and initializes them by copying.*/
    : sz{arg.sz}, elem {new double [arg.sz]}
{
    copy(arg.elem, arg.elem+sz, elem); //std::copy();
}


