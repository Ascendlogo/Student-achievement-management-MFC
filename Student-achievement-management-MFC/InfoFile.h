#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#define _F_LOGIN "./login.ini"
#define _F_DATA "./data.txt"
using namespace std;
class CInfoFile
{
public:
	CInfoFile();
	struct msg
	{
		char studentNumber[20];//ѧ��
		char studentName[20];//ѧ������
		int gradeChinese, gradeMath, gradeEnglish;//�ɼ�
	};
	list<msg>ls;
	int num;//ѧ������
	//��ȡ��¼��Ϣ
	void ReadLogin(CString &user, CString &pwd);
	//�޸�����
	void WritePwd(char* user, char* pwd);
	//��ȡѧ������
	void ReadDocline();
	//д���ļ�
	void WriteDocline();
	//���ѧ��
	void Addline(CString user, int num);
	~CInfoFile();
};

