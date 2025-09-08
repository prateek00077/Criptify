#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#include "Task.hpp"
#include <queue>
#include <memory>

using namespace std;

class ProcessManagement {
    private:
        queue<unique_ptr<Task>>taskQueue;
    public:
        ProcessManagement();
        bool submitToQueue(unique_ptr<Task>task);
        void executeTasks();
};

#endif