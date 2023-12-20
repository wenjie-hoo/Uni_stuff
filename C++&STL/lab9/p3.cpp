#include <iostream>
#include <filesystem>
#include <chrono>
#include <ctime>
#include <sstream> 
#include <iomanip>

using namespace std;

template <typename TP>
time_t to_time_t(TP tp) {
    using namespace chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now() + system_clock::now());
    return system_clock::to_time_t(sctp);
}

int main(int argc, char const *argv[]) {
    if (argc > 1) {
        filesystem::path path(argv[1]);
        if (filesystem::exists(argv[1])) {
            cout << filesystem::canonical(path) << "\n";

            if (!filesystem::is_directory(path))
                cout << "File size: " << filesystem::file_size(path) << " bytes\n";

            auto time = filesystem::last_write_time(path);
            time_t ctime = to_time_t(time);
            tm tm = *localtime(&ctime);

            wstringstream wss;  // Use wstringstream
            wss << put_time(&tm, L"%F %T");
            wcout << "Last write time: " << wss.str() << endl;
        } else {
            cerr << "File not found: " << argv[1] << endl;
        }
    }
    return 0;
}
