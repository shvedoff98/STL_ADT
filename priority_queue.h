#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>

template <class T, 
    class Compare = std::less<typename std::vector<T>::value_type>>
class Prior_q
{
    typedef typename std::vector<T>::value_type value_type;
    typedef typename std::vector<T>::size_type size_type;
    typedef typename std::vector<T>::reference reference;
    typedef typename std::vector<T>::const_reference const_reference;

public:
    Prior_q(size_t sz)
    {
	size_t num = sz + 1;
	for (size_t i = 0; i<sz; ++i) vec.push_back(--num);
	std::random_shuffle(std::begin(vec), std::end(vec));
	std::make_heap(std::begin(vec), std::end(vec));
    }

    const_reference Top() const { return vec.front(); }
    size_type size() const noexcept { return vec.size(); }
    bool empty() const noexcept { return vec.begin() == vec.end(); }

    void push (value_type const& value)
    {
	vec.push_back(value);
	std::push_heap(std::begin(vec), std::end(vec), cmp);
    }

    void pop ()
    {
	std::pop_heap(std::begin(vec), std::end(vec));
	vec.pop_back();
    }

private:
    std::vector<T> vec;
    Compare cmp;
};

	
