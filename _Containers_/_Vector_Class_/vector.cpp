#include <iostream>
#include <algorithm>
#include <exception>

template <class T> class vector
{
    private:

	size_t last_elem; // for push_back 
	size_t capacity_;
	size_t sz;
	T* arr;

    public:
	
	explicit vector (size_t size);
	vector& operator= (vector& other);
	T& operator[] (size_t pos);
	T& at (size_t pos);
	T const& at (size_t pos) const;
	size_t size () const noexcept { return sz; }
	size_t capacity () const noexcept { return capacity_; }
	void push_back (T&& elem);
	void print ();

};


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
void vector<T>::print()
{
    for (size_t i = 0; i < sz; ++i)
    {
	std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}



template <class T>
void vector<T>::push_back (T&& elem) 
{
    arr[last_elem] = elem;
    if (last_elem == sz) { ++sz; }

    ++last_elem;

    if (sz == capacity_) 
    {
	T* p = new T[capacity_*2];
	std::copy(arr, arr+sz, p);
	capacity_ = 2*capacity_;
	arr = p;
    }
}


template <class T>
vector<T>& vector<T>::operator=(vector& other)
{
    sz = other.sz;
    return *this;
}


template <class T>
T& vector<T>::operator[] (size_t pos)
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
	vec.push_back (i+1);
	
	if (j == 5 || i == len-1)
	{
	    j = 0;
	    printf ("Capacity: %ld\n", vec.capacity());
	    printf ("Size: %ld\n", vec.size());
	}
    }


    
    vec.print();

    exit(EXIT_SUCCESS);
}
