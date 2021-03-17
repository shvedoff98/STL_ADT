#include "vector_implementation.h"
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        fprintf(stderr, "Too many arguments");
        return 1;
    }
    
    Vector v(5);
    for (int i=0; i<v.size(); ++i)
    {
        v.set(i,1.1*i);
        cout << v.get(i) << " ";
    }
    cout << "\n";
    
    return 0;
}
