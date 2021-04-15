// Cylinder class impementation
#include <iostream>
using namespace std;

const double PI = 3.14;

class Cylinder {

    private:
        double radius;
        double height;

    public:
        Cylinder(double r, double h) 
            : radius {r}, height {h} {}

        double Area() const;
        double Volume() const;
};


double Cylinder::Area() const
{
    return 2 * PI * radius * height;
}

double Cylinder::Volume() const
{
    return  PI * radius * radius * height;
}

int main(int argc, char* argv[])
{
    cout << "Enter the radius: ";
    double r; cin >> r;
    cout << "Enter the height: ";
    double h; cin >> h;

    Cylinder First_cyl(r, h);
    double x = First_cyl.Area();
    double y = First_cyl.Volume();
    cout << "Area: " << x << "\n";
    cout << "Volume: " << y << "\n";
}

