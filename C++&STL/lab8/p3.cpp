#include<iostream>
#include<regex>

using namespace std;


int main()
{
    // regex address_test("^([A-Z][a-z]* *)*(-[A-Z][a-z]*)?(( *[A-Z][a-z]*)*)?$");
    regex address_test("^(?!\\b[A-Z]+\\b)([[:upper:]][[:alpha:]]+)(([[:space:]]+|-)([[:upper:]][[:alpha:]]+))*");
    
    cout << regex_match("Wrocław", address_test) << endl;     
    cout << regex_match("WROCLAW", address_test) << endl;      
    cout << regex_match("Wroclaw Psie Pole", address_test) << endl;  //      
    cout << regex_match("Jelenia-gora", address_test) << endl; 
    cout << regex_match("jelenia-Gora", address_test) << endl; 
    cout << regex_match("Jelenia-Gora", address_test) << endl;//

    return 0;
}
