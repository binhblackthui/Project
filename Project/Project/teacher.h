#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>
#include<string.h>
#include<cctype>
using namespace std;

struct infoteacher
{
	char* tenGV;
	char* ngsinh;
	char* chucvu;
	char* mail;
	char* gtinh;
};
struct accteacher
{
	char* nameacc;
	char *pass;
};
struct teacher
{
	infoteacher info;
	accteacher acc;
	teacher* Next;
};
struct listteacher
{
	teacher* Head;
};


void themDauDSGV(listteacher& l);
teacher* dangnhapGV(listteacher& l);
void docfileGV(listteacher& l);
void themDauDSGV(listteacher& l);
void taoDSGV(listteacher& l);
teacher* taoGV();
void ganNULLGV(listteacher& l);
void xuatThongTinGV(teacher* t);
void doiMatKhauGV(teacher* temp, listteacher l);
