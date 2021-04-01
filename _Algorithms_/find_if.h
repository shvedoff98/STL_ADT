template <typename Iter, typename Pred>

Iter find_if(Iter first, Iter last, Pred pred)
{
    while (first != last && !(*first)) ++first;
    return first;
}
