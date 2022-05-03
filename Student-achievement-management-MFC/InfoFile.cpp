#include "stdafx.h"
#include "InfoFile.h"


CInfoFile::CInfoFile()
{
}


CInfoFile::~CInfoFile()
{
}

void CInfoFile::ReadLogin(CString &user, CString &pwd)
{
	ifstream ifs; //创建文件输入对象
	ifs.open(_F_LOGIN);
	char buf[1024] = { 0 };
	ifs.getline(buf, sizeof(buf)); //读取一行内容
	user = CString(buf);			 //char *转换为CString
	ifs.getline(buf, sizeof(buf));
	pwd = CString(buf);
	ifs.close(); //关闭文件
}
void CInfoFile::WritePwd(char* user, char* pwd)
{
	ofstream ofs;	 //创建文件输出对象
	ofs.open(_F_LOGIN); //打开文件
	ofs << user << endl; //name写入文件
	ofs << pwd << endl;	//pwd写入文件
	ofs.close();	//关闭文件
}
void CInfoFile::ReadDocline()
{
	ifstream ifs(_F_DATA); //输入方式打开文件

	char buf[1024] = { 0 };
	ls.clear();//清空链表
	ifs.getline(buf, sizeof(buf));//取出表头

	while (!ifs.eof()) //读到文件末尾则结束
	{
		msg tmp;
		ifs.getline(buf, sizeof(buf)); //读取一行
		char *sst = strtok(buf, "|"); //以“|”切割
		if (sst != NULL)
		{
			tmp.studentNumber = sst; //学号
		}
		else
		{
			break;
		}
		sst = strtok(NULL, "|");
		tmp.studentName = sst;	//姓名
		sst = strtok(NULL, "|");
		tmp.gradeChinese = atoi(sst);//语文成绩
		sst = strtok(NULL, "|");
		tmp.gradeMath = atoi(sst);	//数学成绩
		sst = strtok(NULL, "|");
		tmp.gradeEnglish = atoi(sst);	//英语成绩
		ls.push_back(tmp); //放在链表的后面
		
	}
	ifs.close(); //关闭文件
}
void CInfoFile::WriteDocline()
{
	ofstream ofs(_F_DATA);//输出方式打开文件

	if (ls.size() > 0)	//链表有内容才执行
	{
		ofs << "学号|姓名|语文成绩|数学成绩|英语成绩" << endl; //写入表头
		//通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
		for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			ofs << it->studentNumber << "|";
			ofs << it->studentName << "|";
			ofs << it->gradeChinese << "|";
			ofs << it->gradeMath << "|";
			ofs << it->gradeEnglish << endl;
		}
	}

	ofs.close();//关闭文件
}
void CInfoFile::Addline(CString &m_stuNUM, CString &m_stuNAME, int &m_gradeChinese, int &m_gradeMath, int &m_gradeEnglish)
{
	msg tmp;

	if (ls.size() > 0)
	{
		//商品名称，库存，价格有效
		CStringA str1,str2;
		str1 = m_stuNUM;	//CString转CStirngA
		tmp.studentNumber = str1.GetBuffer(); //CStirngA转char *
		str2 = m_stuNAME;	//CString转CStirngA
		tmp.studentName = str2.GetBuffer(); //CStirngA转char *
		tmp.gradeChinese = m_gradeChinese;
		tmp.gradeMath = m_gradeMath;
		tmp.gradeEnglish = m_gradeEnglish;
		ls.push_back(tmp);	//放在链表的后面
	}
}

