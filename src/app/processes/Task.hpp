#ifndef Task_HPP
#define Task_HPP
#include <string>
#include <iostream>
#include "../fileHandling/IO.hpp"
#include <sstream>

using namespace std;


enum class Action {
    ENCRYPT,
    DECRYPT
};

struct Task
{
    string filePath;
    fstream f_stream;
    Action action;

    Task(fstream &&f_stream, Action action, string filePath) {
        this->filePath = filePath;
        this->f_stream = move(f_stream);
        this->action = action;
    }

    string toString() {
        ostringstream oss;
        oss<<filePath<<","<<(action==Action::ENCRYPT ? "ENCRYPT" : "DECRYPT");
        return oss.str();
    }

    static Task fromString(const string &taskData) {
        istringstream iss(taskData);
        string filePath;
        string actionStr;

        if(getline(iss, filePath, ',') && getline(iss, actionStr)) {
            Action action = (actionStr=="ENCRYPT"?Action::ENCRYPT : Action::DECRYPT);
            IO io(filePath);
            fstream f_stream = move(io.getFileStream());

            if(f_stream.is_open()) {
                return Task(move(f_stream), action, filePath);
            } else {
                throw runtime_error("failed to open the file "+ filePath);
            }
        } else {
            throw runtime_error("Invalid task data format ");
        }
    }
};


#endif