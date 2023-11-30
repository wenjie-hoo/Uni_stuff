#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<double> uniformDist(0.0, 1.0);
    binomial_distribution<int> binomialDist(10, 0.5); 
    normal_distribution<double> normalDist(5.0, 2.0);

    ofstream uniformFile("uniform.csv");
    ofstream binomialFile("binomial.csv");
    ofstream normalFile("normal.csv");

    for (int i = 0; i < 1000; ++i) {
        double uniformNumber = uniformDist(gen);
        int binomialNumber = binomialDist(gen);
        double normalNumber = normalDist(gen);

        uniformFile << uniformNumber << ",";
        binomialFile << binomialNumber << ",";
        normalFile << normalNumber << ",";
    }

    uniformFile.close();
    binomialFile.close();
    normalFile.close();
    cout << "saved to CSV files." << endl;

    return 0;
}
