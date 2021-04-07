// std::copy() function implementation


template <typename In, typename Out>
Out copy (In first, In last, Out res)
{
    while (first != last)
    {
        *res = *first;
        ++res;
        ++first;
    }
    return res;
}

                

