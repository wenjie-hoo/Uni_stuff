#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>
using namespace std;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int phi(int k) {
    if (k == 1)
        return 1;
    
    int result = 0;
    for (int i = 1; i < k; ++i) {
        if (gcd(i, k) == 1)
            ++result;
    }
    return result;
}

vector<int> totient(int k) {
    vector<int> result;
    for (int i = 1; i <= k; ++i) {
        result.push_back(phi(i));
    }
    return result;
}

int main() {
    int k;
    cout << "Enter a value for k: ";
    cin >> k;
    vector<int> values = totient(k);
    ofstream file("phi.txt");
    copy(values.begin(), values.end(), ostream_iterator<int>(file, ";"));
    file.close();
    return 0;
}
