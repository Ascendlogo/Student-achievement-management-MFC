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
void CInfoFile::ReadDocline()
{
	ifstream ifs(_F_DATA); //���뷽ʽ���ļ�

	char buf[1024] = { 0 };
	ls.clear();//�������
	ifs.getline(buf, sizeof(buf));//ȡ����ͷ

	while (!ifs.eof()) //�����ļ�ĩβ�����
	{
		msg tmp;
		ifs.getline(buf, sizeof(buf)); //��ȡһ��
		char *sst = strtok(buf, "|"); //�ԡ�|���и�
		if (sst != NULL)
		{
			tmp.studentNumber = sst; //ѧ��
		}
		else
		{
			break;
		}
		sst = strtok(NULL, "|");
		tmp.studentName = sst;	//����
		sst = strtok(NULL, "|");
		tmp.gradeChinese = atoi(sst);//���ĳɼ�
		sst = strtok(NULL, "|");
		tmp.gradeMath = atoi(sst);	//��ѧ�ɼ�
		sst = strtok(NULL, "|");
		tmp.gradeEnglish = atoi(sst);	//Ӣ��ɼ�
		ls.push_back(tmp); //��������ĺ���
		
	}
	ifs.close(); //�ر��ļ�
}
void CInfoFile::WriteDocline()
{
	ofstream ofs(_F_DATA);//�����ʽ���ļ�

	if (ls.size() > 0)	//���������ݲ�ִ��
	{
		ofs << "ѧ��|����|���ĳɼ�|��ѧ�ɼ�|Ӣ��ɼ�" << endl; //д���ͷ
		//ͨ��������ȡ���������ݣ�д���ļ����ԡ�|���ָ�����β�ӻ���
		for (list<msg>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			ofs << it->studentNumber << "|";
			ofs << it->studentName << "|";
			ofs << it->gradeChinese << "|";
			ofs << it->gradeMath << "|";
			ofs << it->gradeEnglish << endl;
		}
	}

	ofs.close();//�ر��ļ�
}
void CInfoFile::Addline(CString &m_stuNUM, CString &m_stuNAME, int &m_gradeChinese, int &m_gradeMath, int &m_gradeEnglish)
{
	msg tmp;

	if (ls.size() > 0)
	{
		//��Ʒ���ƣ���棬�۸���Ч
		CStringA str1,str2;
		str1 = m_stuNUM;	//CStringתCStirngA
		tmp.studentNumber = str1.GetBuffer(); //CStirngAתchar *
		str2 = m_stuNAME;	//CStringתCStirngA
		tmp.studentName = str2.GetBuffer(); //CStirngAתchar *
		tmp.gradeChinese = m_gradeChinese;
		tmp.gradeMath = m_gradeMath;
		tmp.gradeEnglish = m_gradeEnglish;
		ls.push_back(tmp);	//��������ĺ���
	}
}

