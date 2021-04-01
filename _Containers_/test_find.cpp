#include "find.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

int main(int argc, char* argv[])
{
    const char sev {'a'};
    vector<int> vec;
    string str; str += 'a';
    array <int,10> arr; 

    for (int i=0; i<10; ++i)
    {
        str += to_string(i); 
        vec.push_back(i);
        arr[i] = i;
    }
    auto vp = find(begin(vec), end(vec), 7);
    auto sp = find(begin(str), end(str), sev);
    auto ap = find(begin(arr), end(arr), 7);
    
    cout << "Pointer to element with value 7 in vector: " << &vp << "\tValue: " << *vp << "\n";
    cout << "Pointer to element with value \"a\" in string: " << &sp << "\tValue: " << *sp << "\n";
    cout << "Pointer to element with value 7 in array:  " << &ap << "\tValue: "  << *ap << "\n";
}
