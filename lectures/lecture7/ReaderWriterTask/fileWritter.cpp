#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileWriter {

private:
    ofstream mFile;

public:
    FileWriter(std::string fileName) {
        mFile.open(fileName.c_str());
    }

    template <typename T>
    void write(T data) {
        mFile << data << endl;
    }

    ~FileWriter() {
        mFile.close();
    }
};

int main() {
   FileWriter fw("test.txt");
   fw.write<int> (123);
   std::string str = "hello ";
   fw.write<std::string> (str);
   return 0;
}