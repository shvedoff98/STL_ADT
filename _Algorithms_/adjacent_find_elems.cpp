#include <iostream>
#include <array>


template <class Iter>
Iter adjacent_find_elems(Iter first, Iter last)
{
    while (first != last)
    {
	Iter next = first; ++next;
	if (*first == *next) return first;
	++first; ++next;
    }
    return last;
}

int main(int argc, char* argv[])
{
    std::array<int, 10> arr {1,2,3,4,5,6,7,8,8,9};
    auto it = adjacent_find_elems(arr.begin(), arr.end());
    std::cout << *it << "\n";

}
