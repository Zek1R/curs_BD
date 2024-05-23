#include <iostream>
#include <Windows.h>
#include <string>
#include "Student.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    
    Student student1;

    student1.SetStudent();
    student1.PrintStudent();
    return 0;
}
