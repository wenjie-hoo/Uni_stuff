/*
Write std::outa raw string to the standard output containing:
1.address of our Institute (in the first line the full name of the Institute, 
2.in the second line the street with the number, in the third line the postal code and city);
absolute path to the Windows application programs directory;
3.arious sequences of quotation marks and round brackets (and in particular the sequence )").
*/

#include <iostream>
using namespace std;

int main() {
    cout << R"(Fryderyka Joliot-Curie 15, 50-383 Wrocław)" << endl;
    cout << R"(C:\\Program Files (x86))" << endl;
    cout << R"end(""(\))")end" << endl;
    return 0;
}

