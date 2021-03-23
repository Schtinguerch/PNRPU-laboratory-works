#include <iostream>
#include <windows.h>
#include <string>
#include "Header files/Triad.h"
#include "Header files/Time.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triad withNoAgrumens;
    Triad withArguments(43, -21, 67);
    Triad copied(withArguments);

    cout << withNoAgrumens << withArguments << copied << endl;

    copied.IncFirst();
    copied.IncSecond();
    copied.IncThird();

    cout << copied << endl;

    Time nullTime;
    Time selectedTime(23, 59, 59);
    Time copiedTime(selectedTime);

    cout << nullTime << selectedTime << copiedTime << endl;

    selectedTime.IncThird();
    selectedTime.SetSecond(65);

    cout << selectedTime << endl;

    Triad triad = copiedTime;
    cout << endl << triad;
    
    return 0;
}