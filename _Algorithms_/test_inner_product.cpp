#include <list>
#include <iostream>
#include <vector>
#include "inner_product.h"
using namespace std;

int main(int argc, char* argv[])
{
    vector <double> dow_price = { 81.86, 34.69, 54.45 };
    list<double> dow_weight =  { 5.8549, 2.4808, 3.8940 };
    
    double dji_index = inner_product(dow_price.begin(), dow_price.end(), dow_weight.begin(), 0.0);
    cout << dji_index << "\n";

}

