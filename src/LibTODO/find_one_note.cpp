#include <iostream>
#include <fstream>
#include <string>
//find_one_one - поиск одной заметки
std::string* find_one_note(const std::string& note_to_find, int& n_count) {
long unsigned int temp=-1;

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
		if (one_note.find(note_to_find) != temp) {
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
