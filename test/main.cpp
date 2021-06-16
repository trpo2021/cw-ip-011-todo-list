#include <cstdio>
#include <fstream>
#include <ios>

#define CTEST_MAIN
#include <ctest.h>

#include <LibTODO/add_note.h>
#include <LibTODO/all_notes.h>
#include <LibTODO/find_one_note.h>
#include <LibTODO/remove_all_notes.h>
#include <LibTODO/remove_one_note.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(remove_one_note, remove_from_middle)
{
    remove_all_notes();

    std::string input[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int input_size = 3;

    int note_index_to_remove = 2;

    std::string expected_output[] = {
            "Note number 1",
            "Note number 3",
    };
    int expected_output_size = 2;

    remove_one_note(input, input_size, note_index_to_remove);

    int output_size = 0;
    std::string* output = all_notes(output_size);

    ASSERT_EQUAL(expected_output_size, output_size);
    for (int i = 0; i < expected_output_size && i < output_size; ++i) {
        ASSERT_STR(expected_output[i].c_str(), output[i].c_str());
    }

    delete[] output;
}

CTEST(remove_one_note, remove_non_existent)
{
    remove_all_notes();

    std::string input[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int input_size = 3;

    int note_index_to_remove = 4;

    std::string expected_output[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int expected_output_size = 3;

    remove_one_note(input, input_size, note_index_to_remove);

    int output_size = 0;
    std::string* output = all_notes(output_size);

    ASSERT_EQUAL(expected_output_size, output_size);
    for (int i = 0; i < expected_output_size && i < output_size; ++i) {
        ASSERT_STR(expected_output[i].c_str(), output[i].c_str());
    }

    delete[] output;
}

CTEST(add_note, add_many)
{
    remove_all_notes();

    std::string input[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int input_size = 3;

    std::string expected_output[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int expected_output_size = 3;

    for (int i = 0; i < input_size; ++i) {
        add_note(input[i]);
    }

    int output_size = 0;
    std::string* output = all_notes(output_size);

    ASSERT_EQUAL(expected_output_size, output_size);
    for (int i = 0; i < expected_output_size && i < output_size; ++i) {
        ASSERT_STR(expected_output[i].c_str(), output[i].c_str());
    }

    delete[] output;
}

CTEST(remove_all_notes, populated_file)
{
    remove_all_notes();

    std::string input[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int input_size = 3;

    for (int i = 0; i < input_size; ++i) {
        add_note(input[i]);
    }
    // Очищаем весь список
    remove_all_notes();

    int output_size = 0;
    std::string* output = all_notes(output_size);

    ASSERT_EQUAL(0, output_size);
    ASSERT_NULL(output);

    delete[] output;
}

CTEST(remove_all_notes, non_existent_file)
{
    remove("notes.txt");

    remove_all_notes();

    int output_size = 0;
    std::string* output = all_notes(output_size);

    ASSERT_EQUAL(0, output_size);
    ASSERT_NULL(output);

    delete[] output;
}

CTEST(find_one_note, trivial)
{
    remove_all_notes();

    std::string input[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int input_size = 3;

    std::string expected_output[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int expected_output_size = 3;

    for (int i = 0; i < input_size; ++i) {
        add_note(input[i]);
    }

    int output_size = 0;
    std::string* output = find_one_note("Note number", output_size);

    ASSERT_EQUAL(expected_output_size, output_size);
    for (int i = 0; i < expected_output_size && i < output_size; ++i) {
        ASSERT_STR(expected_output[i].c_str(), output[i].c_str());
    }

    delete[] output;
}

CTEST(find_one_note, trivial_one)
{
    remove_all_notes();

    std::string input[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int input_size = 3;

    std::string expected_output[] = {
            "Note number 2",
    };
    int expected_output_size = 1;

    for (int i = 0; i < input_size; ++i) {
        add_note(input[i]);
    }

    int output_size = 0;
    std::string* output = find_one_note("number 2", output_size);

    ASSERT_EQUAL(expected_output_size, output_size);
    for (int i = 0; i < expected_output_size && i < output_size; ++i) {
        ASSERT_STR(expected_output[i].c_str(), output[i].c_str());
    }

    delete[] output;
}

CTEST(all_notes, trivial)
{
    {
        std::ofstream notes_file("notes.txt", std::ios_base::trunc);
        notes_file << "Note number 1\nNote number 2\nNote number 3\n";
        notes_file.close();
    }

    std::string expected_output[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int expected_output_size = 3;

    int output_size = 0;
    std::string* output = all_notes(output_size);

    ASSERT_EQUAL(expected_output_size, output_size);
    for (int i = 0; i < expected_output_size && i < output_size; ++i) {
        ASSERT_STR(expected_output[i].c_str(), output[i].c_str());
    }

    delete[] output;
}

CTEST(all_notes, trivial_2)
{
    {
        std::ofstream notes_file("notes.txt", std::ios_base::trunc);
        notes_file << "Note number 1\nNote number 2\nNote number 3";
        notes_file.close();
    }

    std::string expected_output[] = {
            "Note number 1",
            "Note number 2",
            "Note number 3",
    };
    int expected_output_size = 3;

    int output_size = 0;
    std::string* output = all_notes(output_size);

    ASSERT_EQUAL(expected_output_size, output_size);
    for (int i = 0; i < expected_output_size && i < output_size; ++i) {
        ASSERT_STR(expected_output[i].c_str(), output[i].c_str());
    }

    delete[] output;
}
