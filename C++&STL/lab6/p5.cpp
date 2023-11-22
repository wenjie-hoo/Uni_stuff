#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void perm(string str) {
    sort(str.begin(), str.end());
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

int main() {
    string test = "abcd";
    perm(test);
    return 0;
}
