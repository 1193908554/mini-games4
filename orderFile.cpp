#include"orderFile.h"

//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;//��ȡ����
	string interval;//ʱ���
	string stuId;//ѧ��ѧ��
	string stuName;//ѧ������
	string roomId;//�������
	string status;//ԤԼ״̬

	this->m_Size = 0;//��¼����

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

		//date��1111
		string key;
		string value;
		map<string, string>m;
		
		int pos = date.find(":");//����4

		if (pos != -1)
		{
			key = date.substr(0, pos);//��0��ʼ
			value = date.substr(pos + 1, date.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//��ȡʱ���
		pos = interval.find(":");

		if (pos != -1)
		{
			key = interval.substr(0, pos);//��0��ʼ
			value = interval.substr(pos + 1, interval.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//��ȡѧ��
		pos = stuId.find(":");

		if (pos != -1)
		{
			key = stuId.substr(0, pos);//��0��ʼ
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//��ȡ����
		pos = stuName.find(":");

		if (pos != -1)
		{
			key = stuName.substr(0, pos);//��0��ʼ
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//��ȡ�������
		pos = roomId.find(":");

		if (pos != -1)
		{
			key = roomId.substr(0, pos);//��0��ʼ
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//��ȡԤԼ״̬
		pos = status.find(":");

		if (pos != -1)
		{
			key = status.substr(0, pos);//��0��ʼ
			value = status.substr(pos + 1, status.size() - pos - 1);//size = 9  pos= 4
			m.insert(make_pair(key, value));
		}

		//��С��map�������ڴ��map������
		m_orderDate.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	//�������map����
	/*for (map<int, map<string, string>>::iterator it = m_orderDate.begin();
		it != m_orderDate.end(); it++)
	{
		cout << "����Ϊ��" << it->first;
		for (map<string, string>::iterator mit = it->second.begin();
			mit != it->second.end(); mit++)
		{
			cout << " key = " << mit->first << " value = " << mit->second << endl;
		}
	}*/
}



//����ԤԼ��¼
void OrderFile::updateOrder()
{
	if (0 == this->m_Size)//û������
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);//��д�ļ���ʽ

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

	ofs.close();//�ر�������
}