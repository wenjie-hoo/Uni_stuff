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

            uintmax_t total_size = 0;
            for (const auto &entry : fs::recursive_directory_iterator(path))
            {
                if (entry.is_regular_file())
                {
                    total_size += entry.file_size();
                }
            }
            std::cout << "total size: " << total_size << " bytes." << std::endl;
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
