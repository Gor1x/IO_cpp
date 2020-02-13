#ifndef LAB11_EMPLOYEES_H_INCLUDED
#define LAB11_EMPLOYEES_H_INCLUDED

#include <iostream>
#include <cstdint>
#include <cstddef>
#include <vector>

enum employeeTypes {
    DEVELOPER = 1,
    SALES_MANAGER = 2
};

class Employee {
public:
    virtual int salary() const = 0;

    virtual void printInfo(std::ostream &output) const = 0 ;
    virtual void readInfo(std::istream &input) = 0;

    friend std::ostream& operator << (std::ostream &output, const Employee&);
    friend std::istream& operator >> (std::istream &input, Employee&);

protected:
    std::string _name;
    int32_t _base_salary;
};

class Developer : Employee {

public:
    int salary() const override;

private:
    void printInfo(std::ostream &os) const override;

    void readInfo(std::istream &input) override;

private:
    bool _has_bonus;
};

class SalesManager : Employee{

private:
    void printInfo(std::ostream &os) const override;
    void readInfo(std::istream &input) override;

public:
    int salary() const override;

private:

    int32_t _sold_nm, _price;
};

class EmployeesArray {
public:
    void add(const Employee *e);

    void print(std::ostream &os);

    int total_salary() const;


    friend std::istream& operator >> (std::istream &is, EmployeesArray&);
    friend std::ostream& operator << (std::ostream &os, EmployeesArray&);

    virtual ~EmployeesArray();

private:
    std::vector<const Employee* > _employees;
};

#endif