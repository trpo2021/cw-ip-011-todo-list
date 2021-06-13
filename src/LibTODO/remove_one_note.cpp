#include <fstream>
#include <iostream>
#include <string>
//Удаляет одну заметку под индексом choice - 1
void remove_one_note(std::string* all_notes_arr, int count, int choice)
{
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
