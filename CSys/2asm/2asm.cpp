#include <iostream>

using namespace std;

int main()
{
	const char textin[] = "Этот текст имеет скрытый 2ой смысл. Ахахаха 435346426 а стоп...";
	// const char textin[] = "У этого текста 20 значений. Смысла немного после точки";
	char textout[100];

	unsigned int len_ = strchr(textin, '.') - textin;
	textout[len_] = '\0';

	unsigned short is_prev_dec = 0;
	unsigned short bo = 0;

	__asm {
		mov ecx, len_; Прохождение всей длины textin
		mov esi, 0; Индексация с нулевого элемента

	scan_lower:
		cmp is_prev_dec, 0
		je scan_digit
		cmp textin[esi], 'а'
		jb event2
		cmp textin[esi], 'я'
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

		mov textout[0], 'Y'
		jmp endprogram
	event2:
		mov textout[1], 'N'
	endprogram:
	}

	cout << textout;
}
