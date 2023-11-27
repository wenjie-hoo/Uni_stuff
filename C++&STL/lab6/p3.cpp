#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

auto findMaxFrequencyElements(const vector<int>& numbers) {
    unordered_map<int, int> counters;
    for (int number : numbers) {
        ++counters[number];
    }

    int maxFrequency = (*max_element(counters.begin(), counters.end(),
                                     [](const pair<int, int>& a, const pair<int, int>& b) {
                                         return a.second < b.second;
                                     })).second;

    vector<pair<int, int>> maxFrequencyElements;
    
    for (const auto& entry : counters) {
        if (entry.second == maxFrequency) {
            maxFrequencyElements.push_back(entry);
        }
    }
    return maxFrequencyElements;
}

int main() {
    vector<int> test = {1, 1, 1, 5, 8, 9, 5, 8, 8, 5};
    vector<pair<int, int>> res = findMaxFrequencyElements(test);

    for_each(res.begin(), res.end(), [](const auto& element) {
        cout << "(" << element.first << "," << element.second << ")" << endl;
    });

    return 0;
}


