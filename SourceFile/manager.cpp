#include "manager.h"

// 默认构造
Manager::Manager()
{

}


// 有参构造
Manager::Manager(string name, string pwd)
{
    // 初始化管理员信息
    this->m_Name = name;
    this->m_Pwd = pwd;

    // 初始化容器 获取到所有文件中 学生/老师信息
    this->initVector();
}

// 菜单界面
void Manager::operMenu()
{
    cout << "欢迎管理员: " << this->m_Name << "登录! " << endl;
    cout << "\t\t---------------------------------------\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|            1. 添加账号              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|            2. 查看账号              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|            3. 查看机房              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|            4. 清空预约              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|            0. 注销登录              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t---------------------------------------\n";
    cout << "请选择您的操作:   " << endl;
}

// 添加账号
void Manager::addPerson()
{
    // 提示
    cout << "请输入添加账号的类型" << endl;
    cout << "1. 添加学生" << endl;
    cout << "2. 添加老师" << endl;

    string fileName;  // 操作文件名
    string tip;  // 提示ID号
    string errTip; // 错误重复提示

    ofstream ofs;  //文件操作对象

    int select = 0;
    cin >> select;  // 接受用户的选项

    if (select == 1)
    {
        // 添加的是学生
        fileName = STUDENT_FILE;
        tip = "请输入学号: ";       
        errTip = "学号重复, 请重新输入"; 
    }
    else
    {
        // 添加的是老师
        fileName = TEACHER_FILE;
        tip = "请输入职工编号: ";        
        errTip = "职工号重复, 请重新输入"; 
    }

    ofs.open(fileName, ios::out | ios::app);

    int id;  // 学号/职工号
    string name;
    string pwd;

    cout << tip << endl;

    while (true)
    {
        cin >> id;
        bool ret = checkRepeat(id, select);
        if (ret)
        {
            cout << errTip << endl;
        }
        else
        {
            break;
        }
    }

    cout << "请输入姓名: " << endl;
    cin >> name;

    cout << "请输入密码: " << endl;
    cin >> pwd;

    //向文件中添加数据
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

    system("pause");
    system("cls");

    ofs.close();

    // 初始化程序
    this->initVector();
}

// 查看账号
void Manager::showPerson()
{

}

// 查看机房信息
void Manager::showComputer()
{
    
}

// 清空预约记录
void Manager::cleanFile()
{

}

// 读取学生文件中信息
void Manager::initVector()
{
    vStu.clear();
    vTea.clear();

    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }


    Student s;
    while(ifs >> s.m_Id && ifs >>s.m_Name && ifs >> s.m_Pwd)
    {
        vStu.push_back(s);
    }
    cout << "当前学生数量为: " << vStu.size() << endl;
    ifs.close();  // 学生初始化

    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }
    Teacher t;
    while(ifs >> t.m_EmpId && ifs >>t.m_Name && ifs >> t.m_Pwd)
    {
        vTea.push_back(t);
    }
    cout << "当前老师数量为: " << vTea.size() << endl;
    ifs.close();  // 学生初始化
}

/// @brief 
/// @param id 学生学号/教师职工号
/// @param type 检测类型
/// @return 
bool Manager::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        for(vector<Student>::iterator it = vStu.begin(); it !=vStu.end(); it++)
        {
            if(id== it->m_Id)
            {
                return true;
            }
        }
    }
    else if (type == 2)
    {
        for(vector<Teacher>::iterator it = vTea.begin(); it !=vTea.end(); it++)
        {
            if(id== it->m_EmpId)
            {
                return true;
            }
        }

    }

    return false;
}