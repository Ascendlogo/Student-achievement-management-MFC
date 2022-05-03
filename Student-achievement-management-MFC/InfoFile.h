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
		string studentNumber;//学号
		string studentName;//学生姓名
		int gradeChinese, gradeMath, gradeEnglish;//成绩
	};
	list<msg>ls;
	int num;//学生数量
	//读取登录信息
	void ReadLogin(CString &user, CString &pwd);
	//修改密码
	void WritePwd(char* user, char* pwd);
	//读取学生数据
	void ReadDocline();
	//写入文件
	void WriteDocline();
	//添加学生
	void Addline(CString &m_stuNUM, CString &m_stuNAME, int &m_gradeChinese, int &m_gradeMath, int &m_gradeEnglish);
	~CInfoFile();
};

