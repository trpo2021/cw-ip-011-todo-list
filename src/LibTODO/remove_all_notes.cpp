#include <iostream>
#include <fstream>
#include <string>
//Удаляет все заметки
void remove_all_notes() {
	std::fstream file("notes.txt", std::ios::out | std::ios::trunc);
	if (!file.is_open()) {
		std::cout << "[-] File is not opened!" << std::endl;
		exit(EXIT_FAILURE);
	}
	file.close();
}