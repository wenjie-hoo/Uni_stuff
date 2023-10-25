/*Check whether trigraphs work in the compiler you use (at least C++17), 
such as what ??-translates to the tilde character ˜, 
etc. What should you do to ensure that the compiler correctly interprets the trigraphs appearing in the program?*/
#include <iostream>

int main() {
    std::cout << " ??- (should be ~)" << std::endl;
    std::cout << " ??< (should be {)" << std::endl;
    std::cout << " ??> (should be })" << std::endl;
    return 0;
}
// -trigraphs