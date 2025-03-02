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

enum class TaskStatus {
    NOT_COMPLETED,
    COMPLETED
};

class Task {
public:
    Task(const string &desc);
    Task(const string &desc, TaskPriority p);
    Task(const string &desc, TaskPriority p, TaskStatus s);
    ~Task();
    string getDescription();
    string getPriority();
    string getStatus();

    inline std::string taskPriorityToString(TaskPriority priority) {
        switch (priority) {
            case TaskPriority::LOW: return "LOW";
            case TaskPriority::MEDIUM: return "MEDIUM";
            case TaskPriority::HIGH: return "HIGH";
            case TaskPriority::CRITICAL: return "CRITICAL";
            default: return "UNKNOWN";
        }
    }

    inline std::string taskStatusToString(TaskStatus status) {
        switch (status) {
            case TaskStatus::NOT_COMPLETED: return "Not Completed";
            case TaskStatus::COMPLETED: return "Completed";
            default: return "UNKNOWN";
        }
    }

private:
    string description;
    TaskPriority priority;
    TaskStatus status;
};

#endif /* Task_h */
