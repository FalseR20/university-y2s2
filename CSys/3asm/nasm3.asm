section	.text
   global _start    

%macro print 2
    ;вывод полученной строки
    mov	edx, %1
    mov	ecx, %2
    mov	ebx, 1
    mov	eax, 4
    int	0x80
%endmacro

_start:	
    mov ecx, len
    mov esi, 0
    mov edi, 0

forbegin:
    cmp byte [textin + esi], ' '
    jne skipnext
    mov al, byte [textin + esi + 1]
    cmp al, [letter]
    jne skipnext
skipword:
    inc esi
    dec ecx
    cmp byte [textin + esi], ' '
    je forbegin
    cmp byte [textin + esi], '.'
    je forbegin
    jmp skipword

skipnext:
    mov al, byte [textin + esi]
    mov byte [textout + edi], al
    inc edi
    inc esi
    loop forbegin
    mov byte [textout + edi - 1], 0
    
    print len, textout
    mov	eax,1
    int	0x80	 

section	.data
    textin db 'This sentence has a lot of sense.'
    letter db 's'
    len equ  $-textin
    textout times(len) db ' '
