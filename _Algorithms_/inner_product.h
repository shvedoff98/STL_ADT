template <typename In, typename In2,  typename T>

T inner_product(In first, In last, In2 first2, T init)
{
    while (first != last)
    {
        init = init + (*first * *first2);
        ++first;
        ++first2;
    }
    return init;
}


