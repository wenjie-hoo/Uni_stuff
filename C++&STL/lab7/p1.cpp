#include<iostream>
#include<random>
using namespace std;

random_device gen;

void switchElem(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

template<typename T, int size>
void fisherShuffle(T(&array)[size])
{  
    for(int i = size - 1; i > 0; i--)
    {
        uniform_int_distribution<int> distribution(0, i);
        int randomIndex = distribution(gen);
        switchElem(&array[randomIndex], &array[i]);
    }
}

int main()
{
    int num[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        fisherShuffle(num);
        for(int i = 0; i < 10; i++)
        {
            cout << num[i] << " ";
        }
    return 0;
}
