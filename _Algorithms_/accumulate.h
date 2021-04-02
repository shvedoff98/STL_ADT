
template <typename In, typename T>

T accumulate(In first, In last, T init)
{
    while (first != last)
    {
        init = init + *first;
        ++first;
    }
    return init;
}
