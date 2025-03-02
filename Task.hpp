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


class Task {
public:
    Task(const string &desc);
    ~Task();
    string getDescription();
private:
    string description;
};

#endif /* Task_h */
