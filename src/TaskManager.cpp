//
//  TaskManager.cpp
//  TaskManager
//
//  Created by Josh Pratl on 3/1/25.
//

#include "TaskManager.hpp"
#include <string>
#include <memory>
#include <iostream>

using namespace std;


TaskManager::TaskManager() {
    cout << "Task Manager Created" << endl;
}

TaskManager::~TaskManager() {
    cout << "Task Manager Destroyed" << endl;
}

void TaskManager::addTask(string t, TaskPriority p, TaskStatus l) {
    Task task(t, p, l);

    unique_ptr<Task> ptr = std::make_unique<Task>(task);
    tasks.push_back(std::move(ptr));
}

void TaskManager::listTasks() const {
    int numTasks = 1;
    for (const auto &x : tasks) {
        cout << "Task " + to_string(numTasks++) + ": " 
        << x->getDescription() + " Priority: " + x->getPriority() 
        << " Status: " + x->getStatus() << endl;
    }
}

string TaskManager::printTasks() const {
    string tasksList = "";
    for (const auto &x : tasks) {
        tasksList += x->getDescription();
        tasksList += " ";
    }
    return tasksList.substr(0, tasksList.length() - 1);
}

void TaskManager::removeTask(int index) {
    index -=1;
    if (index < 0 || index > taskCount() - 1) {
        cout << "Invalid index" << endl;
        return;
    }
    tasks.erase(tasks.begin() + index);
}

int TaskManager::taskCount() const {
    return tasks.size();
}

string TaskManager::getTaskPriority(int index) const {
    return tasks[index - 1]->getPriority();
}

string TaskManager::getStatus(int index) const {
    return tasks[index - 1]->getStatus();
}

std::string TaskManager::getTaskDescription(int index) const {
    if (index >= 0 && index < taskCount()) {
        return tasks[index]->getDescription();
    }
    return "Invalid Task";
}
