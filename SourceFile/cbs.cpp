#include "globalFile.h"
#include <iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include "student.h"
#include "teacher.h"
#include "manager.h"

void managerMenu(Identity *&manager)
{
    while (true)
    {
        // 多态, 父类指针创建子类对象, 调用共同的接口
        manager->operMenu();

        // 将父类指针 转为子类指针, 调用子类里其他接口
        Manager *man = (Manager *)manager; // 强转

        int select = 0;
        // 接受用户选项
        cin >> select;

        if (select == 1) // 添加账号
        {
            cout << "添加账号" << endl;
            man->addPerson();
        }
        else if (select == 2) // 查看账号
        {
            cout << "查看账号" << endl;
            man->showPerson();
        }
        else if (select == 3) // 查看机房信息
        {
            cout << "查看机房信息" << endl;
            man->showComputer();
        }
        else if (select == 4) // 清空预约
        {
            cout << "清空预约" << endl;
            man->cleanFile();
        }
        else
        {
            // 注销
            delete manager; // 销毁掉堆区对象
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

// 登录功能
void LoginIn(string fileName, int type)
{
    // 父类指针用来指向子类对象
    Identity *person = NULL;

    // 读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    // 判断身份
    if (type == 1)
    {
        cout << "请输入你的学号: " << endl;
        cin >> id;
    }
    else if (type == 2)
    {
        cout << "请输入您的职工号: " << endl;
        cin >> id;
    }

    cout << "请输入用户名" << endl;
    cin >> name;
    cout << "请输入密码" << endl;
    cin >> pwd;

    // 验证身份
    if (type == 1)
    {
        // 学生身份验证
        int fId;                                          // 从文件中读取的id号
        string fName;                                     // 从文件中获取的姓名
        string fPwd;                                      // 从文件中获取的密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) // 读到空格结束
        {
            //  cout << fId << endl;
            //  cout << fName << endl;
            //  cout << fPwd << endl;
            //  cout << endl;
            if ((fId == id) && (fName == name) && (fPwd == pwd))
            {
                cout << "学生验证登录成功! " << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);
                // 进入学生身份的子菜单

                return;
            }
        }
    }
    else if (type == 2)
    {
        // 老师身份验证
        int fId;                                          // 从文件中读取的id号
        string fName;                                     // 从文件中获取的姓名
        string fPwd;                                      // 从文件中获取的密码
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) // 读到空格结束
        {
            //  cout << fId << endl;
            //  cout << fName << endl;
            //  cout << fPwd << endl;
            //  cout << endl;
            if ((fId == id) && (fName == name) && (fPwd == pwd))
            {
                cout << "老师验证登录成功! " << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);
                // 进入学生身份的子菜单

                return;
            }
        }
    }
    else if (type == 3)
    {
        // 管理员身份验证
        string fName;                // 从文件中获取的姓名
        string fPwd;                 // 从文件中获取的密码
        while (ifs >> fName >> fPwd) // 读到空格结束
        {
            if ((fName == name) && (fPwd == pwd))
            {
                cout << "管理员验证登录成功! " << endl;
                system("pause");
                system("cls");
                person = new Manager(name, pwd);
                // 进入管理员身份的子菜单
                managerMenu(person);

                return;
            }
        }
    }
    cout << "验证登录失败" << endl;
    system("pause");
    system("cls");

    return;
}

int main()
{
    char select = 0;

    while (true)
    {
        cout << "=================== 欢迎来到传智播客机房预约系统======================" << endl;
        cout << endl
             << "请输入您的身份" << endl;
        cout << "\t\t ---------------------- \n";
        cout << "\t\t|                      |\n";
        cout << "\t\t|     1. 学生代表      |\n";
        cout << "\t\t|                      |\n";
        cout << "\t\t|     2. 老    师      |\n";
        cout << "\t\t|                      |\n";
        cout << "\t\t|     3. 管 理 员      |\n";
        cout << "\t\t|                      |\n";
        cout << "\t\t|     0. 退    出      |\n";
        cout << "\t\t|                      |\n";
        cout << "\t\t ---------------------- \n";
        cout << "输入您的选择: ";

        cin >> select;

        switch (select) // 根据用户选择 实现不同接口
        {
        case '1': // 学生身份
            LoginIn(STUDENT_FILE, 1);
            break;
        case '2': // 老师身份
            LoginIn(TEACHER_FILE, 2);
            break;
        case '3': // 管理员
            LoginIn(ADMIN_FILE, 3);
            break;
        case '0': // 退出
            cout << "欢迎下一次使用" << endl;
            system("pause");
            return 0;
        default:
            cout << "输入有误, 请重新选择!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}