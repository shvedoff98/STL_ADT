#include "stl_vector.h"
#include <vector>
#include <iostream>
using namespace std;

void f(int n)
{
    Vector v(n) ,v2(n);
    v.set(0,5.2); v2.set(1,10.4);
    cout << v.get(0) << " " << v2.get(1) << "\n";
}

void shallow_copy_(void)
{
    int* p = new int{77};
    int* q = p;
    *p = 88.4;
    cout << *q << " " << *p << "\n";
/*          _ _        ___
           | p |      | q |  
           |___|      |___|
            |_         _|
              |_     _|
                |___|
                |88 |
                |___|  */             


}       

void deep_copy_(void)
{
    int* p = new int{99};                
    int* q = new int{*p};
    *p = 88;
    cout << *q << " " << *p << "\n";

    // We should use deep copy instead of shallow one because
    // in this case 2 ptrs point to 2 different objects. It is safe.
/*          _ _        ___
           | p |      | q |  
           |___|      |___|
            |_         |_
              |_         |_
                |___       |___
                |88 |      | 99|
                |___|      |___|   */       
}

vector<double> fill(istream& is)
{
    vector<double>res;
    for (double x; is >> x; ) res.push_back(x);
    return res;
}


void use()
{
    vector<double>vec = fill(cin);
}
int main(int argc, char* argv[])
{
    f(5);    
    shallow_copy_();
    deep_copy_();
    use();
}
