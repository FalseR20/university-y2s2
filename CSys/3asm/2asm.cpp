#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void change_asm(const char*, const char);

int main()
{
    const char text[100] = "This sentence has a lot of sense.";
    const char letter = 's';
    change_asm(text, letter);
}

void change_asm(const char* text, const char letter) {
    char textin[100];
    char textout[100];
    strcpy(textin, text);
    int len_ = strlen(text);
    cout << " input: " << textin << "\n";

    __asm {
            mov ecx, len_
            mov esi, 0
            mov edi, 0

        forbegin:
            cmp textin[esi], ' '
            jne skipnext
            mov al, textin[esi + 1]
            cmp al, letter
            jne skipnext
        skipword:
            inc esi
            dec ecx
            cmp textin[esi], ' '
            je forbegin
            cmp textin[esi], '.'
            je forbegin
            jmp skipword

        skipnext:
            mov al, textin[esi]
            mov textout[edi], al
            inc edi
            inc esi
            loop forbegin

            mov textout[edi], '\0'
    }

    cout << "output: " << textout << "\n";
}
