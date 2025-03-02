#ifndef GUI_HPP
#define GUI_HPP

#include <gtkmm.h>
#include "TaskManager.hpp"

class TaskManagerGUI : public Gtk::Window {
public:
    TaskManagerGUI();

private:
    TaskManager taskManager; // Manages tasks

    // UI Components
    Gtk::Box vbox {Gtk::ORIENTATION_VERTICAL}; // Layout
    Gtk::ScrolledWindow scrollWindow;
    Gtk::ListBox taskList; // Display list of tasks
    Gtk::Button addButton {"➕ Add Task"};
    Gtk::Button removeButton {"➖ Remove Task"};
    Gtk::Entry taskEntry;
    Gtk::ComboBoxText priorityCombo;

    // Methods
    void on_add_task();
    void on_remove_task();
    void update_task_list();
};

#endif // GUI_HPP
