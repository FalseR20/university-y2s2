#include <iostream>

using namespace std;


int main() {
	char text[]     = "OhHelloMyWorld";
	char text_new[] = "              ";

	unsigned int len_ = strlen(text);
	unsigned int half = len_ / 2;
	unsigned int half2 = len_ - len_ / 2;

	__asm {
			mov  esi, 0
			mov  edi, half2
			mov  ecx, half
		forbegin1:
			mov  al, byte ptr text[esi]
			mov  byte ptr text_new[edi], al
			inc  esi
			inc  edi
			loop forbegin1

			mov  esi, half
			mov  edi, 0
			mov  ecx, half2
		forbegin2:
			mov  al, byte ptr text[esi]
			mov  byte ptr text_new[edi], al
			inc  esi
			inc  edi
			loop forbegin2
	}
	cout << " Input: " << text << '\n';
	cout << "Output: " << text_new;

	return 0;
}
