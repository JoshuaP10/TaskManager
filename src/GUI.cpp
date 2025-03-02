#include "GUI.hpp"
#include <iostream>

TaskManagerGUI::TaskManagerGUI() {
    set_title("Task Manager");
    set_default_size(400, 300);

    // Fix for GTKmm 3: Use Gtk::PolicyType::AUTOMATIC
    scrollWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    scrollWindow.add(taskList); // GTKmm 3 uses `add()`

    // Configure Priority Dropdown
    priorityCombo.append("LOW");
    priorityCombo.append("MEDIUM");
    priorityCombo.append("HIGH");
    priorityCombo.append("CRITICAL");
    priorityCombo.set_active(0); // Default priority

    // Button Signals
    addButton.signal_clicked().connect(sigc::mem_fun(*this, &TaskManagerGUI::on_add_task));
    removeButton.signal_clicked().connect(sigc::mem_fun(*this, &TaskManagerGUI::on_remove_task));

    // Layout for GTKmm 3
    vbox.pack_start(scrollWindow);
    vbox.pack_start(taskEntry);
    vbox.pack_start(priorityCombo);
    vbox.pack_start(addButton);
    vbox.pack_start(removeButton);
    add(vbox); // GTKmm 3 uses `add()`

    update_task_list();
    show_all_children();
}

// Updates the task list display
void TaskManagerGUI::update_task_list() {
    // Fix for GTKmm 3: Remove all children manually
    std::vector<Gtk::Widget*> children = taskList.get_children();
    for (Gtk::Widget* child : children) {
        taskList.remove(*child);
    }

    for (int i = 0; i < taskManager.taskCount(); i++) {
        std::string taskStr = taskManager.getTaskPriority(i) + ": " + taskManager.getTaskDescription(i);
        Gtk::Label *taskLabel = Gtk::manage(new Gtk::Label(taskStr));
        taskList.append(*taskLabel);
    }
}

// ✅ Implement on_add_task()
void TaskManagerGUI::on_add_task() {
    std::string taskDesc = taskEntry.get_text();
    std::string priorityStr = priorityCombo.get_active_text();

    if (taskDesc.empty()) {
        std::cout << "❌ Task description cannot be empty.\n";
        return;
    }

    TaskPriority priority;
    if (priorityStr == "LOW") priority = TaskPriority::LOW;
    else if (priorityStr == "MEDIUM") priority = TaskPriority::MEDIUM;
    else if (priorityStr == "HIGH") priority = TaskPriority::HIGH;
    else priority = TaskPriority::CRITICAL;

    taskManager.addTask(taskDesc, priority);
    taskEntry.set_text(""); // Clear input field
    update_task_list();
}

// ✅ Implement on_remove_task()
void TaskManagerGUI::on_remove_task() {
    if (taskManager.taskCount() == 0) {
        std::cout << "❌ No tasks to remove.\n";
        return;
    }
    taskManager.removeTask(taskManager.taskCount()); // Remove last task
    update_task_list();
}
