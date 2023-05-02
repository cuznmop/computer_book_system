#pragma once
#include <iostream>
#include "identity.h"
using namespace std;
#include <string>
#include "orderFile.h"
#include <vector>

class Teacher : public Identity
{
public:
    Teacher();

    Teacher(int empId, string name, string pwd);

    void operMenu();

    void showAllOrder();

    void validOrder();

    int m_EmpId;
};