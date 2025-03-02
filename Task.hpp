//
//  Task.hpp
//  TaskManager
//
//  Created by Josh Pratl on 3/1/25.
//

#ifndef Task_h
#define Task_h
#include <string>
#include <iostream>
using namespace std;

enum class TaskPriority {
    LOW,
    MEDIUM,
    HIGH,
    CRITICAL
};

class Task {
public:
    Task(const string &desc);
    Task(const string &desc, TaskPriority p);
    ~Task();
    string getDescription();
    string getPriority();
    inline std::string taskPriorityToString(TaskPriority priority) {
        switch (priority) {
            case TaskPriority::LOW: return "LOW";
            case TaskPriority::MEDIUM: return "MEDIUM";
            case TaskPriority::HIGH: return "HIGH";
            case TaskPriority::CRITICAL: return "CRITICAL";
            default: return "UNKNOWN";
        }
    }
private:
    string description;
    TaskPriority priority;
};

#endif /* Task_h */
