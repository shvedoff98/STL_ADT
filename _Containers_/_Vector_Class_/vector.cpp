#include "vector.h"


// Own stl_vector implementation without using iterators.



#if 0
template <class T>
void vector<T>::swap (vector& vec)
{
    T* p = new T[vec.capacity_];
    std::copy (vec.arr, vec.arr+vec.sz, p);
    delete[] arr;
    arr = p;
    delete[] p;
}
#endif

template <class T>
T* vector<T>::data () const noexcept
{
    return arr;
}

template <class T>
void vector<T>::shrink_to_fit() noexcept
{
    if (sz == capacity_) return;
    else
    {
        T* p = new T[sz];
        delete[] arr;
        arr = p;
        delete[] p;
        capacity_ = sz;
    }
}


template <class T>
void vector<T>::reserve(size_t n) 
{
    try
    {
        (n < sz);
    }
    catch (std::logic_error& err)
    {
        throw _SIZE_ERROR_; std::cout << err.what() << "\n";
    }

    T* p = new T[n];
    std::copy (arr, arr+sz, p);
    delete[] arr;
    arr = p;
    delete[] p;
    capacity_ = n;
}


template <class T>
size_t vector<T>::erase (size_t pos)
{
    size_t res;
    if (pos == sz) 
    {
        pop_back();
        res = arr[sz-1];
        return res;
    } 
    else
    {
        for (size_t i = sz; i >= pos; --i)
        {
            arr[i] = arr[i-1];
            if ( i == pos ) res = i;
        }
    }
    return res;
}


template <class T>
bool vector<T>::empty() const noexcept
{
    return (sz == 0);
}

template <class T>
void vector<T>::resize(size_t val) 
{
    T* p = new T[val];
    std::copy (arr, arr+val, p);
    arr = p;
    sz = val;
    capacity_ = 2*sz;
}

template <class T>
vector<T>::~vector() 
{
     delete[] arr; 
}



template <class T>
void vector<T>::clear () noexcept
{
    sz = 0;
}

template <class T>
void vector<T>::pop_back()
{
    --sz;
}


template <class T>
T& vector<T>::at(size_t pos) 
{
    if (pos >= sz)
    {
	    throw std::out_of_range ("Out of vector's range");
    }
    
    return arr[pos];
}


template <class T>
T const& vector<T>::at(size_t pos) const
{
    if (pos >= sz)
    {
	    throw std::out_of_range ("Out of vector's range");
    }
    
    return arr[pos];
}


template <class T>
void vector<T>::print() const noexcept
{
    for (size_t i = 0; i < last_elem; ++i)
    {
	    std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}



template <class T>
void vector<T>::push_back (T&& elem) 
{
    arr[last_elem] = elem;
    if (last_elem == sz)  ++sz; 

    ++last_elem;

    if (sz == capacity_) 
    {
        T* p = new T[capacity_*2];
        std::copy(arr, arr+sz, p);
        delete[] arr;
        arr = p;                         // cannot free allocated memory p
        capacity_ = 2*capacity_;          // free(): double free detected in tcache 2 Aborted (core dumped)
       // delete[] p;
    }
}


template <class T>
vector<T>& vector<T>::operator=(vector& other)
{
    sz = other.sz;
    return *this;
}


template <class T>
T& vector<T>::operator[] (size_t pos) const noexcept
{
    return arr[pos];
}


template <class T>
vector<T>::vector (size_t size) : sz(size), capacity_(size*2)
{
    arr = new T[capacity_];
    last_elem = 0;
}




int main(int, char**)
{
    vector<int> vec(5);

    size_t len = 20;
    for (size_t i=0, j=1; i < len; ++i, ++j )
    {
        vec.push_back (i);
 #if 0   // capacity , size
        if (j == 5 || i == len-1)
        {
            j = 0;
            printf ("Capacity: %ld\n", vec.capacity());
            printf ("Size: %ld\n", vec.size());
        }
#endif
    }

    vector <int> other (10);
    other.push_back(9);
    other.push_back(15);

    vec.print();
    other.print();


#if  0 // data
    auto ptr = vec.data();
    std::cout << *ptr << "\n";
    ptr += 10;
    std::cout << *ptr << "\n";
#endif



#if 0  // shrink_to_fit
    vec.shrink_to_fit();
    std::cout << vec.capacity() << "\n";
    std::cout << vec.size() << "\n";
#endif



#if 0  // resize, erase, clear
    vec.print();
    vec.resize(5);
    vec.erase(5);
    vec.erase(4);
    vec.erase(3);
    vec.print();
    vec.clear();
    std::cout << vec.size() << "\n";
    std::cout << vec.empty() << "\n";
#endif

#if 0 // reserve
    vec.resize(10);
    printf ("Capacity: %ld\n", vec.capacity());
    printf ("Size: %ld\n", vec.size());

    vec.reserve(11);
    printf ("Capacity: %ld\n", vec.capacity());
    printf ("Size: %ld\n", vec.size());

#endif

#if 0 // checking stl_vector
    using namespace std;
    {
        std::vector<int> vec (10, 0);
    }
#endif
    
    exit(EXIT_SUCCESS);
}
