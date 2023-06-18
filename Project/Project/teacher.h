#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>

using namespace std;

struct thongtinGV
{
	char* tenGV;
	char* ngsinh;
	char* chucvu;
	char* mail;
	char* gtinh;
};
struct taikhoanGV
{
	char* nameacc;
	char *pass;
};
struct GiaoVien
{
	thongtinGV info;
	taikhoanGV acc;
	GiaoVien* Next;
};
struct listGiaoVien
{
	GiaoVien* Head;
};


void themDauDSGV(listGiaoVien& l);
GiaoVien* dangnhapGV(listGiaoVien& l);
void docfileGV(listGiaoVien& l);
void themDauDSGV(listGiaoVien& l);
void taoDSGV(listGiaoVien& l);
GiaoVien* taoGV();
void ganNULLGV(listGiaoVien& l);
void xuatThongTinGV(GiaoVien* t);
GiaoVien* doiMatKhauGV(GiaoVien*& temp, listGiaoVien l);
