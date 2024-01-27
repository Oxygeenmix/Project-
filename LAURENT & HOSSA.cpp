#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    std::string date;
};

class TaskReminder {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description, const std::string& date) {
        tasks.push_back({description, date});
        std::cout << "Task added successfully!\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
        } else {
            std::cout << "Tasks:\n";
            for (const auto& task : tasks) {
                std::cout << "Description: " << task.description << "\tDate: " << task.date << "\n";
            }
        }
    }
};

int main() {
    TaskReminder taskReminder;
    int choice;

    do {
        std::cout << "\nTask Reminder Program\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description, date;
                std::cout << "Enter task description: ";
                std::cin.ignore();  // Clear buffer
                std::getline(std::cin, description);
                std::cout << "Enter task date: ";
                std::cin >> date;
                taskReminder.addTask(description, date);
                break;
            }
            case 2:
                taskReminder.viewTasks();
                break;
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
