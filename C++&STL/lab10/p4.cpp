#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <algorithm>

using namespace std;

int main()
{
    vector<wstring> names = {
        L"żebra",
        L"łosoś",
        L"jagoda",
        L"świnka",
        L"żółw",
        L"orzeł",
        L"słonecznik",
        L"ryba",
    };
    // jagoda orzeł ryba słonecznik łosoś świnka żebra żółw

    locale polishLocale("pl_PL.UTF-8");
    const collate<wchar_t> &coll = use_facet<collate<wchar_t>>(polishLocale);
    sort(names.begin(), names.end());

    for (const auto &name : names)
    {
        wcout << name << L"\n";
    }

    wofstream outputFile("p4.txt");
    outputFile.imbue(polishLocale);

    if (outputFile.is_open())
    {
        for (const auto &name : names)
        {
            outputFile << name << L"\n";
        }
        outputFile.close();
        cout << "generated p4.txt\n";
    }
    else
    {
        cerr << "Error";
        return 1;
    }
    return 0;
}
