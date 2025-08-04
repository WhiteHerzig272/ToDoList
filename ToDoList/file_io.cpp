#include <iostream>
#include <fstream>
#include "file_io.h"
#include <vector>

void viewList() {
    std::string line;

    std::ifstream in("../tasks.txt");
    if (in.is_open()) {
        int counter = 0;
        while (std::getline(in, line)) { // Пока getline успешно читает сторку, будет работать цикл
            std::cout << ++counter << ". " << line << std::endl;
        }
        std::cout << std::endl << std::endl;
    } else {
        std::cout << "Error! \"tasks.txt\" not found\n";
    }

    in.close();
}

void addTask(const std::string &task) {
    std::ofstream outFile("../tasks.txt", std::ios::app);
    if (!outFile.is_open()) {
        std::cout << "Error! Writing to file.\n";
        return;
    }
    outFile << task << std::endl;

    outFile.close();
}

void removeTask(int index) {
    std::string line;
    std::vector<std::string> lines;

    std::ifstream inFile("../tasks.txt");
    while (std::getline(inFile, line)) {
        lines.push_back(line);
    }
    inFile.close();

    if (index + 1 < 0 || index + 1 > lines.size()) {
        std::cout << "Error! Invalid task number.\n";
        return;
    }

    lines.erase(lines.begin() + index);

    std::ofstream outFile("../tasks.txt");
    if (!outFile.is_open()) {
        std::cout << "Error! Writing to file.\n";
        return;
    }
    for (const auto& task : lines) {
        outFile << task << "\n";
    }
    outFile.close();
}

void deleteAllTasks() {
    std::ofstream outFile("../tasks.txt", std::ios::trunc);
    if (!outFile.is_open()) {
        std::cout << "Error! Writing to file.\n";
        return;
    }
    outFile.close();
}

