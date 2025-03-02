


#include "TaskManager.hpp"
#include <assert.h>

void testAddTask() {
    TaskManager t;
    t.addTask("Hello");
    cout << t.printTasks() << endl;
    assert(t.printTasks() == "Hello");
    t.addTask("goodbye");
    assert(t.printTasks() == "Hello goodbye");
    cout << "Passed addTask test" << endl;
}

void testRemoveTask() {
    TaskManager t;
    t.addTask("Hello");
    t.addTask("goodbye");
    t.removeTask(1);
    assert(t.printTasks() == "goodbye");
    t.removeTask(1);
    assert(t.printTasks() == "");
    cout << "Passed removeTask test" << endl;
}

void testTaskCount() {
    TaskManager t;
    t.addTask("1");
    t.addTask("2");
    assert(t.taskCount() == 2);
}

int main() {
    testAddTask();
    testRemoveTask();
    testTaskCount();
}
