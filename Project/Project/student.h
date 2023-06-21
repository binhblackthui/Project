#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

struct thongtinSV
{
	long long MSSV;
	char* tensv;
	char* gtinh;
	char* lop;
	char* ngsinh;
	long long CCCD;
};
struct taikhoanSV
{
	char* tenTK;
	char* password;
};
struct SinhVien
{
	taikhoanSV acc;
	thongtinSV info;
	SinhVien* pNext;
};
struct Lop
{
	string tenLop;
	string khoa;
	int soluong;
	int top;
	int nam;
	thongtinSV* danhsach=NULL;
	Lop* next;
};

struct listLop {
	Lop* head = NULL;
	string namhoc;
};
struct listSinhVien 
{
	SinhVien* pHead;
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

struct Thongtin {
	thongtinSV info{};
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
	int nam = 0;
	int hki = 0;
	Thongtin* danhsach=NULL;

	Hocphan* next;
	int top = 0;
};
struct Khoahoc
{
	
	int hocki = 0;
	Ngay batdau = {};
	Ngay ketthuc = {};
	Hocphan* HP=NULL;
	
};


void docfileSV(listSinhVien& l);//dua danh sach sinh da duoc dang ki ra mang
void demsoluongsv(listSinhVien& l);//dem so luong sinh vien da đănn kí
SinhVien* taoSV();
void GanNULLSV(listSinhVien& l);
void themDauDSSV(listSinhVien& l);
void xuatthongtinSV(SinhVien* s);
SinhVien* dangnhapSV(listSinhVien& l);
SinhVien* doiMKSV(SinhVien*& temp, listSinhVien l);
void ghifile(listSinhVien s);
Ngay taoNgay(string str);
void taoHocKi(Khoahoc& k);
int themSVVaoMonHoc(Khoahoc k, listLop  lop);
void ghiFileMonHoc(Khoahoc k);
void taoMonHoc(Khoahoc& k, listLop lop);
int xuatKhoaHoc(Khoahoc k);
void docFileMonHoc(Khoahoc& k);
void xuatMonHhoc(Hocphan* h);
void inHoa(string& str);
void suaMon(Hocphan*& temp);
int suaMonHoc(Khoahoc k,listLop lop);
int themSVMonHoc(Khoahoc& k, listSinhVien l, listLop lop);
int xoa1SVRaKhoiMonHoc(Khoahoc k, listLop  lop);
void xoaKhoaHoc(Khoahoc& k);
void xuatDSDiem(Hocphan* temp);
void svxemDiem(Khoahoc k, SinhVien* sv);
void svxemThongTinLop(Khoahoc k, SinhVien* sv);
Lop* taoLop();
void docFileLop(listLop& l);
void ghiDSLop(listLop l);
void taoNamHoc(listLop& l);
void taoLopHoc(listLop& l);
void xuatDSLop(listLop l);
void xuatLop(listLop l);
void themVaoLopFile(listLop& l, listSinhVien& s);
void them1SVLop(listLop& l, listSinhVien& s);