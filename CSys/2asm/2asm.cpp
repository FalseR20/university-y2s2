#include <iostream>

using namespace std;

int main()
{
	// const char textin[] = "This text will be changed in the 1st way; abcxyz. 837467 aahahhahaha stop...";
	const char textin[] = "2020, 2021 and 2022 are the worst years.";
	char textout[100];

	unsigned int len_ = strchr(textin, '.') - textin;
	textout[len_] = '\0';

	unsigned short is_prev_dec = 0;
	unsigned short bo = 0;
	unsigned short path = 0;
	char prev_liter = '\0';

	__asm {
		mov ecx, len_; Прохождение всей длины textin
		mov esi, 0; Индексация с нулевого элемента

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

	event1:
		mov path, 1
		mov ecx, len_
		mov esi, 0
	event1for:
		mov al, textin[esi]
		cmp textin[esi], 'a'
		jb event1contin
		cmp textin[esi], 'z'
		ja event1contin
		mov al, 'z'
		sub al, textin[esi]
		add al, 'a'
		
	event1contin:
		mov textout[esi], al
		inc esi
		loop event1for

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

	cout << "path " << path << ": " << textout;
}
