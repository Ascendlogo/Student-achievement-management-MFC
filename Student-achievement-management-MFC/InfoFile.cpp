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