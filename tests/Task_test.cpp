//
//  Task_test.cpp
//  TaskManager
//
//  Created by Josh Pratl on 3/1/25.
//

#include <stdio.h>
#include <assert.h>
#include "Task.hpp"

void Test_show() {
    Task t("I need to do homework");
    assert(t.getDescription() == "I need to do homework");
    cout << "show test passed" << endl;
}

void Test_getPriority() {
    Task t("I need to do homework", TaskPriority::HIGH);
    assert(t.getPriority() == "HIGH");
    Task t1("I need more homework");
    assert(t1.getPriority() == "LOW");
}

void Test_getStatus() {
    Task t("I need to do my homework", TaskPriority::LOW, TaskStatus::COMPLETED);
    assert(t.getStatus() == "Completed");
    Task t1("I need more homework", TaskPriority::LOW);
    assert(t1.getStatus() == "Not Completed");
}

int main() {
    Test_show();
    Test_getPriority();
    Test_getStatus();
}
