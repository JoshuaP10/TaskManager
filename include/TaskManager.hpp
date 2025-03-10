//
//  TaskManager.hpp
//  TaskManager
//
//  Created by Josh Pratl on 3/1/25.
//

#ifndef TaskManager_hpp
#define TaskManager_hpp
#include "Task.hpp"
#include <stdio.h>
#include <memory>
#include <vector>
using namespace std;


class TaskManager {
public:
    TaskManager();
    ~TaskManager();

    void addTask(string t, TaskPriority p = TaskPriority::LOW, TaskStatus l = TaskStatus::NOT_COMPLETED);
    void listTasks();
    void removeTask(int index);
    string printTasks() const;
    int taskCount() const;
    string getTaskPriority(int index);
    string getStatus(int index);
    

private:
    std::vector<unique_ptr<Task>> tasks;

};


#endif /* TaskManager_hpp */
