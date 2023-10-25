/*
Define a class line_writer that wraps a text file.
Objects of this class should hold pointers/references to the file stream-
that ofstream creates and opens in the constructor. 
The task of such an object is to write the file line by line. 
This class should close the stream in the destructor.
In the main program, create multiple shared_ptr pointers referencing the same file object. 
Let each program fragment have its own pointer to write its data to that file. 
The file should be closed only when all smart pointers have been processed.
*/

#include <fstream>
#include <memory>
#include <string>

class line_writer {
    std::ofstream stream;

public:
    line_writer(const std::string& name) {
        stream = std::ofstream(name + ".txt");
    }

    void write(const std::string& str) {
        stream << str << std::endl;
    }
};

int main() {
    std::shared_ptr<line_writer> ptr1 = std::make_shared<line_writer>("text");
    std::shared_ptr<line_writer> ptr2 = ptr1;
    std::shared_ptr<line_writer> ptr3 = ptr1;

    ptr1->write("a");
    ptr2->write("b");
    ptr3->write("c");
}
