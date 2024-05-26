#include "StudentWindow.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    
    StudentWindow window;
    
    bool isrun = true;
    while (isrun)
    {
        isrun = window.StudentCommander();
    }

  
    return 0;
}
