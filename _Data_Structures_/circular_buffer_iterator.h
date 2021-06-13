#include <iterator>
#include <cassert>
#include <exception>

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
    typedef ptrdiff_t			     difference_type;

public:

    circular_buffer_iterator (circular_buffer<T> const& buf, size_t const pos, bool const last) :
		buffer_(buf), index_(pos), last_(last) 
		{}

    self_type& operator++()
    {
	if (last_)
	{
	    throw std::out_of_range("Iterator cannot be incremented past the end of range.");
	}
	index_ = (index + 1) % buffer_.data_.size();
	last_ = index_ == buffer_.next_pos();
	return *this;
    }

    self_type operator++ (int)
    {
	self_type tmp = *this ;
	++*this;
	return tmp;
    }

    bool operator== (self_type const& other) const
    {
	assert (compatible(other));
	return _index == other.index_ && last_ == other.last_;
    }

    bool operator!= (self_type const& other) const
    {
	return !(*this == other);
    }

    const_reference operator* () const
    {
	return buffer_.data_[index_];
    }

    const_reference operator-> () const
    {
	return buffer_.data_[index_];
    }


private:

    bool compatible (self_type const& other) const
    {
	return &buffer_ == &other.buffer_;
    }

    circular_buffer<T> const & buffer_;
    size_t index_;
    bool last_;

};

