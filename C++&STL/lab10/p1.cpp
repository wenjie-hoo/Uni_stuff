#include <iostream>
#include <string>
#include <cwchar>
using namespace std;

int main()
{
	wcout.imbue(std::locale("pl_PL.UTF-8"));
    // setlocale (LC_ALL, "pl_PL.UTF-8");
    
    wstring str(L"Żółta łódź");
    wcout << str << endl;

    wstring strC(L"黄色的船");
    wcout << strC << endl;

    wchar_t wide_character = L'Ż';
    cout << "Ż" << wide_character << endl;

    cout << "size:" << sizeof(str) << endl;
    return 0;

}