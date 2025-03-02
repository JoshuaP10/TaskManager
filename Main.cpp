//
//  Main.cpp
//  TaskManager
//
//  Created by Josh Pratl on 3/1/25.
//

#include "Task.hpp"
#include "TaskManager.hpp"

int main() {
    TaskManager t;

    bool terminate = false;

    while (!terminate) {

        cout << "Options: \n" 
                "0: Print Tasks\n"
                "1: Add Task\n"
                "2: Remove Task\n"
                "3: Quit\n" 
             << endl;

        int options;

        cout << "Enter a number: ";
        cin >> options;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }



        switch (options) {
            case 0:
                t.listTasks();
                break;
            case 1:
                {
                    string task;
                    cin.ignore();
                    getline(cin, task);
                    t.addTask(task);
                    break;
                }
            case 2:
                {
                    cout << "Choose a task to remove: " << endl;
                    t.listTasks();
                    int num;
                    cin >> num;
                    if (cin.fail() || num > t.taskCount() || num < 0) {
                        cout << "Invalid input! Please enter a valid number." << endl;

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    t.removeTask(num);
                    break;
                }
            case 3:
                return 1;
            
            default:
                cout << "Invalid option! Please enter a valid number." << endl;
                break;

        }
    }
}
