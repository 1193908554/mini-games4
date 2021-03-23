#include"orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;//读取日期
	string interval;//时间段
	string stuId;//学生学号
	string stuName;//学生姓名
	string roomId;//机房编号
	string status;//预约状态

	this->m_Size = 0;//记录条数

	while (ifs >> date && ifs >> interval && ifs >> stuId 
		&& ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;
		cout << endl;*/

		//date：1111
		string key;
		string value;
		map<string, string>m;
		
		int pos = date.find(":");//返回4

		if (pos != -1)
		{
			key = date.substr(0, pos);//从0开始
			value = date.substr(pos + 1, date.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//截取时间段
		pos = interval.find(":");

		if (pos != -1)
		{
			key = interval.substr(0, pos);//从0开始
			value = interval.substr(pos + 1, interval.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//截取学号
		pos = stuId.find(":");

		if (pos != -1)
		{
			key = stuId.substr(0, pos);//从0开始
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//截取姓名
		pos = stuName.find(":");

		if (pos != -1)
		{
			key = stuName.substr(0, pos);//从0开始
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//截取机房编号
		pos = roomId.find(":");

		if (pos != -1)
		{
			key = roomId.substr(0, pos);//从0开始
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//截取预约状态
		pos = status.find(":");

		if (pos != -1)
		{
			key = status.substr(0, pos);//从0开始
			value = status.substr(pos + 1, status.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//将小的map容器放在大的map容器中
		m_orderDate.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	//测试最大map容器
	/*for (map<int, map<string, string>>::iterator it = m_orderDate.begin();
		it != m_orderDate.end(); it++)
	{
		cout << "条数为：" << it->first;
		for (map<string, string>::iterator mit = it->second.begin();
			mit != it->second.end(); mit++)
		{
			cout << " key = " << mit->first << " value = " << mit->second << endl;
		}
	}*/
}



//更新预约记录
void OrderFile::updateOrder()
{
	if (0 == this->m_Size)//没有数据
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);//重写文件方式

	for (int i = 0; i < this->m_Size; i++)
	{
		ofs<<"date:"<< this->m_orderDate[i]["date"] << " ";
		ofs << "interval:" << this->m_orderDate[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderDate[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderDate[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderDate[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderDate[i]["status"] << " ";
		ofs << endl;
	}

	ofs.close();//关闭输入流
}