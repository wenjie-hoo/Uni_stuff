#include <iostream>
#include <regex>
#include<string>
using namespace std;

int main(){
    
    string date_0=("((0[1-9]|2[0-8]|1\\d)-(02)-([1-9]\\d{3}))");
    string date_1=("((0[1-9]|30|[12]\\d)-(0[469]||11)-([1-9]\\d{3}))");
    string date_2("((0[1-9]|3[01]|[12]\\d)-(0[13578]|1[02])-([1-9]\\d{3}))");

    regex date_test("^" + date_0 + "|" + date_1 + "|" + date_2  + "$");
    
    cout << regex_match("12-12-2023", date_test) << endl;//
    cout << regex_match("12-12-223", date_test) << endl;
    cout << regex_match("29-02-2023", date_test) << endl;
    cout << regex_match("3-6-2023", date_test) << endl;
    cout << regex_match("31-06-0023", date_test) << endl;
    cout << regex_match("31-07-2023", date_test) << endl; //
    cout << regex_match("-1-05-200", date_test) << endl;
    cout << regex_match("12/12/2003", date_test) << endl;
}