#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

void search_hyperlinks(const string& file, const regex& reg) {
    ifstream inputFile(file);
    string line;
    while (getline(inputFile, line)) {
        smatch m;
        while (regex_search(line, m, reg)) {
            cout << m.str(m.size() - 1) << endl;
            line = m.suffix().str();
        }
    }
    inputFile.close();
}

int main() {
    regex hyperlink(R"(<a.+?href=\"([^\"]*)\")");
    search_hyperlinks("test.html", hyperlink);

    return 0;
}
