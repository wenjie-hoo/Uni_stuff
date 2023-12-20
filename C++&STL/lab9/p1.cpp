#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iomanip>
using namespace std;


int main() {
    vector<double> values(istream_iterator<double>(cin), 
                               istream_iterator<double>{});

    cout << "values: ";
    for_each(values.begin(), values.end(), [](double n){cout << n << " ";});
    cout << endl;

    double sum = accumulate(values.begin(), values.end(), 0.0);
    double mean = sum / values.size();

    double squared_diff_sum = accumulate(values.begin(), values.end(), 0.0,
        [mean](double acc, double val) { return acc + pow(val - mean, 2.0); });

    double variance = squared_diff_sum / values.size();
    double standard_deviation = sqrt(variance);

    cout << fixed << setprecision(3);
    cout << " Mean: " << mean << endl;
    cout << "Standard Deviation: " << standard_deviation << endl;

    return 0;
}
