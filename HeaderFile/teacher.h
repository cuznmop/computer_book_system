#pragma once
#include <iostream>
#include "identity.h"
using namespace std;

class Teacher : public Identity
{
public:
    Teacher();

    Teacher(int empId, string name, string pwd);

    virtual void operMenu();

    void showAllOrder();

    void validOrder();

    int m_EmpId;
};