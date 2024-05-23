#include <iostream>
#include <Windows.h>
#include <string>
#include "Student.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Date birthDate;
    Name studentName;
    studentName.setName();
    birthDate.setDate();
    studentName.PrintName();
    birthDate.PrintDate();
    return 0;
}
