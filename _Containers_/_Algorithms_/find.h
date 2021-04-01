// STL simple std::find implementation

template <typename IT, typename T>

IT find(IT first, IT last, const T& val)
{
    while (first != last && *first != val) { ++first; }
    return first;
}
