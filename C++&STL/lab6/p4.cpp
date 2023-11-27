#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;

string getFileToString(ifstream& content) {
    return string((istreambuf_iterator<char>(content)),
                       (istreambuf_iterator<char>()));
}

int main(int argc, const char* argv[]) {
    ifstream file(argv[1]);
    string read = getFileToString(file);
    array<uint, 26> counts{0};
    for_each(read.begin(), read.end(),
                  [&](const char& let) {
                      if (let >= 'A' && let <= 'Z')
                          counts[let - 'A'] += 1;
                      else if (let >= 'a' && let <= 'z')
                          counts[let - 'a'] += 1;
                  });

    uint allLettersCounted = accumulate(counts.begin(), counts.end(), 0);

    for (int i = 'a'; i <= 'z'; i++) {
        cout << static_cast<char>(i) << ": " << counts[i - 'a'] / static_cast<double>(allLettersCounted) << ";" << endl;
    }
    return 0;
}
