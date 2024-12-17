#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileReader {

private:
    ifstream mFile;

public:
    FileReader(std::string fileName) {
        mFile.open(fileName.c_str());
    }

    template <typename T>
    void read(T& data) {
        mFile >> data;
    }

    ~FileReader() {
        mFile.close();
    }
};

int main() {
   FileReader fw("test.txt");
   int a;
   fw.read<int> (a);
   std::string s;
   fw.read<std::string> (s);
   std::cout << s << ' ' << a << std::endl;
   return 0;
}