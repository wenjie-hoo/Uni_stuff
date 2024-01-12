#include <iostream>
#include <string>
#include <cwchar>
using namespace std;

int main()
{
    locale polish("pl_PL.UTF-8");
	cout << polish.name()<<endl;
    setlocale (LC_ALL, "pl_PL.UTF-8");
    
    wstring str(L"Żółta łódź");
    wcout << str << endl;

    wstring strC(L"yellow boat");
    wcout << strC << endl;

    wchar_t wide_character = L'Ż';
    cout << "Ż" << wide_character << endl;

    cout << "size:" << sizeof(str) << endl;
    return 0;

}