// Vector class implementation

#include <algorithm>
#include <initializer_list>

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

    Vector& operator=(const Vector&);

    double& operator[] (int n) { return elem[n]; } // return the reference

    double& operator[] (int n); // for non-cocnstant vector
    
    double operator[] (int n) const; // For the constant vector

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

Vector& Vector::operator=(const Vector& a)
// Make this vector the copy of a
{
    double* p = new double[a.sz]; // allocate the memory
    copy(a.elem, a.elem+a.sz, p); // copy elements
    delete[] elem;      // free the memory
    elem = p;           // overinitialize th ptr
    sz = a.sz;
    return *this; // returns the reference on itself
}


