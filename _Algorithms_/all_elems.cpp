#include <iostream>
#include <array>


template <class Iter, class Pred>
bool all_elems (Iter first, Iter last, Pred pred)
{
    while (first != last)
    {
	if ( !pred(*first) ) return false;
	++first;
    }
    return true;
}

int main(int argc, char* argv[])
{
    std::array<int, 10> arr {1,2,3,4,5,6,7,8,9};
    bool b_param = all_elems(arr.begin(), arr.end(), [] (int i) { 
		 return 0x01 & i; });
    std::cout << b_param << "\n";
}
