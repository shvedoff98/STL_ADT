#include "find_if.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

bool odd(int x) { return x % 2 ; }


int main(int argc, char* argv[])
{
    vector<int> vec;

    for (int i=0; i<10; ++i) { vec.push_back(i); }

    auto vp = find_if(begin(vec), end(vec), odd);
    
    cout << &vp << "\tValue: " << *vp << "\n";
}
