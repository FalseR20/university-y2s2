#include <iostream>

using namespace std;


int main() {
	int a = 5;

	__asm {
		add a, 2
	}

	cout << a;
}
