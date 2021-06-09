// Simple priority queue data structure

#include <vector>
#include <iterator>
#include <functional>

template <class T, 
    class Compare = std::less<std::vector<T>::value_type>>
class priority_queue
{
    typedef typename std::vector<T>::value_type value_type;
    typedef typename std::vector<T>::size_type size_type;
    typedef typename std::vector<T>::reference reference;
    typedef typename std::vector<T>::const_reference reference;

public:
    const_reference Top() const { return vec.back(); }
    size_type size() const noexcept { return vec.size(); }
    bool empty() const noexcept { return vec.begin() == vec.end(); }

    void push (value_type const& value)
    {
	vec.push_back(value);
	std::push_heap(std::begin(vec), std::end(vec), cmp);
    }

    void pop () {}


private:
    std::vector<T> vec;
    Compare cmp;
    
}
	
