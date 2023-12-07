#include <iostream>
#include <complex>
#include <cmath>
using namespace std;


complex<double> gammaEulera(complex<double> z, int terms) {
    complex<double> result = 1.0 / z;
    for (double n = 1; n <= terms; ++n) {
        result *= pow((1.0 + 1.0 / n), z) / (1.0 + (z / n));
    }
    return result;
}

complex<double> gammaInEulera(complex<double> z, int terms) {
    complex<double> result = 1.0;
    for (double n = 1; n <= terms; ++n) {
        result *= (1.0 + ( z / n)) * exp(-z / n);
    }
    return result;
}

int main() {
    complex<double> z(2, 3);
    int terms = 1000; 
    complex<double> resultA = gammaEulera(z, terms);
    cout << "gammaEulera(" << z << ") = " << resultA << endl;

    complex<double> resultB = gammaInEulera(z, terms);
    cout << "gammaInEulera(" << z << ") = " << resultB << endl;

    return 0;
}
