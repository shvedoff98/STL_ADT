// Vector class implementation

#include <algorithm>
#include <initializer_list>

using namespace std;

class Vector {
    int sz;
    int space;
    double* elem;

public:

    Vector(const Vector&); // Constructor by copying 

    Vector(int s); // Constructor with number of elements

    Vector(initializer_list <double> lst);

    ~Vector() { delete[] elem; } // Destructor to free 
                    // the allocated memory
    
//-------------------------------------------------------------------------

    int size() const { return sz; } // Size of the vector 

    double get(int n) const { return elem[n]; } // To derive certain
                                                //element of the vector

    int capacity() const { return space; }

    void set(int n, double v) { elem[n]=v; } // Initialize some element
                                        // of the vector with certain value

//--------------------------------------------------------------------------

    Vector& operator=(const Vector&&);  //copying with operator=

    Vector& operator=(const Vector&); //copy, but if size of the initial 
                                   // vector is less than a.sz then
                                   // do not allocate extra memory because we
                                   // do not know what will be done with
                                   // this vector

    double& operator[] (int n) { return elem[n]; } // for non-cocnstant vector

    const double& operator[] (int n) const { return elem[n]; } 
                                        // For the constant vector
//--------------------------------------------------------------------------

    void reserve(int newalloc); // changes the size of the vector
    void push_back(double d);

};


int Vector::capacity() const { return space; }


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

Vector::Vector(initializer_list <double> lst)
    //initializes vector with {}
        : sz{ lst.size() }, elem{new double[sz]}
{
        copy (lst.begin(), lst.end(), elem);
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

Vector::Vector& operator=(const Vector&& a)
    //almost like copying constructor
    //but we have to handle with old elements
{
    if (*this = &a) return *this; //self-initializing
    if (a.sz <= space) {
        for (int i=0; i<a.sz; ++i)
        {
            elem[i] = a.elem[i];
        }
        sz = a.sz;
        return *this;
    }

    double *p = new double[a.sz];
    for (int i=0; i<a.sz; ++i)
    {
        p[i] = a.elem[i];
    }
    delete[] elem;
    space = sz = a.sz;
    elem = p;

    return *this;
}

void Vector::reserve(int newalloc)
{
    if(newalloc <= space) return; // Size never decreases
    double* p = new double[newalloc];
    for (int i=0; i<sz; ++i)
    {
        p[i] = elem[i]; // copy old elements
    }
    delete[] elem;  // free old memory
    elem = p;
    space = newalloc;
}

void Vector::push_back(double d)
    // increases the size of th vector by 1
    // initializes new element with value of d
{
    if (space == 0)
    {
        reserve(8);
    } else if (sz == space) {
        reserve(2*space);
    }
    elem[sz] = d;
    ++sz;
}

