#include <fstream>
#include <iostream>
#include <string>
// see_all_notes - показать все заметки
void see_all_notes()
{
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
