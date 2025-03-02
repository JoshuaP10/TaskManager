


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

void testGetPriority() {
    TaskManager t;
    t.addTask("1", TaskPriority::HIGH);
    t.addTask("2");
    cout << t.getTaskPriority(1) << endl;
    cout << t.getTaskPriority(2) << endl;
    assert(t.getTaskPriority(1) == "HIGH");
    assert(t.getTaskPriority(2) == "LOW");
}

int main() {
    testAddTask();
    testRemoveTask();
    testTaskCount();
    testGetPriority();
}
