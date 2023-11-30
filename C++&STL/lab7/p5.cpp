#include <iostream>
#include <fstream>
#include <complex>
using namespace std;

complex<double> zetaFunction(complex<double> z, int iter) {
    complex<double> res = 0.0;
    for (int n = 1; n <= iter; ++n) {
        res += pow(1/n, z);
    }
    return res;
}

complex<double> gammaEulera(complex<double> z, int iters) {
    complex<double> res = 1.0 / z;
    for (double n = 1; n <= iters; ++n) {
        res *= pow((1.0 + 1.0 / n), z) / (1.0 + (z / n));
    }
    return res;
}


int main() {
    int iterations = 100;  
    double criticalLine = 0.5;

    ofstream outputFile("p5.csv");
    outputFile << "File generated and saved " << endl;

    outputFile.close();


    return 0;
}
