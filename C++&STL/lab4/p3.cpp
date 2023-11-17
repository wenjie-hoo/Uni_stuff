/*
Create three data sets of different types in your program vector<double>, list<string> and set<int>. 
Fill these containers with random values (you can randomly or arbitrarily type something). 
Then perform some calculations on these sets using the functors you have defined:
- Print all values in the given range (greater than a and less than b).
- Output every kth value starting from the p-th position.
- Determine the arithmetic mean (applies to collections with numbers).
- Determine the minimum and maximum element (return a pair of values).
- Determine the sum (or concatenation for character strings) of all elements.
For each task, define a function object (with internal state) and use it in a for-each loop. When programming this task, 
do not use accumulate() or similar functions.
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Functor to print values in the range (greater than a and less than b)
template<typename T>
class PrintInRange {
private:
    T a, b;
public:
    PrintInRange(T a, T b) : a(a), b(b) {}
    void operator()(const T& elem) const {
        if (elem > a && elem < b) {
            cout << elem << " ";
        }
    }
};

template<typename T>
class OutputEveryKth {
private:
    int p, k;
    int position = 0;

public:
    OutputEveryKth(int p, int k) : p(p), k(k) {}

    void operator()(const T& elem) {
        if (position >= p && (position - p) % k == 0) {
            cout << elem << " ";
        }
        position++;
    }
};

template<typename T>
class CalculateArithmeticMean {
private:
    T sum = 0;
    int count = 0;

public:
    void operator()(const T& elem) {
        sum += elem;
        count++;
    }

    double getMean() const {
        return (count != 0) ? static_cast<double>(sum) / static_cast<int>(count) : 0.0;
    }
};

template<typename T>
class FindMinMax {
private:
    T minElem, maxElem;
    bool firstElement = true;

public:
    void operator()(const T& elem) {
        if (firstElement) {
            minElem = elem;
            maxElem = elem;
            firstElement = false;
        } else {
            minElem = min(minElem, elem);
            maxElem = max(maxElem, elem);
        }
    }

    pair<T, T> getMinMax() const {
        return make_pair(minElem, maxElem);
    }
};

template<typename T>
class CalculateSum {
private:
    T sum;

public:
    CalculateSum() : sum() {}

    void operator()(const T& elem) {
        sum += elem;
    }
    T getSum() const {
        return sum;
    }
};

int main() {
    vector<double> Tvect{1.2, 2.3, 3.4, 4.5, 5.6, 6.7};
    list<string> Tlist{"a", "b", "c", "d", "e", "f", "g", "h"};
    set<int> Tset{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    cout << "----- print in range -----" << endl;
    PrintInRange<double> printInRange(3, 5);
    for_each(Tvect.begin(), Tvect.end(), printInRange);
    
    cout << "\n----- every Kth -----" << endl;
    OutputEveryKth<string> outputEveryKth(3, 2);
    for_each(Tlist.begin(), Tlist.end(), outputEveryKth);

    cout <<  "\n----- Arithmetic Mean ------" << endl;
    CalculateArithmeticMean<int> calculateMean;
    for (const auto& num : Tset) {calculateMean(num);}
    cout  << calculateMean.getMean() << endl;


    cout <<  "----- Min Max ------" << endl;
    FindMinMax<double> findMinMax;
    auto mm = for_each(Tvect.begin(), Tvect.end(), findMinMax);
    cout << " Min:" <<mm.getMinMax().first << " Max:" << mm.getMinMax().second<< endl;

    cout << "----- Concatenated String -----" << endl;
    CalculateSum<string> calculateStringSum;
    for (const auto& str : Tlist){calculateStringSum(str);}
    cout << calculateStringSum.getSum() << endl;

    cout << "----- Concatenated String -----" << endl;
    CalculateSum<int> calculateStringSu_1;
    for (const auto& num : Tset){calculateStringSu_1(num);}
    cout << calculateStringSu_1.getSum() << endl;

    return 0;

}
