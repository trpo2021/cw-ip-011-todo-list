#include <iostream>
#include <fstream>
#include <string>
//show_menu - выводит меню в консоль
void show_menu() {
	std::cout << "[1] Add note." << std::endl;
	std::cout << "[2] Show all notes." << std::endl;
	std::cout << "[3] Find note." << std::endl;
	std::cout << "[4] Remove one note." << std::endl;
	std::cout << "[5] Remove all notes." << std::endl;
	std::cout << "[6] Exit." << std::endl;
}

//add_note - добавить заметку
void add_note(const std::string& new_note) {
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

//see_all_notes - показать все заметки 
void see_all_notes() {
	std::ifstream file("notes.txt");

	if (!file.is_open()) {
		std::cout << "No notes! Add them!" << std::endl;
		return;
	}

	std::string one_note;
	std::cout << "All notes: " << std::endl;
	for (int i = 1; !file.eof(); i++) {
		getline(file, one_note);
		if (one_note.empty())
			continue;
		std::cout << '[' << i << "]" << one_note << std::endl;
	}

	file.close();
}

//find_one_one - поиск одной заметки
std::string* find_one_note(const std::string& note_to_find, int& n_count) {


	std::ifstream file("notes.txt");
	if (!file.is_open()) {
		std::cout << "No notes! Add them!" << std::endl;
		return nullptr;
	}

	std::string one_note;
	std::string* found_notes = nullptr;
	std::string* found_notes_tmp = nullptr;
	int count = 0;//количество найденых заметок
	while (!file.eof()) {
		getline(file, one_note);
		if (one_note.find(note_to_find) != -1) {
			count++;
			found_notes_tmp = new std::string[count];
			//Копируем все уже найденые заметки
			for (int i = 0; i < count - 1; i++)
				found_notes_tmp[i] = found_notes[i];
			//Добавляем найденую заметку
			found_notes_tmp[count - 1] = one_note;

			//Удаляем старое содержимое found_notes
			delete[] found_notes;

			//found_notes указывает на новый массив
			found_notes = found_notes_tmp;
			found_notes_tmp = nullptr;
		}
	}
	file.close();
	n_count = count;

	return found_notes;
}

//возвращает указатель на массив всех заметок
std::string* all_notes(int& n_count) {
	std::string* all_notes = nullptr;
	std::string* all_notes_ptr = nullptr;

	std::ifstream file("notes.txt");
	if (!file.is_open()) {
		std::cout << "File is not opened!";
		exit(EXIT_FAILURE);
	}

	std::string one_note;
	int count = 0;
	while (!file.eof()) {
		getline(file, one_note);
		if (one_note.empty())
			continue;
		count++;
		all_notes_ptr = new std::string[count];

		//Копируем уже считанные заметки 
		for (int i = 0; i < count - 1; i++)
			all_notes_ptr[i] = all_notes[i];

		//Добавляем новую заметку 
		all_notes_ptr[count - 1] = one_note;

		//Очищаем старый массив all_notes
		delete[] all_notes;

		//all_notes указывает на новый массив 
		all_notes = all_notes_ptr;
		all_notes_ptr = nullptr;
	}

	file.close();
	n_count = count;

	return all_notes;
}

//Удаляет одну заметку под индексом choice - 1
void remove_one_note(std::string* all_notes_arr, int count, int choice) {
	std::ofstream file("notes.txt");
	if (!file.is_open()) {
		std::cout << "[-]Error! File is not opened" << std::endl;
		exit(EXIT_FAILURE);

	}

	//Запись заметок без заметки с индексом choice - 1
	for (int i = 0; i < count; i++) {
		if (i == choice - 1) //Пропуск заметки с индексом choice - 1
			continue;
		file << all_notes_arr[i] << std::endl;
	}



	file.close();
}

//Удаляет все заметки
void remove_all_notes() {
	std::fstream file("notes.txt", std::ios::out | std::ios::trunc);
	if (!file.is_open()) {
		std::cout << "[-] File is not opened!" << std::endl;
		exit(EXIT_FAILURE);
	}
	file.close();
}
