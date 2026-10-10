#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

struct Task {
    std::string title;
    bool done = false;
};

const std::string FILE_NAME = "tasks.txt";

void saveTasks(const std::vector<Task>& tasks) {
    std::ofstream out(FILE_NAME);
    for (const auto& t : tasks) {
        out << (t.done ? 1 : 0) << ' ' << t.title << '\n';
    }
}

std::vector<Task> loadTasks() {
    std::vector<Task> tasks;
    std::ifstream in(FILE_NAME);
    int done;
    while (in >> done) {
        in.ignore();
        Task t;
        t.done = (done == 1);
        std::getline(in, t.title);
        tasks.push_back(t);
    }
    return tasks;
}

int readInt(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

void listTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks yet.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". [" << (tasks[i].done ? "x" : " ")
                  << "] " << tasks[i].title << "\n";
    }
}

int main() {
    std::vector<Task> tasks = loadTasks();
    int choice = 0;

    while (choice != 5) {
        std::cout << "\n1. Add task\n2. List tasks\n3. Complete task\n"
                  << "4. Delete task\n5. Quit\n";
        choice = readInt("> ");

        if (choice == 1) {
            Task t;
            std::cout << "Title: ";
            std::getline(std::cin, t.title);
            tasks.push_back(t);
        } else if (choice == 2) {
            listTasks(tasks);
        } else if (choice == 3 || choice == 4) {
            listTasks(tasks);
            if (tasks.empty()) continue;
            int n = readInt("Task number: ");
            if (n < 1 || n > static_cast<int>(tasks.size())) {
                std::cout << "Invalid task number.\n";
            } else if (choice == 3) {
                tasks[n - 1].done = true;
            } else {
                tasks.erase(tasks.begin() + (n - 1));
            }
        }
        saveTasks(tasks);
    }
}
