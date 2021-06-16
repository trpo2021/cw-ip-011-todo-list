#include <fstream>
#include <iostream>
#include <string>

std::string* all_notes(int& n_count)
{
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
        for (int i = 0; i < count - 1; i++)
            all_notes_ptr[i] = all_notes[i];
        all_notes_ptr[count - 1] = one_note;
        delete[] all_notes;
        all_notes = all_notes_ptr;
        all_notes_ptr = nullptr;
    }
    
    file.close();
    n_count = count;
    return all_notes;
}
