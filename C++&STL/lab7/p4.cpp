#include <iostream>
#include <complex>
#include <cmath>
using namespace std;


complex<double> gammaEulera(complex<double> z, int iters) {
    complex<double> res = 1.0 / z;
    for (double n = 1; n <= iters; ++n) {
        res *= pow((1.0 + 1.0 / n), z) / (1.0 + (z / n));
    }
    return res;
}

complex<double> gammaReEulera(complex<double> z, int iters) {
    complex<double> res = 1.0;
    for (double n = 1; n <= iters; ++n) {
        res *= (1.0 + ( z / n)) * exp(-z / n);
    }
    return res;
}


int main() {
    complex<double> z = 2.5;
    int iters = 300; 
    complex<double> resA = gammaEulera(z, iters);
    cout << "gammaEulera" << z << " = " << resA << endl;

    complex<double> resB = gammaReEulera(z, iters);
    cout << "gammaReEulera" << z << " = " << resB << endl;

    return 0;
}
