#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        fs::path path(argv[1]);
        if (fs::exists(path))
        {
            cout << "Path: " << fs::canonical(path) << "\n";
            if (fs::is_directory(path))
            {
                cout << "Directories:\n";
                for (const auto &entry : fs::directory_iterator(path))
                {
                    if (fs::is_directory(entry.path()))
                    {
                        cout << entry.path().filename() << "\n";
                    }
                }
                cout << "Files:\n";
                for (const auto &entry : fs::directory_iterator(path))
                {
                    if (fs::is_regular_file(entry.path()))
                    {
                        cout << entry.path().filename() << "\n";
                    }
                }
            }
            else
            {
                cout << argv[1] << " is not a directory!\n";
            }
        }
        else
        {
            cout << argv[1] << " does not exist!\n";
        }
    }
    else
    {
        cout << "Usage: " << argv[0] << " <directory_path>\n";
    }

    return 0;
}
