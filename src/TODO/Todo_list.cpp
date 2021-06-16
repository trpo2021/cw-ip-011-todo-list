#include <iostream>
#include <cstdlib>
#include <string>
#include <LibTODO/show_menu.h>
#include <LibTODO/add_note.h>
#include <LibTODO/all_notes.h>
#include <LibTODO/find_one_note.h>
#include <LibTODO/remove_all_notes.h>
#include <LibTODO/remove_one_note.h>
#include <LibTODO/see_all_notes.h>
 

enum CHOISE {
    ADD_NOTE = 1,
    SEE_ALL_NOTES,
    FIND_ONE_NOTE,
    REMOVE_ONE_NOTE,
    REMOVE_ALL_NOTES
};

int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;


    while (true) {
        show_menu();
        cout << "Your choice: ";
        int choice = 0;
        cin >> choice;
        if (choice == ADD_NOTE) {
            system("cls");
            
            string new_note;
            getline(cin, new_note);//пропуск переноса строки после cin
            cout << "Note to add: ";
            getline(cin, new_note);
            add_note(new_note);

            system("pause");
        }
        else if (choice == SEE_ALL_NOTES) {
            system("cls");
            see_all_notes();
            system("pause");
        }
        else if (choice == FIND_ONE_NOTE) {
            system("cls");
            string note_to_find;
            getline(cin, note_to_find);
            cout << "Note to find: ";
            getline(cin, note_to_find);

            int n_found = 0;
            string* found_notes = find_one_note(note_to_find, n_found);

            if (found_notes) {
                cout << "Found notes: " << endl;
                for (int i = 0; i < n_found; i++)
                    cout << found_notes[i] << endl;

                delete[] found_notes;
            }
            else {
                cout << "no such note!" << endl;
            }
            system("pause");
        }
        else if (choice == REMOVE_ONE_NOTE) {
            system("cls");
            //Получаем все заметки
            int count = 0;
            string* all_notes_arr = all_notes(count);
            //Выводим их в консоль
            cout << "All_notes: " << endl;
            for (int i = 0; i < count; i++)
                cout << "[" << i + 1 << "] " << all_notes_arr[i] << endl;
            
            cout << "Number of note to remove: " << endl;
            int choice = 0; 
            cin >> choice;
            remove_one_note(all_notes_arr, count, choice);
            cout << "Your note removed!" << endl;

            delete[] all_notes_arr;

            system("pause");
        }
        else if (choice == REMOVE_ALL_NOTES) {
            system("cls");
            remove_all_notes();
            cout << "All notes removed!" << endl;
            system("pause");
        }
        else
            break;
    }
}
