#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>
#include<string.h>
#include<cctype>
#include<iomanip>
using namespace std;

struct infostudent
{
	long long MSSV;
	char* tensv;
	char* gtinh;
	char* lop;
	char* ngsinh;
	long long CCCD;
	char* chucvu;
};
struct account
{
	char* tenTK;
	char* password;
};
struct student
{
	account acc;
	infostudent info;
	student* pNext;
};
struct classroom {
	char tenlop[20];
	char nganh[30];
	int n = 0;
	int nam;
};
struct list
{
	student* pHead;
};

struct Ngay
{
	int ngay, thang, nam;
};

struct Thoigian
{
	string gioBatDau;
	string gioKetThuc;
	string thu;
};

struct Hocphan
{
	string MaHP;
	string TenHP;
	string Tenlop;
	string GV;
	int tinchi;
	Thoigian time;
	int soluong;
	infostudent* danhsach;
	Hocphan* next;
	int top = 0;
};
struct Khoahoc
{
	
	int hocki = 0;;
	Ngay batdau;
	Ngay ketthuc;
	Hocphan* HP=NULL;
	
};


void docfileSV(list& l);//dua danh sach sinh da duoc dang ki ra mang
void demsoluongsv(list& l);//dem so luong sinh vien da đănn kí
student* creatstudent();
void GanNULLSV(list& l);
void themDauDSSV(list& l);
void vietHoaTen(char s[]);
void dangkiSV(list& l,classroom *lop);
void xuatthongtinSV(student* s);
student* dangnhapSV(list& l);
student* doiMatKhau(student*& temp, list l);
void dslop(list s, classroom* &lop, int& n);
void xuatlop(classroom* lop, int n,list s);
int taonamhoc(int& namhoc);
void taolop(list s, classroom* &lop, int namhoc);
void nhaptay(list s, classroom* lop);
void nhapfile(list s, classroom* lop);
void them1SV(list& s);
void ghifile(list s);
void xoa1SV(list& s);
Ngay taoNgay(string str);
void taoHocKi(Khoahoc& k);
int themSVVaoMonHoc(Khoahoc k);
void ghiFileMonHoc(Khoahoc k);
void taoMonHoc(Khoahoc& k);
void xuatKhoaHoc(Khoahoc k);
void docFileMonHoc(Khoahoc& k);
void xuatMonHhoc(Hocphan* h);
void inHoa(string& str);
void suaMon(Hocphan*& temp);
int suaMonHoc(Khoahoc k);
int themSVMonHoc(Khoahoc& k, list l);
int xoa1SVRaKhoiMonHoc(Khoahoc k);
void xoaKhoaHoc(Khoahoc& k);