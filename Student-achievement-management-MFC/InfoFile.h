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
		string studentNumber;//ѧ��
		string studentName;//ѧ������
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
	void Addline(CString &m_stuNUM, CString &m_stuNAME, int &m_gradeChinese, int &m_gradeMath, int &m_gradeEnglish);
	~CInfoFile();
};

