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
	ifstream ifs; //�����ļ��������
	ifs.open(_F_LOGIN);
	char buf[1024] = { 0 };
	ifs.getline(buf, sizeof(buf)); //��ȡһ������
	user = CString(buf);			 //char *ת��ΪCString
	ifs.getline(buf, sizeof(buf));
	pwd = CString(buf);
	ifs.close(); //�ر��ļ�
}
void CInfoFile::WritePwd(char* user, char* pwd)
{
	ofstream ofs;	 //�����ļ��������
	ofs.open(_F_LOGIN); //���ļ�
	ofs << user << endl; //nameд���ļ�
	ofs << pwd << endl;	//pwdд���ļ�
	ofs.close();	//�ر��ļ�
}