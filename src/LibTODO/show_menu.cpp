#include <LibTODO/show_menu.h>
#include <fstream>
#include <iostream>
#include <string>

void show_menu()
{
    std::cout << "[1] Add note." << std::endl;
    std::cout << "[2] Show all notes." << std::endl;
    std::cout << "[3] Find note." << std::endl;
    std::cout << "[4] Remove one note." << std::endl;
    std::cout << "[5] Remove all notes." << std::endl;
    std::cout << "[6] Exit." << std::endl;
}
