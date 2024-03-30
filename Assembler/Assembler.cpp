#include <iostream>

using namespace std;

// ������ 5 
// Y = (8 * �2 + 12 * � � 7) / (3 * x + 25), X = 4

int main()
{
    setlocale(LC_ALL, "ukr");
    long RES = 0, X = 4;

    _asm {                      ; ������� ���������� �������
        lea EBX, RES            ; ������������ ������ ���������� � ������ EBX
        mov EAX, 3              ; EAX = 3
        imul X                  ; EAX = 3 * x
        add EAX, 25             ; EAX = 3 * x + 25
        mov EDI, EAX            ; ����������� ���������� � ������ EDI
        mov EAX, 8              ; EAX = x
        imul X                  ; EAX = x ^ 2
        imul X                  ; EAX = x ^ 2 * 8
        mov EDX, X              ; EDX = 4
        imul EDX, 12            ; EDX = 4 * 12
        sub EDX, 7              ; EDX = 4 * 12 - 7
        add EAX, EDX            ; EAX = x ^ 2 * 8 + 12 * 4 - 7
        cdq                     ; ���������� �������� - ������� � EAX - EDX
        div EDI                 ; ����� � EAX, ������� � EDX
        shr EDI, 1              ; ������ ���������� �� 2
        cmp EDI, EDX            ; ��������� �������� ������� � ��������
        adc EAX, 0              ; ��������� �� ������� ���� �� ���������
        mov dword ptr[EBX], EAX ; ����������� ���������� � ������
    }
    cout << "��������� ���������: " << RES << endl;

    float x = pow(X, 2) * 8 + 12 * X - 7;
    float y = 3 * X + 25;

    cout << "��������� �++: " << x / y << endl;

}
