#include <iterator>

// Iterator


template <class T>
class circular_buffer_iterator
{
    typedef circular_buffer_iterator	     self_type;
    typedef T				     value_type;
    typedef T&				     reference;
    typedef T const&			     const_reference;
    typedef T*                               pointer;
    typedef std::random_access_iterator_tag  iterator_category;
    typedef ptrdiff_t			     difference_type

public:
    circular_buffer_iterator (circular_buffer<T> const& buf,
			     size_t const pos, bool const last) :
		buffer_(buf), index_(pos), last_(last) 
		{}
    
};

