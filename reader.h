#include <cstring>
#include <fstream>

class Reader {
    public:
        Reader(std::string, int);
        std::string readNewLine();
    private:
        std::string const path;
        int bufferSize;
        std::ifstream input;
        std::string line;
};
