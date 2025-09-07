#ifndef IO_HPP
#define IO_HPP

#include <fstream>
#include <string>
using namespace std;

class IO {
    private:
        fstream file_stream;
    public:
        IO(const string &file_path);
        ~IO();
        fstream getFileStream();
};



#endif