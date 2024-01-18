#include <iostream>
#include <iomanip>
#include <locale>
#include <ctime>
using namespace std;

int main() {
    int num = 12345;
    double mon = 123.45;
    float flo = 1234.56; 
    time_t currentTime = time(nullptr);

    locale usLocale("en_US.UTF-8");
    cout.imbue(usLocale);
    cout << "US" << endl;
    cout << "Int:" << num << endl;
    cout << "Float: " << flo << endl;
    cout << "Currency: " << put_money(mon, true) << endl;
    cout << "Time: " << put_time(localtime(&currentTime), "%c") << endl;

    locale frLocale("fr_FR.UTF-8");
    cout.imbue(frLocale);
    cout << "\nFrance" << endl;
    cout << "Int:" << num << endl;
    cout << "Float: " << flo << endl;
    cout << "Currency: " << put_money(mon, true) << endl;
    cout << "Time: " << put_time(localtime(&currentTime), "%c") << endl;
    
    locale jpLocale("ja_JP.UTF-8");
    cout.imbue(jpLocale);
    cout << "\nJapan" << endl;
    cout << "Int:" << num << endl;
    cout << "Float: " << flo << endl;
    cout << "Currency: " << put_money(mon, true) << endl;
    cout << "Time: " << put_time(localtime(&currentTime), "%c") << endl;

    return 0;
}
