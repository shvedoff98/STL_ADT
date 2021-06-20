#ifndef _VECTOR_H
#define _VECTOR_H


#include <iostream>
#include <algorithm>
#include <exception>

#define _SIZE_ERROR_ std::length_error("Vector's size cannot be beggire than capacity.") 

template <class T> class vector
{
    private:

	size_t last_elem; // for push_back 
	size_t capacity_;
	size_t sz;
	T* arr;

    public:	
        explicit vector (size_t size);
        virtual ~vector ();

    public:

        vector& operator= (vector& other);
        T& operator[] (size_t pos) const noexcept;
        T& at (size_t pos);
        T const& at (size_t pos) const;
        T* data () const noexcept;
    
    public:

        size_t size () const noexcept { return sz; }
        size_t capacity () const noexcept { return capacity_; }
        size_t erase (size_t pos);

    public:

        void push_back (T&& elem);
        void pop_back ();
        void swap (vector&);

    public:

        void resize (size_t val);
        void reserve(size_t n);
        void shrink_to_fit() noexcept;
        void clear() noexcept;

    public:

        void print () const noexcept;

    public:

        bool empty() const noexcept;


};

#endif
