#include "vector_implementation.h"
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
    Vector v(5);

    for (int i=0; i<v.size(); ++i)
    {
        v.set(i,1.1*i);
        cout << v.get(i) << " ";
    }
    cout << "\n";
}
