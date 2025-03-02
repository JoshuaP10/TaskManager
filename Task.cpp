//
//  Task.cpp
//  TaskManager
//
//  Created by Josh Pratl on 3/1/25.
//

#include "Task.hpp"

Task::Task(const string &desc) {
    description = desc;
    cout << "taskCreated" << endl;
    
}
Task::~Task() {
    cout << "taskDeleted" << endl;
}

string Task::getDescription() {
    return description;
}