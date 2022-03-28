#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void change_asm(const char*);

int main()
{
    setlocale(LC_ALL, "Russian");
    char text[100];
    cout << "Введите свое предлжение с точкой или напишите \"0\" для предложений по умолчанию\n";
    cin.getline(text, 100);
    if (text[0] != '0') {
        change_asm(text);
    } else {
        change_asm("1st, 2nd и 3rd - исключения в языке Великобритании и Америке. Текст после точки");
        change_asm("20 телеграммааппаратов, установленныx в субботу простаивали.");
    }
}

void change_asm(const char* text) {
    char textin[100];
    char textout[100];
    strcpy(textin, text);
    cout << "input: " << textin << "\n";
    unsigned int len_ = strchr(textin, '.') - textin + 1;

    unsigned short is_prev_dec = 0;
    unsigned short bo = 0;
    unsigned short path = 0;
    char prev_liter = '\0';

    __asm {
            mov ecx, len_
            mov esi, 0

        scan_lower:
            cmp is_prev_dec, 0
            je scan_digit
            cmp textin[esi], 'a'
            jb event2
            cmp textin[esi], 'z'
            ja event2
            mov is_prev_dec, 0
        scan_digit:
            cmp textin[esi], '0'
            jb contin
            cmp textin[esi], '9'
            ja contin
            mov is_prev_dec, 1
        contin:
            inc esi
            loop scan_lower

        ; event1:
            mov path, 1
            mov ecx, len_
            mov esi, 0
        event1for:
            mov al, textin[esi]
            cmp textin[esi], 'А'
            jb event1contin
            cmp textin[esi], 'Я'
            ja event1contin
            mov al, 'Я'
            sub al, textin[esi]
            add al, 'А'

        event1contin:
            mov textout[esi], al
            inc esi
            loop event1for

            mov textout[esi], '\0'
            jmp endprogram

        event2:
            mov path, 2
            mov ecx, len_
            mov esi, 0
            mov edi, 0
        event2for:
            mov al, prev_liter
            cmp al, textin[esi]

            je event2contin
            mov al, textin[esi]
            mov textout[edi], al
            inc edi
            mov prev_liter, al

        event2contin:
            inc esi
            loop event2for
            mov textout[edi], '\0'

        endprogram:
    }

    cout << "path" << path << ": " << textout << "\n";
}
