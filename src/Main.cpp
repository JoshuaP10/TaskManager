#include "GUI.hpp"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "com.taskmanager.gui");

    TaskManagerGUI window; // Use your TaskManager GUI class
    return app->run(window);
}
