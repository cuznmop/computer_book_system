#include "orderFile.h"

// 构造函数
OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string date;   // 日期
    string interval;  // 时间段
    string stuId;  // 学号
    string stuName;  // 姓名
    string roomId;  // 机房号     
    string status;  // 预约状态

    this->m_Size = 0;  // 记录条数

    while(ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId &&ifs >> status)
    {
        string key;
        string value;
        map<string, string>m;

        int pos = date.find(":");
        if (pos != -1)
        {
            key = date.substr(0, pos);
            value = date.substr(pos+1, date.size() - pos - 1);  //直接写pos + 1就可以了，默认是剩下字符

            m.insert(make_pair(key, value));
        }
        
        pos = interval.find(":");
        if (pos != -1)
        {
            key = interval.substr(0, pos);
            value = interval.substr(pos+1, interval.size() - pos - 1);  //直接写pos + 1就可以了，默认是剩下字符

            m.insert(make_pair(key, value));
        }
        
        pos = stuId.find(":");
        if (pos != -1)
        {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos+1, stuId.size() - pos - 1);  //直接写pos + 1就可以了，默认是剩下字符

            m.insert(make_pair(key, value));
        }
        
        pos = stuName.find(":");
        if (pos != -1)
        {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos+1, stuName.size() - pos - 1);  //直接写pos + 1就可以了，默认是剩下字符

            m.insert(make_pair(key, value));
        }
        
        pos = roomId.find(":");
        if (pos != -1)
        {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos+1, roomId.size() - pos - 1);  //直接写pos + 1就可以了，默认是剩下字符

            m.insert(make_pair(key, value));
        }
        
        pos = status.find(":");
        if (pos != -1)
        {
            key = status.substr(0, pos);
            value = status.substr(pos+1, status.size() - pos - 1);  //直接写pos + 1就可以了，默认是剩下字符

            m.insert(make_pair(key, value));
        }

        // 将小map容器放入到大的map容器中
        this->m_orderData.insert(make_pair(this->m_Size, m));
        this->m_Size++;
        
    }

    ifs.close();

    for(map<int, map<string, string>>::iterator it=m_orderData.begin(); it != m_orderData.end(); it++)
    {
        cout << "条数为: " << it ->first << " value = " << endl;
        for(map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
        {
            cout << "key = " << mit->first << " value= " << mit->second << " ";
        }
        cout << endl;
    }
}

// 更新预约记录
void OrderFile::updateOrder()
{

}