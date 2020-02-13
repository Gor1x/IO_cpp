#include "employees.h"

int SalesManager::salary() const
{
    return _base_salary + _sold_nm * _price * 0.01;
}

void SalesManager::printInfo(std::ostream &os) const
{
    os << "Sales Manager " << std::endl;
    os << "Name: " << _name << std::endl;
    os << "Base Salary: " << _base_salary << std::endl;
    os << "Sold items: " << _sold_nm << std::endl;
    os << "Item price: " << _price << std::endl;
}

void SalesManager::readInfo(std::istream &input)
{
    input >> _name >> _base_salary >> _sold_nm >> _price;
}


int Developer::salary() const
{
        int salary = _base_salary;
        if (_has_bonus)
        {
            salary += 1000;
        }
        return salary;
}

void Developer::printInfo(std::ostream &os) const
{
    os << "Developer " << std::endl;
    os << "Name: " << _name << std::endl;
    os << "Base Salary: " << _base_salary << std::endl;
    os << "Has bonus: " << (_has_bonus ? '+' : '-') << std::endl;
}

void Developer::readInfo(std::istream &input)
{
    input >> _name >> _base_salary >> _has_bonus;
}


void EmployeesArray::add(const Employee *e)
{
    _employees.push_back(e);
}

int EmployeesArray::total_salary() const
{
    int totalSum = 0;
    for (auto v : _employees)
    {
        totalSum += v->salary();
    }
    return totalSum;
}

std::istream &operator>>(std::istream &is, EmployeesArray &array)
{
    is.unsetf(std::ios::dec);
    is.setf(std::ios::hex);

    int32_t peopleCount;
    is >> peopleCount;
    for (size_t i = 0; i < peopleCount; i++)
    {
        int32_t type;
        is >> type;

        Employee* employee = (type == DEVELOPER) ?
                             (Employee*)new Developer():
                             (Employee*)new SalesManager();

        is >> (*employee);

        array.add(employee);
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, EmployeesArray &array)
{
    array.print(os);
    os << "== Total salary: " << array.total_salary() << std::endl;
}

void EmployeesArray::print(std::ostream &os)
{
    for (size_t i = 0; i < _employees.size(); i++)
    {
        os << i + 1 << ". ";
        os << *(_employees[i]);
    }
}

EmployeesArray::~EmployeesArray()
{
    for (auto & _employee : _employees)
    {
        delete _employee;
    }
}

std::istream &operator>>(std::istream &input, Employee &employee)
{
    employee.readInfo(input);
    return input;
}

std::ostream &operator<<(std::ostream &output, const Employee &employee)
{
    employee.printInfo(output);
    return output;
}

