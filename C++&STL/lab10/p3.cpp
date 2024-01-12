#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
using namespace std;

int main()
{

    string inputFilePath = "text.txt";
    string utf32OutputFilePath = "output_utf32.txt";
    string iso88592OutputFilePath = "output_iso88592.txt";

    ifstream inputFile(inputFilePath, ios::binary);
    if (!inputFile.is_open())
    {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    string utf8Content((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());

    wstring_convert<codecvt_utf8<char32_t>, char32_t> utfConverter;
    u32string utf32Content = utfConverter.from_bytes(utf8Content);

    ofstream utf32OutputFile(utf32OutputFilePath, ios::binary);
    if (!utf32OutputFile.is_open())
    {
        std::cerr << "Error opening UTF-32 output file." << std::endl;
        return 1;
    }
    utf32OutputFile.write(reinterpret_cast<const char *>(&utf32Content[0]), utf32Content.size() * sizeof(char32_t));
    utf32OutputFile.close();

    wstring_convert<codecvt_utf8<char32_t>, char32_t> iso88592Converter;
    string iso88592Content = iso88592Converter.to_bytes(utf32Content);

    ofstream iso88592OutputFile(iso88592OutputFilePath, ios::binary);
    if (!iso88592OutputFile.is_open())
    {
        cerr << "Error opening ISO-8859-2 output file." << endl;
        return 1;
    }

    iso88592OutputFile.write(iso88592Content.c_str(), iso88592Content.size());
    iso88592OutputFile.close();

    inputFile.close();
    cout << "Conversion successful" << endl;
    return 0;
}
