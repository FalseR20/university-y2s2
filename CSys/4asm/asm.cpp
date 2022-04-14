#include <iostream>
using namespace std;


int main()
{
    const float ONE = 1, TWO = 2, FOUR = 4, MINUSFIVE = -5, FIFTEEN = 15;
    float x;
    float y;
    cout << "Print x and y (%d %d): ";
    cin >> x >> y;
    float u;

    __asm {
        finit
        fld  [x]
        fsub [y]
        fcom MINUSFIVE
        fstsw ax
        sahf
        jb p2
        fcom FIFTEEN
        fstsw ax
        sahf
        jbe p3
        jmp p1

    p1:
        fld  [y]
        fmul [y]
        fadd [ONE]
        fld  [x]
        fmul [x]
        fadd
        fld  [x]
        fmul [x]
        fadd [y]
        fadd [y]
        fdivr
        fstp [u]
        jmp endasm

    p2:
        fld  [y]
        fmul [y]
        fsub [ONE]
        fld  [x]
        fmul [x]
        fadd
        fld  [y]
        fmul [y]
        fsub [x]
        fdivr
        fstp [u]
        jmp endasm

    p3:
        fld  [y]
        fmul [y]
        fmul [TWO]
        fld  [x]
        fmul [x]
        fadd [FOUR]
        fadd
        fstp [u]
        jmp endasm

    endasm:
    }

    cout << u;
}
