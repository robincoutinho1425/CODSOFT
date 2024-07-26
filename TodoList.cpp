#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void displayMenu();
void addTask(vector<string>& tasks);
void viewTasks(const vector<string>& tasks);
void removeTask(vector<string>& tasks);
void clearTasks(vector<string>& tasks);

int main() {
    vector<string> tasks;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                removeTask(tasks);
                break;
            case 4:
                clearTasks(tasks);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void displayMenu() {
    cout << "\nTo-Do List Menu:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Remove Task" << endl;
    cout << "4. Clear All Tasks" << endl;
    cout << "5. Exit" << endl;
}

void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter the task: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added!" << endl;
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

void removeTask(vector<string>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) {
        return;
    }

    int taskNumber;
    cout << "Enter the number of the task to remove: ";
    cin >> taskNumber;
    cin.ignore(); // Ignore leftover newline character

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task removed!" << endl;
}

void clearTasks(vector<string>& tasks) {
    tasks.clear();
    cout << "All tasks cleared!" << endl;
}
