//
//  Task.cpp
//  TaskManager
//
//  Created by Josh Pratl on 3/1/25.
//

#include "Task.hpp"

Task::Task(const string &desc) {
    description = desc;
    priority = TaskPriority::LOW;
    status = TaskStatus::NOT_COMPLETED;
    cout << "taskCreated" << endl;
    
}

Task::Task(const string &desc, TaskPriority p) {
    description = desc;
    priority = p;
    status = TaskStatus::NOT_COMPLETED;
    cout << "taskCreated" << endl;
}

Task::Task(const string &desc, TaskPriority p, TaskStatus s) {
    description = desc;
    priority = p;
    status = s;
    cout << "taskCreated" << endl;
}

Task::~Task() {
    cout << "taskDeleted" << endl;
}

string Task::getDescription() {
    return description;
}

string Task::getPriority() {
    return taskPriorityToString(priority);
}

string Task::getStatus() {
    return taskStatusToString(status);
}