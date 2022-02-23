#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const char FILENAME[] = "..\\files\\Lorem.txt";
const char FILENAME_NEW[] = "..\\files\\NewFile.txt";
const long long BUFFER_SIZE = 1024;


int main() {
    ifstream file(FILENAME, ios_base::ate | ios_base::binary);
    ofstream new_file(FILENAME_NEW, ios_base::trunc | ios_base::binary);
    if (!file.is_open() or !new_file.is_open()) {
        cout << "Some of files are not found";
        return -1;
    }

    char buffer[BUFFER_SIZE];
    const long long filesize = file.tellg();
    long long cursor = filesize - (BUFFER_SIZE - 1);
    while (cursor > 0) {
        file.seekg(cursor, ios_base::beg);
        file.read(buffer, BUFFER_SIZE - 1);
        reverse(buffer, buffer + (BUFFER_SIZE - 1));
        new_file << buffer;
        cursor -= (BUFFER_SIZE - 1);
    }
    file.seekg(ios_base::beg);
    file.read(buffer, BUFFER_SIZE - 1 + cursor);
    buffer[BUFFER_SIZE - 1 + cursor] = '\0';
    reverse(buffer, buffer + (BUFFER_SIZE - 1) + cursor);
    new_file << buffer;
}
