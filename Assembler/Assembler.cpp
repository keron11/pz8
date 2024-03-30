#include <iostream>

using namespace std;

// Варіант 5 
// Y = (8 * х2 + 12 * х – 7) / (3 * x + 25), X = 4

int main()
{
    setlocale(LC_ALL, "ukr");
    long RES = 0, X = 4;

    _asm {                      ; початок асемблерної вставки
        lea EBX, RES            ; завантаження адреси результатів в регістр EBX
        mov EAX, 3              ; EAX = 3
        imul X                  ; EAX = 3 * x
        add EAX, 25             ; EAX = 3 * x + 25
        mov EDI, EAX            ; пересилання знаменника в регістр EDI
        mov EAX, 8              ; EAX = x
        imul X                  ; EAX = x ^ 2
        imul X                  ; EAX = x ^ 2 * 8
        mov EDX, X              ; EDX = 4
        imul EDX, 12            ; EDX = 4 * 12
        sub EDX, 7              ; EDX = 4 * 12 - 7
        add EAX, EDX            ; EAX = x ^ 2 * 8 + 12 * 4 - 7
        cdq                     ; розширення операнда - ділимого в EAX - EDX
        div EDI                 ; часне – EAX, залишок – EDX
        shr EDI, 1              ; ділення знаменника на 2
        cmp EDI, EDX            ; порівняння половини дільника з залишком
        adc EAX, 0              ; додавання до часного заєму від порівняння
        mov dword ptr[EBX], EAX ; пересилання результату в пам’ять
    }
    cout << "Результат Асемблеру: " << RES << endl;

    float x = pow(X, 2) * 8 + 12 * X - 7;
    float y = 3 * X + 25;

    cout << "Результат С++: " << x / y << endl;

}
