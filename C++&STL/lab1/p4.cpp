/*
Define a strongly typed enumeration type for several selected male and female names, 
whose elements will be of type uint_16. Then define a function that takes as arguments 
a message of the type stringand the name of the recipient of a previously defined enumeration 
type (the function can print a message personally addressed to a specified person using the switch-case statement ).
*/
#include<iostream>
#include<string>
using namespace std;

enum class RecipientName : uint16_t{
    John = 1,
    Mary,
    Sarah,
    Emily
};

void GenerateMsg (string msg, RecipientName name){
    switch (name)
    {
    case RecipientName::John:
        cout << "John:" << msg <<endl;
        break;
    case RecipientName::Mary:
        cout << "Mary:" << msg <<endl;
        break;
    case RecipientName::Sarah:
        cout << "Sarah:" << msg <<endl;
        break;
    case RecipientName::Emily:
        cout << "Emily:" << msg <<endl;
        break;
    default:
        cout << "Unknown:" <<endl;
        break;
    }
}

int main (){
    GenerateMsg("Hello, how are you?", RecipientName::Sarah);
    return 0;
}
