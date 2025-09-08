#include "ProcessManagement.hpp"
#include <iostream>
#include <cstring>
//#include <windows.h> // Uncomment if you need Windows process/thread APIs
#include "../encryptDecrypt/Cryption.hpp"

using namespace std;

ProcessManagement::ProcessManagement(){}

bool ProcessManagement:: submitToQueue(unique_ptr<Task>task) {
    taskQueue.push(move(task));
    return true;
}

void ProcessManagement::executeTasks() {
    while (!taskQueue.empty())
    {
        unique_ptr<Task>taskToExecute = move(taskQueue.front());
        taskQueue.pop();
        cout<<"Executing task: "<<taskToExecute->toString()<<"\n";
        executeCryption(taskToExecute->toString());
    }
    
}