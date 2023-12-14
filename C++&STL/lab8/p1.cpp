#include <iostream>
#include <regex>

using namespace std;

int main()
{
    regex time_test("^([0-1]?[0-9]|2[0-3]):[0-5][0-9](:[0-5][0-9])?$");
    cout << regex_match("00:50", time_test) << endl;
    cout << regex_match("12:12", time_test) << endl;
    cout << regex_match("1:01:01", time_test) << endl;
    
    cout << regex_match("15:05:1", time_test) << endl;
    cout << regex_match("23:232", time_test) << endl;
    cout << regex_match("14,16", time_test) << endl;
    cout << regex_match("14.16", time_test) << endl;
    cout << regex_match("1:01:01.1", time_test) << endl;
}