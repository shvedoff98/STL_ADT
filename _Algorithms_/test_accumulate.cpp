#include <iostream>
#include "accumulate.h"
using std::cout;
using std::cin;

 
// DRIVE CODE


int test_accum(int* x, int* y, int init)
{
    return accumulate(x, y, init);
}

int fill(int* first, int* last)
{
    while (first != last)
    {
        int x; cin >> x;
        *first = x;
        ++first;
    }
    return *first;
}


int main(int argc, char* argv[])
{
    for (;;)
    {
        int SIZE; int len_arr;
        cout << "Enter the size of array: "; cin >> SIZE;
        int* arr = new int[SIZE];

        fill (arr, &arr[SIZE]);
        cout << "The array is: ";
        for (int i=0; i<SIZE; ++i){ cout << arr[i] << " "; }
        cout << "\n";

        cout << "Sum of all elements in the array is: ";
        cout << test_accum(arr, &arr[SIZE], 0) << "\n";

        delete [] arr;
        return 0;
    }
}
