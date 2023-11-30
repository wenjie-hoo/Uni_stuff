#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

int genWordLength(binomial_distribution<int>& binomialDist, mt19937& gen) 
{
    return binomialDist(gen);
}

char genLetter(uniform_int_distribution<int>& letterDist, mt19937& gen) 
{
    return static_cast<char>('a' + letterDist(gen));
}

int main()
{
    int textLength = 100;
    ofstream outputFile("random_text.txt");

    binomial_distribution<int> binomialDist(10, 0.5);
    uniform_int_distribution<int> letterDist(0, 25);
    random_device rd;
    mt19937 gen(rd());

    while (textLength > 0) {
        int wordLength = genWordLength(binomialDist, gen);
        for (int i = 0; i <= wordLength; ++i) {
            char randomLetter = genLetter(letterDist, gen);
            outputFile << randomLetter;
            --textLength;
        }
        if (textLength > 0) {
            outputFile << ' ';
            --textLength;
        }
    }

    outputFile.close();
    cout << "Random text generated and saved." << endl;
    return 0;
}


