#include <iostream>
#include "copy_if.h"
#include <vector>

using namespace std;

class Larger_than {
private:
    int v;
public:
    Larger_than(int vv) : v(vv) { };
    bool operator() (int x) const { return x > v; }
};

void f (vector<int>& v, vector<int>& v2)
{
    copy_if(v.begin(), v.end(), v2.begin(), Larger_than(6));
}

int main(int argc, char* argv[])
{
    vector<int> v {1,2,3,4,5,6,7,8,9,10};
    vector<int> v2 (v.size());
    f (v, v2); 
    for (auto& x : v2) { cout << x << " "; }
    cout << "\n";
}
