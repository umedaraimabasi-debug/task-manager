#include <iostream>
#include <string>
#include <vector>

struct Task {
    std::string title;
    bool done = false;
};

int main() {
    std::vector<Task> tasks;
    int choice = 0;

    while (choice != 3) {
        std::cout << "\n1. Add task\n2. List tasks\n3. Quit\n> ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            Task t;
            std::cout << "Title: ";
            std::getline(std::cin, t.title);
            tasks.push_back(t);
        } else if (choice == 2) {
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". ["
                          << (tasks[i].done ? "x" : " ") << "] "
                          << tasks[i].title << "\n";
            }
        }
    }
}
