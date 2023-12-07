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


int main() {
    int iterations = 100;  
    double criticalLine = 0.5;

    ofstream outputFile("p5.csv");
    outputFile << "File generated and saved " << endl;
    outputFile.close();

    return 0;
}
