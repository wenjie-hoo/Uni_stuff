#include<iostream>
#include<regex>

using namespace std;

int main() {
    regex complex_test(R"(^\((\+|\-)?\d+(\.\d+)? *(\+|\-)?\d+(\.\d+)?[iI]?\)$)");

    cout << regex_match("(-12+3i)", complex_test) << endl;
    cout << regex_match("(12-3i)", complex_test) << endl;
    cout << regex_match("(7.4+0.5i)", complex_test) << endl;
    cout << regex_match("(7.4-0.5i)", complex_test) << endl;
    cout << regex_match("(2+0.01i)", complex_test) << endl;
    cout << regex_match("3+4i", complex_test) << endl;
    cout << regex_match("(3,14-2,72i)", complex_test) << endl;
    cout << regex_match("(5.7i)", complex_test) << endl;
}