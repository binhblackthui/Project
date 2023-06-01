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
struct Lop
{
	string tenLop;
	string khoa;
	int soluong;
	int top;
	int nam;
	infostudent* danhsach=NULL;
	Lop* next;
};

struct listLop {
	Lop* head = NULL;
	string namhoc;
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



struct Diem {
	float giuaki = 0;
	float cuoiki = 0;
	float diemtb = 0;
};

struct thongtin {
	infostudent info{};
	Diem diem{};
};

struct Hocphan
{
	string MaHP;
	string TenHP;
	string Tenlop;
	string GV;
	int tinchi=0;
	Thoigian time;
	int soluong=0;
	thongtin* danhsach=NULL;

	Hocphan* next;
	int top = 0;
};
struct Khoahoc
{
	
	int hocki = 0;;
	Ngay batdau = {};
	Ngay ketthuc = {};
	Hocphan* HP=NULL;
	
};


void docfileSV(list& l);//dua danh sach sinh da duoc dang ki ra mang
void demsoluongsv(list& l);//dem so luong sinh vien da đănn kí
student* creatstudent();
void GanNULLSV(list& l);
void themDauDSSV(list& l);
void vietHoaTen(char s[]);
void xuatthongtinSV(student* s);
student* dangnhapSV(list& l);
student* doiMatKhau(student*& temp, list l);
void ghifile(list s);
Ngay taoNgay(string str);
void taoHocKi(Khoahoc& k);
int themSVVaoMonHoc(Khoahoc k);
void ghiFileMonHoc(Khoahoc k);
void taoMonHoc(Khoahoc& k);
int xuatKhoaHoc(Khoahoc k);
void docFileMonHoc(Khoahoc& k);
void xuatMonHhoc(Hocphan* h);
void inHoa(string& str);
void suaMon(Hocphan*& temp);
int suaMonHoc(Khoahoc k);
int themSVMonHoc(Khoahoc& k, list l);
int xoa1SVRaKhoiMonHoc(Khoahoc k);
void xoaKhoaHoc(Khoahoc& k);
void xuatDSDiem(Hocphan* temp);
void svxemDiem(Khoahoc k, student* sv);
void svxemThongTinLop(Khoahoc k, student* sv);
Lop* taoLop();
void docFileLop(listLop& l);
void ghiDSLop(listLop l);
void taoNamHoc(listLop& l);
void taoLopHoc(listLop& l);
void xuatDSLop(listLop l);
void xuatLop(listLop l);
void themVaoLopFile(listLop& l, list& s);
void them1SVLop(listLop& l, list& s);