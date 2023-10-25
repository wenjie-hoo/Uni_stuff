// Write a program that, for given coefficients of a quadratic equation, 
// calculates the discriminant of that equation (often denoted by Δ) and, 
// depending on its value, lists the zero places. 
// Use an if-else conditional statement with a local initializer for the discriminant.
// ax^2 + bx +c = 0
// b^2 - 4ac
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (auto delta {b * b - 4 * a * c}; delta == 0) {
        cout << "root " << -b / (2 * a) << endl;
    } else if (delta > 0) {
        cout << "root1 " << (-b - sqrt(delta)) / (2 * a) << endl;
        cout << "roo2 " << (-b + sqrt(delta)) / (2 * a) << endl;
    } else {
        cout << "The equation has no real roots" << endl;
    }
    return 0;
}
