/*
Define a recursive function that will determine the nth Lucas number. 
This function is supposed to take a type argument uint64_tand should automatically deduce the type of the result.
*/

#include<iostream>
using namespace std;

auto  Lucas(uint32_t i){
    if(i==0)
        return 0;
    if(i==1)
        return 1;
    return Lucas(i - 1) + Lucas(i - 2);
}

int main(){
    cout<<Lucas(10);
}