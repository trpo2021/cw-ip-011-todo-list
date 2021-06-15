#include <fstream>
#include <iostream>
#include <string>

void add_note(const std::string& new_note)
{
    std::cout << new_note;

    std::ofstream file("notes.txt", std::ios::app);
    if (!file.is_open()) {
        std::cout << "[-] File is not opened!";
        exit(EXIT_FAILURE);
    }

    file << new_note << std::endl;

    file.close();

    std::cout << "\nNote added!" << std::endl;
}
