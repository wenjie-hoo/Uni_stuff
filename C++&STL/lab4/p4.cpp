/*
Define a recursive lambda to calculate the binomial coefficient (n after k) only for the natural values of n and k. 
Then test this lambda on a few non-small values placed in a collection of 
vector<pair<int,int>> pairs (place a pair with some negative number in the last position there).
*/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int binomialCoefficient(int n, int k) {
    function<int(int, int)> calBinomial = [&](int n, int k) -> int {
        if (k == 0 || k == n) {
            return 1;
        } else {
            return calBinomial(n - 1, k - 1) + calBinomial(n - 1, k);
        }
    };

    return calBinomial(n, k);
}

int main() {
    vector<pair<int, int>> pairs = {
        {5, 1},
        {27, 6}, 
        {124, 4},
        {-4, -6}, 
    };

    for (const auto& pair : pairs) {
        int n = pair.first;
        int k = pair.second;
        if (n >= 0 && k >= 0 && n >= k) {
            int result = binomialCoefficient(n, k);
            cout << "C(" << n << ", " << k << ") = " << result << endl;
        } else {
            cout << "invalid input: n = " << n << ", k = " << k << endl;
        }
    }
}
