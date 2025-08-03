#include <iostream>
#include <fstream> // Для работы с файлами (file stream)
#include <string>
#include <limits> // Для numeric_limits
#include "file_io.h"

int main() {
    setlocale(LC_ALL, "ru_Ru.UTF-8");


    while (true) {
        int action;

        std::cout << "1. Add task\n2. Remove task\n3. View all tasks\n4. Delete all tasks\n5. Exit\nWhat do you want to do: ";

        // Input validation
        if (!(std::cin >> action)) {
            std::cout << "Error! Enter a number from 1 to 5.\n";

            // Clean error's flag and input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }

        // Range Checking
        if (action < 1 || action > 5) {
            std::cout << "Error! Enter a number from 1 to 5.\n";
            continue;
        }

        std::string task;
        int number;

        switch (action) {
            case 1:
                std::cout << "Input new task: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::getline(std::cin, task);
                addTask(task);
                break;
            case 2:
                while (true) {
                    viewList();
                    std::cout << "Input task number: ";
                    if (!(std::cin >> number)) {
                        std::cout << "Error! Enter a number;.\n";

                        // Clean error's flag and input buffer
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        continue;
                    }

                    break;
                }
                removeTask(number - 1);
                break;
            case 3:
                viewList();
                break;
            case 4:
                deleteAllTasks();
                break;
            case 5:
                return 0;
        }

    }

    //return 0;
}