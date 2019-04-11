#include <cstring>
#include <fstream>

class Reader {
    public:
        Reader(std::string);
        std::string readNewLine();
    private:
        std::string const path;
        std::ifstream input;
        std::string line;
};
