template <class In, class Out, class Pred>

Out copy_if (In first, In last, Out res, Pred p)
{
// copies the elements, that equals to Pred p
    while (first != last)
    {
        if (p(*first)) *res++ = *first;
        ++first;
    }
    return res;
}
