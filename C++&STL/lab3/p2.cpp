#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << "Smallest positive normalized number for float & double: \n"
         << numeric_limits<float>::min() << endl
         << numeric_limits<double>::min() << endl;
    cout << "Maximum positive normalized number for float & double: \n"
         << numeric_limits<float>::max() << endl
         << numeric_limits<double>::max() << endl;
    // difference between 1.0
    cout << numeric_limits<float>::epsilon() << endl;
    cout << numeric_limits<double>::epsilon() << endl;
}
