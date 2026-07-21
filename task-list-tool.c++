#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> tasks;
    int opc;

    cout << "Welcome to Task List Tool!" << endl << endl;
    cout << "Menu Options:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Remove Task" << endl;
    cout << "4. Quit" << endl << endl;
    cout << "Task list system initialized and ready!" << endl;

    do {
        cout << "Choose an option: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
        case 1: {
            string task;
            getline(cin, task);
            tasks.push_back(task);
            cout << "Task \"" << task << "\" added successfully!" << endl;
            cout << "Total tasks: " << tasks.size() << endl;
            break;
        }

        case 2:
            if (tasks.empty()) {
                cout << "No tasks available." << endl;
            } else {
                cout << "Your Tasks:" << endl;
                for (int i = 0; i < tasks.size(); i++) {
                    cout << (i + 1) << ". " << tasks[i] << endl;
                }
                cout << "Total tasks: " << tasks.size() << endl;
            }
            break;

        case 3: {
            int taskNumber;
            cin >> taskNumber;

            if (taskNumber >= 1 && taskNumber <= tasks.size()) {
                string removedTask = tasks[taskNumber - 1];
                tasks.erase(tasks.begin() + (taskNumber - 1));
                cout << "Task \"" << removedTask << "\" removed successfully!" << endl;

                if (tasks.empty()) {
                    cout << "No tasks remaining." << endl;
                } else {
                    cout << "Remaining Tasks:" << endl;
                    for (int i = 0; i < tasks.size(); i++) {
                        cout << (i + 1) << ". " << tasks[i] << endl;
                    }
                }
                cout << "Total tasks: " << tasks.size() << endl;
            } else {
                cout << "Error: Invalid task number. Please enter a number between 1 and "
                     << tasks.size() << "." << endl;
            }
            break;
        }

        case 4:
            cout << "Thank you for using Task List Tool!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (opc != 4);

    return 0;
}