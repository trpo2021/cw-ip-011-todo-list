#include <fstream>
#include <iostream>
#include <string>

void remove_all_notes()
{
    std::fstream file("notes.txt", std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cout << "[-] File is not opened!" << std::endl;
        exit(EXIT_FAILURE);
    }
    file.close();
}
