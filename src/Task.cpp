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
    cout << "taskCreated" << endl;
    
}

Task::Task(const string &desc, TaskPriority p) {
    description = desc;
    priority = p;
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