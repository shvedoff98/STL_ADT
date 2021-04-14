#include <iostream>
using namespace std;

const float PI {3.14152};
const float FencePrice {3.50};
const float ConcretePrice {0.50};

class Circle {
    private:

        float radius;

    public:

        Circle(float r);

        float Circumference(void) const;
        float Area(void) const;
};

Circle::Circle (float r) : radius {r} {};

float Circle::Circumference(void) const 
{
    return 2 * PI * radius;
}

float Circle::Area(void) const
{
    return PI * radius * radius;
}


int main(int argc, char* argv[])
{
    float FenceCost, ConcreteCost;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Enter the radius of the pool: ";
    float radius; cin >> radius;

    Circle Pool {radius};
    Circle PoolRim {radius + 3};

    FenceCost = PoolRim.Circumference() * FencePrice;
    cout << "FenceCost: "  << "$" << FenceCost << "\n";

    ConcreteCost = (PoolRim.Area() - Pool.Area()) * ConcretePrice;
    cout << "ConcretePrice: " << "$" << ConcreteCost << "\n";
}
