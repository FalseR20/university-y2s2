#include <iostream>
#include <ctime>

char text[] = "HelloWorld";
unsigned int half = strlen(text) / 2;

void coup_halfs_asm() {
	__asm {
		mov  ecx, half
		mov  edi, half
		mov  esi, 0
		forbegin:
		mov  al, byte ptr[text + esi]
			mov  dl, byte ptr[text + edi]
			mov  byte ptr[text + edi], al
			mov  byte ptr[text + esi], dl
			inc  esi
			inc  edi
			loop forbegin
	}
}

void coup_halfs_cxx() {
	char buffer;
	int j = half;
	for (int i = 0; i < half; i++, j++) {
		buffer = text[i];
		text[i] = text[j];
		text[j] = buffer;
	}
}


int main() {
	std::cout << "Input pure: " << text << "\n";
	coup_halfs_asm();
	std::cout << "Output asm: " << text << "\n";
	coup_halfs_cxx();
	std::cout << "Output c++: " << text << "\n";

	std::cout << "\nTime testing\n";
	unsigned int start_time = clock();
	for (int i = 0; i < 1000000; i++) {
		coup_halfs_asm();
	}
	std::cout << "asm 1kk loops: " << clock() - start_time << " ms\n";
	
	start_time = clock();
	for (int i = 0; i < 1000000; i++) {
		coup_halfs_cxx();
	}
	std::cout << "c++ 1kk loops: " << clock() - start_time << " ms\n";

	return 0;
}
