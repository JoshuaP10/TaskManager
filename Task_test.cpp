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

int main() {
    Test_show();
}
