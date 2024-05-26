#include "Student.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    
    Student student;

    student.SetStudent();
    student.PrintStudent();
    student.SetStudentInfo();
    student.PrintStudent();
 
    student.SetSemMark();
    student.PrintMarks();

    return 0;
}
