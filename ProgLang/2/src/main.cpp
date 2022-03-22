#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int main() {
    const char FILENAME[] = "..\\files\\Lorem.txt";
    //const char FILENAME[] = "..\\files\\Alphabet.txt";
    const char FILENAME_NEW[] = "..\\files\\NewFile.txt";
    const long long BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE + 1];

    ifstream file(FILENAME, ios_base::ate | ios_base::binary);  // Бинарное открытие файла с конца для ввода
    ofstream fileNew(FILENAME_NEW, ios_base::binary);  // Бинарное открытие файла для вывода

    if (!file.is_open() or !fileNew.is_open()) {  // Проверка на открытие
        cout << "File was not found";
        return 0;
    }

    long long cursor = file.tellg() - BUFFER_SIZE;  // Курсор файла = BUFFER_SIZE с конца
    while (cursor > 0) {
        file.seekg(cursor, ios_base::beg);  // Перенос указателя в потоке файла на курсор
        file.read(buffer, BUFFER_SIZE);  // Чтение в буфер BUFFER_SIZE символов
        reverse(buffer, buffer + BUFFER_SIZE);  // Поворот буфера
        fileNew << buffer;  // Запись в новый файл
        cursor -= BUFFER_SIZE;  // Смещение курсора
    }
    cursor += BUFFER_SIZE;  // Теперь курсор - это конец: запись с 0 до cursor

    file.seekg(ios_base::beg);  // Перенос указателя в потоке файла на начало
    file.read(buffer, cursor);  // Чтение в буфер cursor символов
    buffer[cursor] = '\0';  // Заполяется не весь буфер, поэтому надо отделить
    reverse(buffer, buffer + cursor);
    fileNew << buffer;

    file.close();  // Закрытие файлов
    fileNew.close();

    return 0;
}
