#include "employees.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::string;

void doMainProgramCycle(EmployeesArray& array)
{
    std::string command;
    while (cin >> command)
    {
        if (command == "exit")
        {
            return;
        }
        else if (command == "load")
        {
            std::string fileName;
            cin >> fileName;
            std::ifstream file(fileName.c_str());

            file >> array;
        }
        else if (command == "list")
        {
            cout << array;
        }
        else if (command == "add")
        {
            int type;
            cin >> type;
            Employee* employee = (type == DEVELOPER) ?
                            (Employee*) new Developer() :
                            (Employee*) new SalesManager();

            cin >> *employee;
            array.add(employee);

        }
    }
}

int main()
{
    EmployeesArray array;
    doMainProgramCycle(array);
    return 0;
}