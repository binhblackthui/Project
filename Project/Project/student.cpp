﻿#include"student.h"


void demsoluongsv(listSinhVien& l)//TAO 1 DANH SACH LIEN KET SO luong sinh vien trong file TAI KHOAN SINH VIEN
{
	char temp[10000];
	ifstream file;
	file.open("../Project/Tai Khoan/accstudent.csv", ios::in);
	if (file.fail() == true)
		cout << "mo file khon thanh cong";
	file.getline(temp, 1000);
	while (file.getline(temp, 1000))
	{
		themDauDSSV(l);
	}
	file.close();
}


void docfileSV(listSinhVien& l)//DOC FILE TAI KHOAN VA THONG TIN SINH VIEN LUU VAO DANH SACH LIEN KET SINH VIEN
{
	char temp1[1000];//chep chuoi ra tu file
	char temp2[100];//chep chuoi ra tu temp1
	SinhVien* s = l.pHead;
	ifstream file1;
	ifstream file2;
	file1.open("../Project/Tai Khoan/accstudent.csv", ios::in);
	file2.open("../Project/Thong Tin/infostudent.csv", ios::in);
	file1.getline(temp1, 1000);
	file2.getline(temp1, 1000);//bỏ hai dong đầu file text
	while (s != NULL)
	{
		file1.getline(temp1, 1000);
		int k = 0;
		for (int j = 0; 1; j++)
		{
			temp2[j] = temp1[k];
			k++;
			if (temp1[k] == ',')
			{
				k++;
				temp2[j + 1] = '\0';
				s->acc.tenTK = new char[strlen(temp2) + 1];
				strcpy(s->acc.tenTK, temp2);
				break;
			}
		}
		for (int j = 0; 1; j++)
		{
			temp2[j] = temp1[k];
			k++;
			if (temp1[k] == ',')
			{
				k++;
				temp2[j + 1] = '\0';
				s->acc.password = new char[strlen(temp2) + 1];
				strcpy(s->acc.password, temp2);
				break;
			}
		}
		file2.getline(temp1, 1000);
		k = 0;
		for (int j = 0; 1; j++)
		{
			temp2[j] = temp1[k];
			k++;
			if (temp1[k] == ',')
			{
				k++;
				temp2[j + 1] = '\0';
				s->info.MSSV = atoi(temp2);
				break;
			}
		}
		for (int j = 0; 1; j++)
		{
			temp2[j] = temp1[k];
			k++;
			if (temp1[k] == ',')
			{
				k++;
				temp2[j + 1] = '\0';
				s->info.tensv = new char[strlen(temp2) + 1];
				strcpy(s->info.tensv, temp2);
				break;
			}
		}
		for (int j = 0; 1; j++)
		{
			temp2[j] = temp1[k];
			k++;
			if (temp1[k] == ',')
			{
				k++;
				temp2[j + 1] = '\0';
				s->info.lop = new char[strlen(temp2) + 1];
				strcpy(s->info.lop, temp2);
				break;
			}
		}
		for (int j = 0; 1; j++)
		{
			temp2[j] = temp1[k];
			k++;
			if (temp1[k] == ',')
			{
				k++;
				temp2[j + 1] = '\0';
				s->info.gtinh = new char[strlen(temp2) + 1];
				strcpy(s->info.gtinh, temp2);
				break;
			}
		}
		for (int j = 0; 1; j++)
		{
			temp2[j] = temp1[k];
			k++;
			if (temp1[k] == ',')
			{
				k++;
				temp2[j + 1] = '\0';
				s->info.ngsinh = new char[strlen(temp2) + 1];
				strcpy(s->info.ngsinh, temp2);
				break;
			}
		}
		for (int j = 0; 1; j++)
		{
			temp2[j] = temp1[k];
			k++;
			if (temp1[k] == '\0')
			{
				k++;
				temp2[j + 1] = '\0';
				s->info.CCCD = atoi(temp2);
				break;
			}
		}
		s = s->pNext;
	}
	file1.close();
	file2.close();
}





SinhVien* dangnhapSV(listSinhVien& l)// DANG NHAP TAI KHOAN SINH VIEN
{
	SinhVien* temp = l.pHead;
	char name[100];
	char pass[100];
quaylai:
	temp = l.pHead;
	cout << "ten tai khoan (ma so sinh vien) : ";
	cin.getline(name, 100);
	cout << "mat khau : "; cin.getline(pass, 100);
	while (temp != NULL)
	{
		if (strcmp(name, temp->acc.tenTK) == 0 and strcmp(pass, temp->acc.password) == 0)
		{
			system("cls");
			cout << "dang nhap thanh cong" << endl;
			return temp;
		}
		temp = temp->pNext;
	}
	cout << "Dang nhap khong thanh cong" << endl;
	return NULL;
}




void xuatthongtinSV(SinhVien* s)
{
	cout << "Ma so sinh vien : " << s->info.MSSV << endl;
	cout << "Ho va ten : " << s->info.tensv << endl;
	cout << "Lop : " << s->info.lop << endl;
	cout << "Gioi tinh : " << s->info.gtinh << endl;
	cout << "Ngay sinh : " << s->info.ngsinh << endl;
	cout << "Chuc vu : Hoc sinh"  << endl;
	cout << "Can cuoc cong dan : " << s->info.CCCD << endl;
}



SinhVien* taoSV()//TAO RA MOT TAI KHOA SINH VIEN
{
	SinhVien* s = new SinhVien;
	s->pNext = NULL;
	return s;
}







void themDauDSSV(listSinhVien& l)//THEM VAO DAU DANH SACH LIEN KET SINH VIEN
{

	SinhVien* s = taoSV();
	s->pNext = l.pHead;
	l.pHead = s;
}






SinhVien* doiMKSV(SinhVien*& temp, listSinhVien l)//DOI MAT KHAU TAI KHOAN SINH VIEN
{
	SinhVien* acc = l.pHead;
	char pass[100];
	int x;
quaylai:
	cin.ignore();
	cout << "nhap lai mot khau cu : "; cin.getline(pass, 100);
	if (strcmp(pass, temp->acc.password) == 0)
	{
		cout << "nhap mat khau moi : "; cin.getline(pass, 100);
		delete[]temp->acc.password;
		temp->acc.password = new char[strlen(pass) + 1];
		strcpy(temp->acc.password, pass);
		cout << "thay doi mat khau thanh cong." << endl;
		ofstream file;
		file.open("../Project/Tai Khoan/accstudent.csv", ios::out);
		file << "ten tai khoan,mat khau,\n";
		while (acc!=NULL)
		{
			file << acc->acc.tenTK << "," << acc->acc.password << ",\n";
			acc = acc->pNext;
		}
		file.close();
		return temp;
	}
	else
	{
		cout << "thay doi mat khau that bai" << endl;
		cout << "ban co muon nhap lai khong ?" << endl;
		cout << "1.co \t 2. thoat" << endl;
		do
		{
			cin >> x;
		} while (x != 1 and x != 2);
		if (x == 1)
		{
			system("cls");
			goto quaylai;
		}
		else
			return temp;
	}
}






Lop* taoLop()
{
	Lop* temp = new Lop;
	temp->next = NULL;
	return temp;
}


void docFileLop(listLop& l)// DOC FILE LUU DANH SACH LOP HOC DA DUOC TAO TRUOC
{
	ifstream file("../Project/Lop/danh sach lop.csv", ios::in);
	if (file.fail())
		return;
	int n = 0;
	string ch;
	string str;
	while (!file.eof())
	{
		getline(file, str);
		if (!file.eof())
			n++;
	}

	file.close();
	file.open("../Project/Lop/danh sach lop.csv", ios::in);
	getline(file, str);
	l.namhoc = str.substr(0, str.find(","));
	n--;

	for (int i = 0; i < n; i++)
	{
		Lop* temp = taoLop();
		getline(file, str);
	
		temp->tenLop = str.substr(0, str.find(","));
		str = str.substr(str.find(",") + 1, str.length());
	
		temp->khoa = str.substr(0, str.find(","));
		str = str.substr(str.find(",") + 1, str.length());

		temp->top = stoi(str);
		str = str.substr(str.find(",") + 1, str.length());

		temp->soluong = stoi(str);
		str = str.substr(str.find(",") + 1, str.length());

		temp->nam = stoi(str);
		temp->danhsach = new thongtinSV[temp->soluong];

		str ="../Project/Lop/"+ temp->tenLop + ".csv";


		ifstream f(str, ios::in);
		if (f.fail())
			return;
		for (int j = 0; j < temp->top; j++)
		{
			getline(f, str);
			temp->danhsach[j].MSSV = stoi(str);
			str = str.substr(str.find(",") + 1, str.length());

			ch = str.substr(0, str.find(","));
			temp->danhsach[j].tensv = new char[ch.length() + 1];
			strcpy(temp->danhsach[j].tensv, ch.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			ch = str.substr(0, str.find(","));
			temp->danhsach[j].lop = new char[ch.length() + 1];
			strcpy(temp->danhsach[j].lop, ch.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			ch = str.substr(0, str.find(","));
			temp->danhsach[j].gtinh = new char[ch.length() + 1];
			strcpy(temp->danhsach[j].gtinh, ch.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			ch = str.substr(0, str.find(","));

			temp->danhsach[j].ngsinh = new char[ch.length() + 1];
			strcpy(temp->danhsach[j].ngsinh, ch.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			temp->danhsach[j].CCCD = stoi(str);
		}
		f.close();
		temp->next = l.head;
		l.head = temp;
	}
	file.close();
}


void ghiDSLop(listLop l)//CAP NHAT THONG TIN MOI VAO FILE DANH SACH LOP
{
	Lop* temp = l.head;

	ofstream f("../Project/Lop/danh sach lop.csv", ios::out);
	f << l.namhoc << ",\n";
	while (temp != NULL)
	{
		f << temp->tenLop << "," << temp->khoa << "," <<temp->top<<"," << temp->soluong << "," << temp->nam << "\n";
		string str ="../Project/Lop/"+ temp->tenLop + ".csv";
		ofstream file(str, ios::out);
		for (int i = 0; i < temp->top; i++)
			file << temp->danhsach[i].MSSV << "," << temp->danhsach[i].tensv << "," << temp->danhsach[i].lop << "," << temp->danhsach[i].gtinh << "," << temp->danhsach[i].ngsinh << "," << temp->danhsach[i].CCCD << ",\n";

		temp = temp->next;
	}
}

void taoNamHoc(listLop& l)//TAO MOT NAM HOC MOI
{
	cout << "nhap nam hoc (ex : 2020-2021) : ";
	cin.ignore();
	getline(cin, l.namhoc);
	ghiDSLop(l);
}


void taoLopHoc(listLop& l)//TAO MOT LOP MOI
{
	Lop* lop = taoLop();
	cout << "Ten lop : ";
	cin.ignore();
	getline(cin, lop->tenLop);
	inHoa(lop->tenLop);
	cout << "Khoa : ";
	getline(cin, lop->khoa);
	cout << "So luong sinh vien (Max = 50) : ";
	cin >> lop->soluong;
	lop->danhsach = new thongtinSV[lop->soluong];
	lop->nam = stoi(l.namhoc);
	lop->top = 0;
	Lop* temp = l.head;
	while (temp != NULL)
	{
		if (temp->tenLop == lop->tenLop)
			break;
		temp = temp->next;
	}
	if (temp != NULL)
	{
		cout << "tao lop that bai." << endl;
		delete lop;
	}
	else
	{
		cout << "tao lop thanh cong" << endl;
		lop->next = l.head;
		l.head = lop;
		ghiDSLop(l);
	}
}

void xuatDSLop(listLop l)//XUAT RA CAC LOP DA DUOC TAO
{
	Lop* temp = l.head;
	int i = 1;
	cout << setw(10) << left << "stt" << setw(15) << left << "ten lop" << setw(15) << left << "si so" << setw(30) << left << "khoa" << setw(10) << left << "nam" << endl;
	while (temp != NULL)
	{
		cout << setw(10) << left << i << setw(15) << left << temp->tenLop << setw(0) << left << temp->top << "/" << setw(12) << left << temp->soluong << setw(30) << left << temp->khoa << setw(10) << left << temp->nam << endl;
		i++;
		temp = temp->next;
	}
}

void xuatLop(listLop l)//XUAT RA THONG TIN LOP CAN XEM
{
	Lop* temp = l.head;
	cin.ignore();
	cout << "nhap ten lop can xem : ";
	string str;
	getline(cin, str);
	inHoa(str);
	while (temp != NULL)
	{
		if (temp->tenLop == str)
			break;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "khong tim thay thay lop can xem." << endl;

	}
	else {
		system("cls");
		cout << "Lop : " << temp->tenLop << endl;
		cout << "Khoa : " << temp->khoa << endl;
		cout << "Si so : " << temp->top << "/" << temp->soluong << endl;
		cout << "Nam : " << temp->nam << endl;
		cout << endl;

		cout << setw(10) << left << "stt" << setw(15) << left << "MSSV" << setw(30) << left << "ho va ten" << setw(20) << left << "gioi tinh" << setw(20) << left << "ngay sinh" << setw(10) << left << "CCCD" << endl;
		for (int i = 0; i < temp->top; i++)
		{
			cout << setw(10) << left << i + 1 << setw(15) << left << temp->danhsach[i].MSSV << setw(30) << left << temp->danhsach[i].tensv << setw(20) << left << temp->danhsach[i].gtinh << setw(20) << left << temp->danhsach[i].ngsinh << setw(10) << left << temp->danhsach[i].CCCD << endl;
		}
	}
}

void themVaoLopFile(listLop& lop, listSinhVien& l)
{
	Lop* temp = lop.head;
	cin.ignore();
	cout << endl;
	cout << "nhap ten lop can them : ";
	string str;
	getline(cin, str);
	inHoa(str);
	while (temp != NULL)
	{
		if (temp->tenLop == str)
			break;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "khong tim thay thay lop can them." << endl;
		return;
	}
	system("cls");
	cout << "Lop : " << temp->tenLop << endl;
	cout << "Khoa : " << temp->khoa << endl;
	cout << "Si so : " << temp->top << "/" << temp->soluong << endl;
	cout << "Nam : " << temp->nam << endl;
	cout << endl;

	cout << setw(10) << left << "stt" << setw(15) << left << "MSSV" << setw(30) << left << "ho va ten" << setw(20) << left << "gioi tinh" << setw(20) << left << "ngay sinh" << setw(10) << left << "CCCD" << endl;
	for (int i = 0; i < temp->top; i++)
	{
		cout << setw(10) << left << i + 1 << setw(15) << left << temp->danhsach[i].MSSV << setw(30) << left << temp->danhsach[i].tensv << setw(20) << left << temp->danhsach[i].gtinh << setw(20) << left << temp->danhsach[i].ngsinh << setw(10) << left << temp->danhsach[i].CCCD << endl;
	}

	int n = 0;
	cout << endl;
	cout << endl;
	cout << "nhap ten file CSV vao (vd: 22CTT2.csv) : ";
	getline(cin, str);
	ifstream f(str, ios::in);
	string ch;
	if (f.fail())
	{
		cout << "mo file that bai" << endl;
		cout << endl;
		return;
	}
	while (getline(f, ch))
		n++;
	f.close();
	if (n + temp->top > temp->soluong)
	{
		cout << "them sinh vien vao lop that bai" << endl;
		return;
	}
	f.open(str, ios::in);
	
	listSinhVien s;
	s.pHead = NULL;
	for (int i = 0; i < n; i++)
		themDauDSSV(s);
	SinhVien* sv=s.pHead;
	for (int i = temp->top; i < temp->top+n; i++)
	{
		getline(f, str);
		temp->danhsach[i].MSSV = stoi(str);
		sv->info.MSSV = stoi(str);
		str = str.substr(str.find(",") + 1, str.length());
		
		
		ch = str.substr(0, str.find(","));
		temp->danhsach[i].tensv = new char[ch.length() + 1];
		strcpy(temp->danhsach[i].tensv, ch.c_str());
		sv->info.tensv = new char[ch.length() + 1];
		strcpy(sv->info.tensv, ch.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		ch = str.substr(0, str.find(","));
		temp->danhsach[i].lop = new char[ch.length() + 1];
		strcpy(temp->danhsach[i].lop, ch.c_str());
		sv->info.lop = new char[ch.length() + 1];
		strcpy(sv->info.lop, ch.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		ch = str.substr(0, str.find(","));
		temp->danhsach[i].gtinh = new char[ch.length() + 1];
		strcpy(temp->danhsach[i].gtinh, ch.c_str());
		sv->info.gtinh = new char[ch.length() + 1];
		strcpy(sv->info.gtinh, ch.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		ch = str.substr(0, str.find(","));

		temp->danhsach[i].ngsinh = new char[ch.length() + 1];
		strcpy(temp->danhsach[i].ngsinh, ch.c_str());
		sv->info.ngsinh = new char[ch.length() + 1];
		strcpy(sv->info.ngsinh, ch.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		temp->danhsach[i].CCCD = stoi(str);

		sv->info.CCCD = stoi(str);

		ch = to_string(sv->info.MSSV);
		sv->acc.tenTK = new char[ch.length() + 1];
		strcpy(sv->acc.tenTK, ch.c_str());
	    sv->acc.password = new char[4];
		strcpy(sv->acc.password, "123");


		sv = sv->pNext;
		

	}
	temp->top += n;
	
	sv = l.pHead;
	
	
	while (sv != NULL)
	{
		if (sv->pNext == NULL)
		{
			sv->pNext = s.pHead;
			break;
		}
		sv = sv->pNext;
	}
	system("cls");
	cout << "Lop : " << temp->tenLop << endl;
	cout << "Khoa : " << temp->khoa << endl;
	cout << "Si so : " << temp->top << "/" << temp->soluong << endl;
	cout << "Nam : " << temp->nam << endl;
	cout << endl;

	cout << setw(10) << left << "stt" << setw(15) << left << "MSSV" << setw(30) << left << "ho va ten" << setw(20) << left << "gioi tinh" << setw(20) << left << "ngay sinh" << setw(10) << left << "CCCD" << endl;
	for (int i = 0; i < temp->top; i++)
	{
		cout << setw(10) << left << i + 1 << setw(15) << left << temp->danhsach[i].MSSV << setw(30) << left << temp->danhsach[i].tensv << setw(20) << left << temp->danhsach[i].gtinh << setw(20) << left << temp->danhsach[i].ngsinh << setw(10) << left << temp->danhsach[i].CCCD << endl;
	}
	ghifile(l);
	ghiDSLop(lop);
	f.close();
}


void them1SVLop(listLop& l, listSinhVien& s)
{
	Lop* temp = l.head;
	cin.ignore();
	cout << "nhap ten lop can them : ";
	string str;
	getline(cin, str);
	inHoa(str);
	while (temp != NULL)
	{
		if (temp->tenLop == str)
			break;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "khong tim thay thay lop can them." << endl;
		return;
	}

	if (temp->top == temp->soluong)
	{
		cout << "lop da day" << endl;
		return;
	}
	SinhVien* svnew = taoSV();

	cout << "nhap thong tin sinh vien can them vao : " << endl;
	cout << "Ma so sinh vien : ";
	getline(cin, str);

	svnew->acc.tenTK = new char[str.length()+1];
	strcpy(svnew->acc.tenTK, str.c_str());

	svnew->info.MSSV = stoi(str);

	svnew->acc.password = new char[4];
	strcpy(svnew->acc.password, "123");

	cout << "ho va ten : ";
	getline(cin, str);
	svnew->info.tensv = new char[str.length() + 1];
	strcpy(svnew->info.tensv, str.c_str());



	svnew->info.lop = new char[temp->tenLop.length() + 1];
	strcpy(svnew->info.lop, temp->tenLop.c_str());


	cout << "gioi tinh : ";
	getline(cin, str);
	svnew->info.gtinh = new char[str.length() + 1];
	strcpy(svnew->info.gtinh, str.c_str());


	cout << "ngay sinh (vd: 1/1/2004) : ";
	getline(cin, str);
	svnew->info.ngsinh = new char[str.length() + 1];
	strcpy(svnew->info.ngsinh, str.c_str());


	cout << "Can cuoc cong dan : ";
	cin >> svnew->info.CCCD;


	svnew->pNext = s.pHead;
	s.pHead = svnew;
	temp->danhsach[temp->top] = svnew->info;
	temp->top++;
	cout << "them sinh vien thanh cong" << endl;
	ghifile(s);
	ghiDSLop(l);
}






void ghifile(listSinhVien s)//CAP NHAT THONG TIN MOI VAO FILE THONG TIN VA TAI KHOAN SINH VIEN
{
	SinhVien* sv = s.pHead;
	ofstream file1;
	ofstream file2;
	file1.open("../Project/Thong Tin/infostudent.csv", ios::out);
	file2.open("../Project/Tai Khoan/accstudent.csv", ios::out);
	file1 << "MSSV,ho va ten,lop,gioi tinh,ngay sinh,CCCD,\n";
	file2 << "ten tai khoan,mat khau,\n";
	while (sv != NULL)
	{
		file1 << sv->info.MSSV << ","; file1 << sv->info.tensv << ",", file1 << sv->info.lop << ","; file1 << sv->info.gtinh << ","; file1 << sv->info.ngsinh << ","; file1 << sv->info.CCCD << ",\n";
		file2 << sv->acc.tenTK << "," << sv->acc.password << "\n";
		sv = sv->pNext;
	}
	file1.close();
	file2.close();
}





Ngay taoNgay(string str)//TACH CHUOI STRING SANG  CAU TRUC NGAY 
{
	Ngay date = {};
	int i = 0;
	char temp[10];
	while (i < str.length())
	{
		for (int j = 0; 1; j++)
		{
			temp[j] = str[i];
			i++;
			if (str[i] == '/')
			{
				temp[j + 1] = '\0';
				date.ngay = atoi(temp);
				break;
			}
		}
		while (str[i] == '/')
			i++;
		for (int j = 0; 1; j++)
		{
			temp[j] = str[i];
			i++;
			if (str[i] == '/')
			{
				temp[j + 1] = '\0';
				date.thang = atoi(temp);
				break;
			}
		}
		while (str[i] == '/')
			i++;
		for (int j = 0; 1; j++)
		{
			temp[j] = str[i];
			i++;
			if (str[i] == '\0')
			{
				temp[j + 1] = '\0';
				date.nam = atoi(temp);
				break;
			}
		}
	}
	return date;
}

void taoHocKi(Khoahoc& k)// TAO MOT HOC KI MOI
{
	string temp;
	cout << "Hoc ki : "; cin >> k.hocki;
	cout << "Ngay bat dau : "; cin.ignore();
	getline(cin, temp);
	k.batdau = taoNgay(temp);
	cout << "Ngay ket thuc : ";
	getline(cin, temp);
	k.ketthuc = taoNgay(temp);
	ghiFileMonHoc(k);
}


Hocphan* taoMon()//TAO MOT MON HOC RONG
{
	Hocphan *temp = new Hocphan;
	temp->next = NULL;
	return temp;
}

void inHoa(string& str)//INT HOA CAC KI TU TRONG STRING
{
	for (int i = 0; i < str.size(); i++)
		str[i] = towupper(str[i]);
}
void taoMonHoc(Khoahoc& k, listLop lop)//TAO MOT MON HOC DUOC NHAP THONG TIN VAO
{
	Hocphan* mon = taoMon();
	cout << "nhap ma hoc pha : ";
	cin >> mon->MaHP;
	inHoa(mon->MaHP);
	cout << "ten hoc phan : ";
	cin.ignore();
	getline(cin, mon->TenHP);
	inHoa(mon->TenHP);
	cout << "lop : ";
	
	getline(cin, mon->Tenlop);
	inHoa(mon->Tenlop);
	cout << "ten giao vien : ";
	getline(cin, mon->GV);
	cout << "so tin chi : ";
	cin >> mon->tinchi;
	cout << "so luong sinh vien (MAX=50) : ";
	cin >> mon->soluong;
	cout << "thu trong tuan (MON/TUE/WED/THU/FRI/SAT) : ";
	cin.ignore();
	getline(cin, mon->time.thu);
	inHoa(mon->time.thu);
	cout << "tiet bat dau (S1(7:30), S2(9:30), s3(13:30), S4(15:30)) : ";
	getline(cin, mon->time.gioBatDau);
	inHoa(mon->time.gioBatDau);
	cout << "tiet ket thuc (S1(7:30), S2(9:30), s3(13:30), S4(15:30)) : ";
	getline(cin, mon->time.gioKetThuc);
	inHoa(mon->time.gioKetThuc);
	mon->danhsach = new Thongtin[mon->soluong];
	mon->top = 0;
	mon->hki = k.hocki;
	mon->nam = stoi(lop.namhoc);
	
		mon->next = k.HP;
		k.HP = mon;


	

	ghiFileMonHoc(k);
}


int themSVVaoMonHocFile(Khoahoc k, listLop lop)//THEM  SINH VIEN VAO MOT MON HOC DA DUOC TAO TRUOC BANG FILE CSV
{
	Hocphan* hp = k.HP;
	Hocphan* temp1 = k.HP;
	string str;
	cout << setw(10) << left << "stt" << setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << setw(20) << left << "si so" << setw(20) << left << "hoc ki" << setw(20) << left << "nam hoc" << endl;
	int j = 1;
	while (temp1 != NULL)
	{
		if (temp1->nam == stoi(lop.namhoc) and temp1->hki == k.hocki)
		{
			cout << setw(10) << left << j << setw(15) << left << temp1->MaHP << setw(25) << left << temp1->TenHP << setw(15) << left << temp1->Tenlop << setw(25) << left << temp1->GV << setw(20) << left << temp1->tinchi << setw(10) << left << temp1->time.thu << setw(20) << left << temp1->time.gioBatDau << setw(20) << left << temp1->time.gioKetThuc << setw(0) << left << temp1->top << setw(0) << left << "/" << setw(18) << left << temp1->soluong << setw(20) << left << temp1->hki << temp1->nam << " - " << temp1->nam + 1 << endl;
			j++;
		}
		temp1 = temp1->next;
	}
	if (j == 1)
		return 0;
	cout << endl;

	

	cout << "nhap ma hoc phan (0. Thoat) : ";
	cin.ignore();
	getline(cin, str);
	if (str == "0") return 1;
	string str1;
	cout << "nhap ten lop : ";
	getline(cin, str1);
	hp = k.HP;
	while (hp != NULL)
	{
		if (hp->MaHP == str and str1==hp->Tenlop)
			break ;
		hp = hp->next;
	}
	if (hp == NULL)
	{
		cout << "khong tim thay lop." << endl;
		return 1;
	}
	system("cls");
	cout << "Ma hoc phan : " << hp->MaHP << endl;
	cout << "Ten hoc pha : " << hp->TenHP << endl;
	cout << "Lop : " << hp->Tenlop << endl;
	cout << "Giao vien : " << hp->GV << endl;
	cout << "So tinh chi : " << hp->tinchi << endl;
	cout << "Si so : " << hp->top << "/" << hp->soluong << endl;
	cout << endl;
	ifstream file;
		cout << "vui long nhap ten file (ex: 123.csv): ";

		getline(cin, str);
		 file.open(str, ios::in);
		 if (file.fail()) {
			 cout << "khong tim thay file." << endl;
			 return 1;
		 }


	int n = 0;
	while (!file.eof())
	{
		getline(file, str1);
		if (!file.eof())
			n++;
	}
	if (n == 0 || (n+hp->top )> hp->soluong)
	{
		cout << "them danh sach khong thanh cong." << endl;
		return 1;
	}
	file.close();
	file.open(str, ios::in);
	string temp;
	for (int i = hp->top; i < hp->top+n; i++)
	{
		getline(file, str);

		hp->danhsach[i].info.MSSV = stoi(str.substr(0, str.find(",")));
		str = str.substr(str.find(",") + 1, str.length());

		temp = str.substr(0, str.find(","));
		hp->danhsach[i].info.tensv = new char[temp.length() + 1];
		strcpy(hp->danhsach[i].info.tensv, temp.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		temp = str.substr(0, str.find(","));
		hp->danhsach[i].info.lop = new char[temp.length() + 1];
		strcpy(hp->danhsach[i].info.lop, temp.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		temp = str.substr(0, str.find(","));
		hp->danhsach[i].info.gtinh = new char[temp.length() + 1];
		strcpy(hp->danhsach[i].info.gtinh, temp.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		temp = str.substr(0, str.find(","));

		hp->danhsach[i].info.ngsinh = new char[temp.length() + 1];
		strcpy(hp->danhsach[i].info.ngsinh, temp.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		hp->danhsach[i].info.CCCD = stoi(str);

		hp->danhsach[i].diem = {};
	}
	hp->top += n;
	ghiFileMonHoc(k);
	return 0;
}

int xuatKhoaHoc(Khoahoc k)//XUAT TAT CA CAC MON HOC RA MOT DANH SACH VA XEM THONG TIN CHI TIET TUNG MON HOC
{
	cout << "Cac nam hoc :" << endl;
	Hocphan* temp = k.HP;
	int i = 1;
	while (temp != NULL)
	{
		Hocphan* temp1 = k.HP;
		while (1)
		{
			if (temp1 == temp)
			{
				cout << i << ". " << temp->nam <<" - "<<temp->nam+1 << endl;
				i++;
				break;
			}
			if (temp1->nam == temp->nam)
				break;
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
	if (i == 1)
		return 0;
	cout << endl;
	cout << "nhap nam can xem khoa hoc : "; cin >> i;
	system("cls");
	cout << "1. hoc ki 1" << endl;
	cout << "2. hoc ki 2" << endl;
	cout << "3. hoc ki 3" << endl;
	int x;
	cout << endl;
	cout << "nhap hoc ki : " << endl;
	do {
		cin >> x;
	} while (x < 1 || x>3);
	system("cls");
	cout << setw(10) << left << "stt" << setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << setw(20) << left << "si so"  << endl;
	int j = 1;
	temp = k.HP;
	while (temp != NULL)
	{
		if (temp->nam == i and temp->hki == x)
		{
			cout << setw(10) << left << j << setw(15) << left << temp->MaHP << setw(25) << left << temp->TenHP << setw(15) << left << temp->Tenlop << setw(25) << left << temp->GV << setw(20) << left << temp->tinchi << setw(10) << left << temp->time.thu << setw(20) << left << temp->time.gioBatDau << setw(20) << left << temp->time.gioKetThuc << setw(0) << left << temp->top << setw(0) << left << "/" << setw(18) << left<< temp->soluong <<  endl;
			j++;
		}
		temp = temp->next;
	}
	if (j == 1)
		return 0;
	string str;
	int y;
	cout << endl;
	cout << "nhap ma hoc (0. Thoat) : ";
	
	cin.ignore();
	getline(cin, str);
	if (str == "0") return 1;
	cout << "nhap lop : ";
	string str0;
	getline(cin, str0);
	if (str == "0")
		return 1;
	temp = k.HP;
	while (temp != NULL)
	{
		if (temp->MaHP == str and str0==temp->Tenlop)
		{
			do {
				system("cls");
				cout << setw(10) << left << "stt" << setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << endl;
				cout << setw(10) << left << i << setw(15) << left << temp->MaHP << setw(25) << left << temp->TenHP << setw(15) << left << temp->Tenlop << setw(25) << left << temp->GV << setw(20) << left << temp->tinchi << setw(10) << left << temp->time.thu << setw(20) << left << temp->time.gioBatDau << setw(20) << left << temp->time.gioKetThuc << endl;
				cout << endl;
				cout << "1. xem diem" << endl;
				cout << "2. xem thong tin sinh vien." << endl;
				cout << endl;
				cout << "0. quay lai." << endl;
				cout << endl;

				cout << "nhap su lua chon : ";
				do {
					cin >> y;
				} while (y != 1 and y != 2 and y != 0);
				if (y == 0)
					return 1;

				if (y == 2)
					xuatMonHhoc(temp);
				else
					xuatDSDiem(temp);
				cout << endl;
				cout << "0. quay lai" << endl;
				cout << endl; 
				cout << " nhap su lua chon : ";
				do {
					cin >> y;
				} while (y != 0);
			} while (1);
		}
		temp = temp->next;
	}
	cout << "khong tim thay lop co ma hoc phan da nhap ";
	return 0;
}

void xuatMonHhoc(Hocphan *temp)//XUAT THONG TIN LOP HOC
{
	system("cls");
	cout << "Ma hoc phan : " << temp->MaHP<<endl;
	cout << "Ten hoc pha : " << temp->TenHP << endl;
	cout << "Lop : " << temp->Tenlop << endl;
	cout << "Giao vien : " <<temp->GV<< endl;
	cout << "So tinh chi : " << temp->tinchi << endl;
	cout << "Si so : " << temp->top << "/" << temp->soluong << endl;
	cout << "Hoc ki : " << temp->hki << endl;
	cout << "Nam hoc : " << temp->nam << " - " << temp->nam + 1 << endl;
	cout << endl;
	cout << setw(10) << left << "stt" << setw(15) << left << "MSSV" << setw(30) << left << "ho va ten" << setw(20) << left << setw(20) << left <<"lop" << setw(20) << left << "gioi tinh" << setw(20) << left << "ngay sinh" << setw(10) << left << "CCCD" << endl;
	for(int i=0;i<temp->top;i++)
		cout << setw(10) << left << i+1 << setw(15) << left << temp->danhsach[i].info.MSSV << setw(30) << left << temp->danhsach[i].info.tensv << setw(20) << left <<temp->danhsach[i].info.lop<< setw(20) << left << temp->danhsach[i].info.gtinh << setw(20) << left << temp->danhsach[i].info.ngsinh << setw(10) << left << temp->danhsach[i].info.CCCD << endl;
}

void ghiFileMonHoc(Khoahoc k)//CAP NHAT THONG TIN VAO FILE MON HOC
{
	ofstream file("../Project/Mon Hoc/mon hoc.csv");
	file << k.hocki << "," << k.batdau.ngay << "/" << k.batdau.thang << "/" << k.batdau.nam << "," << k.ketthuc.ngay << "/" << k.ketthuc.thang << "/" << k.ketthuc.nam << ",\n";
	Hocphan *h = k.HP;
	while (h != NULL)
	{
		file << h->MaHP << "," << h->TenHP << "," << h->Tenlop << "," << h->GV << "," << h->tinchi << "," << h->top << "," << h->soluong << "," << h->time.gioBatDau << "," << h->time.gioKetThuc << "," << h->time.thu <<","<<h->hki<<","<<h->nam << ",\n";
		h = h->next;
	}
	file.close();
	h = k.HP;
	while (h != NULL)
	{
		string str ="../Project/Mon Hoc/Danh Sach/"+ h->MaHP+"-"+h->Tenlop  + ".csv";
		ofstream file (str, ios::binary);
		for (int i = 0; i < h->top; i++)
			file << h->danhsach[i].info.MSSV << "," << h->danhsach[i].info.tensv << "," << h->danhsach[i].info.lop << "," << h->danhsach[i].info.gtinh << "," << h->danhsach[i].info.ngsinh << "," << h->danhsach[i].info.CCCD << ",\n";
		h = h->next;
		file.close();
	}
	h = k.HP;
	while (h != NULL)
	{
		string str = "../Project/Mon Hoc/Diem/Diem-"+h->MaHP + "-" + h->Tenlop + ".csv";
		ofstream file(str, ios::binary);
		for (int i = 0; i < h->top; i++)
			file << h->danhsach[i].info.MSSV << "," << h->danhsach[i].info.tensv << "," <<h->danhsach[i].diem.giuaki<<","<<h->danhsach[i].diem.cuoiki<<"," << h->danhsach[i].diem.diemtb << ",\n";
		h = h->next;
		file.close();
	}
}

void docFileMonHoc(Khoahoc& k)//DOC FILE MON HOC DE BIET MON HOC NAO DA DUOC TAO
{
	ifstream file("../Project/Mon Hoc/mon hoc.csv", ios::in);
	if (file.fail())
		return;
	int n = 0;
	
	string str;
	string temp;
	while (	!file.eof())
	{
		getline(file, str);
		if(!file.eof())
			n++;
	}

	file.close();
	file.open("../Project/Mon Hoc/mon hoc.csv", ios::in);
	if (n == 1)
	{
		getline(file, str);
		k.hocki = stoi(str);
		str = str.substr(str.find(",") + 1, str.length());
		temp = str.substr(0, str.find(","));
		k.batdau = taoNgay(temp);
		str = str.substr(str.find(",") + 1, str.length());
		k.ketthuc = taoNgay(str);
		return;
	}


	getline(file, str);
	k.hocki = stoi(str);
	str = str.substr(str.find(",") + 1, str.length());
	temp = str.substr(0, str.find(","));
	k.batdau = taoNgay(temp);
	str = str.substr(str.find(",") + 1, str.length());
	temp = str.substr(0, str.find(","));
	k.ketthuc = taoNgay(temp);
	n--;
	for (int i = 0; i < n; i++)
	{
		Hocphan* h = taoMon();
		getline(file, str);
		int x = 0;
		h->MaHP = str.substr(0, str.find(","));
		str = str.substr(str.find(",") + 1, str.length());

		h->TenHP= str.substr(0, str.find(","));
		str = str.substr(str.find(",") + 1, str.length());
		
		h->Tenlop= str.substr(0, str.find(","));
		str = str.substr(str.find(",") + 1, str.length());
		
		h->GV=str.substr(0, str.find(","));
		str = str.substr(str.find(",") + 1, str.length());

		temp = str.substr(0, str.find(","));
		h->tinchi = stoi(temp);
		str = str.substr(str.find(",") + 1, str.length());
	
		temp= str.substr(0, str.find(","));
		h->top = stoi(temp);
		str = str.substr(str.find(",") + 1, str.length());
		
		temp = str.substr(0, str.find(","));
		h->soluong = stoi(temp);
		str = str.substr(str.find(",") + 1, str.length());
		
		

		h->time.gioBatDau= str.substr(0, str.find(","));
		str = str.substr(str.find(",") + 1, str.length());
		h->time.gioKetThuc = str.substr(0, str.find(","));
		str = str.substr(str.find(",") + 1, str.length());
	
		h->time.thu= str.substr(0, str.find(","));
		str = str.substr(str.find(",") + 1, str.length());
		h->hki = stoi(str);

		str = str.substr(str.find(",") + 1, str.length());
		h->nam = stoi(str);
		
		h->danhsach = new Thongtin[h->soluong];

		temp = "../Project/Mon Hoc/Danh Sach/"+h->MaHP+"-"+h->Tenlop + ".csv";


		ifstream file1(temp, ios::in);
		if (file1.fail())
		{
			return;
		}

		for (int j = 0; j < h->top; j++)
		{
			getline(file1, str);
			
			temp = str.substr(0, str.find(","));
			h->danhsach[j].info.MSSV = stoi(temp);
			str = str.substr(str.find(",") + 1, str.length());

			temp = str.substr(0, str.find(","));
			h->danhsach[j].info.tensv = new char[temp.length()+1];
			strcpy(h->danhsach[j].info.tensv, temp.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			temp = str.substr(0, str.find(","));
			h->danhsach[j].info.lop = new char[temp.length() + 1];
			strcpy(h->danhsach[j].info.lop, temp.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			temp = str.substr(0, str.find(","));
			h->danhsach[j].info.gtinh = new char[temp.length() + 1];
			strcpy(h->danhsach[j].info.gtinh, temp.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			temp = str.substr(0, str.find(","));

			h->danhsach[j].info.ngsinh = new char[temp.length() + 1];
			strcpy(h->danhsach[j].info.ngsinh, temp.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			h->danhsach[j].info.CCCD = stoi(str);
		}
		file1.close();
		temp = "../Project/Mon Hoc/Diem/Diem-" + h->MaHP +"-"+h->Tenlop + ".csv";
		file1.open(temp, ios::in);
		if (file1.fail())
			return;
		for (int j = 0; j < h->top; j++)
		{
			getline(file1, str);
			str = str.substr(str.find(",") + 1, str.length());
			str = str.substr(str.find(",") + 1, str.length());
			h->danhsach[j].diem.giuaki = stoi(str);
			str = str.substr(str.find(",") + 1, str.length());
			h->danhsach[j].diem.cuoiki = stoi(str);
			str = str.substr(str.find(",") + 1, str.length());
			h->danhsach[j].diem.diemtb = 0.4 * h->danhsach[j].diem.giuaki + 0.6 * h->danhsach[j].diem.cuoiki;
		}
		if (k.HP == NULL)
			k.HP = h;
		else
		{
			h->next = k.HP;
			k.HP = h;
		}
	}
	ghiFileMonHoc(k);
	file.close();
}

int suaMonHoc(Khoahoc k,listLop lop)//SUA THONG TIN MON HOC
{
	
	cout << setw(10) << left << "stt" << setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << setw(20) << left << "si so" << setw(20) << left << "hoc ki" << setw(20) << left << "nam hoc" << endl;
	int j = 1;
	Hocphan* temp = k.HP;
	while (temp != NULL)
	{
		if (temp->nam == stoi(lop.namhoc) and temp->hki == k.hocki)
		{
			cout << setw(10) << left << j << setw(15) << left << temp->MaHP << setw(25) << left << temp->TenHP << setw(15) << left << temp->Tenlop << setw(25) << left << temp->GV << setw(20) << left << temp->tinchi << setw(10) << left << temp->time.thu << setw(20) << left << temp->time.gioBatDau << setw(20) << left << temp->time.gioKetThuc << setw(0) << left << temp->top << setw(0) << left << "/" << setw(18) << left << temp->soluong << setw(20) << left << temp->hki << temp->nam << " - " << temp->nam + 1 << endl;
			j++;
		}
		temp = temp->next;
	}
	if (j == 1)
		return 0;
	string str;
	cin.ignore();
	cout << endl;
	cout << "nhap ma hoc phan (0. Thoat) : ";
	
	getline(cin,str);
	if (str == "0")
		return 1;
	string str1;
	cout << "nhap ten lop : ";
	getline(cin, str1);
	temp = k.HP;
	while (temp != NULL)
	{
		if (str.compare(temp->MaHP) == 0 and str1.compare(temp->Tenlop)==0)
		{
			break;
		}
		
		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "khong tim thay ma hoc phan." << endl;
		return 0;
	}
	suaMon(temp);
	ghiFileMonHoc(k);
	return 1;
	
}

void suaMon(Hocphan*& temp)
{
	do {
		system("cls");
		cout << "1. Ten hoc phan : " << temp->TenHP << endl;
		cout << "2. Ten lop : " << temp->Tenlop << endl;
		cout << "3. Giao vien : " << temp->GV << endl;
		cout << "4. So tin chi : " << temp->tinchi << endl;
		cout << "5. So luong sinh vien toi da (MAX = 50) : " << temp->soluong << endl;
		cout << "6. Buoi hoc (MON/TUE/WED/THU/FRI/SAT) : " << temp->time.thu << endl;
		cout << "7. Tiet bat dau (S1(7:30), S2(9:30), S3(13:30), S4(15:30)) : " << temp->time.gioBatDau << endl;
		cout << "8. Tiet ket thuc (S1(7:30), S2(9:30), S3(13:30), S4(15:30)) : " << temp->time.gioKetThuc << endl;
		cout << "0.quay lai" << endl;
		int x;
		cout << "Phan ban muon sua lai : ";
		do {
			cin >> x;
		} while (x < 0 || x>9);
		if (x == 0)
			return;
		cin.ignore();
		switch (x)
		{
		case 1:
		{
			cout << "Ten hoc phan : ";
			getline(cin, temp->TenHP);
			break;
		}
		case 2:
		{
			string str = "../Project/Mon Hoc/Danh Sach/" + temp->MaHP + "-" + temp->Tenlop + ".csv";
			remove(str.c_str());
			str = "../Project/Mon Hoc/Danh Sach/Diem-" + temp->MaHP + "-" + temp->Tenlop + ".csv";
			remove(str.c_str());
			cout << "Ten lop : ";
			
			getline(cin, temp->Tenlop);
			inHoa(temp->Tenlop);
			break;
		}
		case 3:
		{
			cout << "Giao vien : ";
			getline(cin, temp->GV);
			break;
		}
		case 4:
		{
			cout << "So tin chi : ";
			cin >> temp->tinchi;
			break;
		}
		case 5:
		{
			cout << "So luong sinh vien toi da : ";
			do {
				cin >> temp->soluong;
			} while (temp->soluong < temp->top);
			break;
		}
		case 6:
		{
			cout << "Buoi hoc : ";
			getline(cin, temp->time.thu);
			inHoa(temp->time.thu);
			break;
		}
		case 7:
		{
			cout << "Tiet bat dau : ";
			getline(cin, temp->time.gioBatDau);
			inHoa(temp->time.gioBatDau);
			break;
		}
		case 8:
		{
			cout << "Tiet ket thuc : ";
			getline(cin, temp->time.gioKetThuc);
			inHoa(temp->time.gioKetThuc);
		}
		}
	} while (1);
}


int themSVMonHoc(Khoahoc& k, listSinhVien l,listLop lop)//THEM SINH VIEN VAO 1 MON HOC
{
	Hocphan* temp = k.HP;
	cout << setw(10) << left << "stt" << setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << setw(20) << left << "si so" << setw(20) << left << "hoc ki" << setw(20) << left << "nam hoc" << endl;
	int j = 1;
	while (temp != NULL)
	{
		if (temp->nam == stoi(lop.namhoc) and temp->hki == k.hocki)
		{
			cout << setw(10) << left << j << setw(15) << left << temp->MaHP << setw(25) << left << temp->TenHP << setw(15) << left << temp->Tenlop << setw(25) << left << temp->GV << setw(20) << left << temp->tinchi << setw(10) << left << temp->time.thu << setw(20) << left << temp->time.gioBatDau << setw(20) << left << temp->time.gioKetThuc << setw(0) << left << temp->top << setw(0) << left << "/" << setw(18) << left << temp->soluong << setw(20) << left << temp->hki << temp->nam << " - " << temp->nam + 1 << endl;
			j++;
		}
		temp = temp->next;
	}
	if (j == 1)
		return 0;
	cout << endl;
	cout << "Nhap Ma Hoc (0. Thoat) : ";
	string str;
	cin.ignore();
	getline(cin, str);
	if (str == "0") return 1;
	string str1;
	cout << "nhap ten lop : ";
	getline(cin, str1);
	temp = k.HP;
	while (temp != NULL)
	{
		if (temp->MaHP == str and temp->Tenlop==str1)
			break;
		
		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "lop khong duoc tim thay" << endl;
		return 0;
	}
	system("cls");
	cout << "Ma hoc phan : " << temp->MaHP << endl;
	cout << "Ten hoc phan : " << temp->TenHP << endl;
	cout << "Ten lop : " << temp->Tenlop << endl;
	cout << "Giao vien : " << temp->GV << endl;
	cout << "So tin chi : " << temp->tinchi << endl;
	cout << "Si so sinh vien : " << temp->top<<"/"<<temp->soluong << endl;

	if (temp->top == temp->soluong)
	{
		cout << "Lop da day khong the them duoc." << endl;
		return 0;
	}

	cout << "Nhap ma so sinh vien can them vao : ";
	SinhVien* sv = l.pHead;
	int x;
	cin >> x;
	while (sv != NULL)
	{
		if (x == sv->info.MSSV)
			break;
		sv = sv->pNext;
	}
	if (sv == NULL)
	{
		cout << "khong tim thay thong tin sinh vien " << endl;
		return 0;
	}
	for (int i = 0; i < temp->top; i++)
	{
		if (temp->danhsach[i].info.MSSV == sv->info.MSSV)
		{
			cout << "sinh vien da co trong lop." << endl;
			return 0;
		}
	}
	
	temp->danhsach[temp->top].info = sv->info;
	temp->top++;
	cout << "them sinh vien vao thanh cong" << endl;
	ghiFileMonHoc(k);
	return 1;
}


int xoa1SVRaKhoiMonHoc(Khoahoc k, listLop  lop)//XOA 1 SINH VIEN RA KHOI 1 MON HOC 
{

	Hocphan* temp = k.HP;
	cout << setw(10) << left << "stt" << setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << setw(20) << left << "si so" << setw(20) << left << "hoc ki" << setw(20) << left << "nam hoc" << endl;
	int j = 1;
	while (temp != NULL)
	{
		if (temp->nam == stoi(lop.namhoc) and temp->hki == k.hocki)
		{
			cout << setw(10) << left << j << setw(15) << left << temp->MaHP << setw(25) << left << temp->TenHP << setw(15) << left << temp->Tenlop << setw(25) << left << temp->GV << setw(20) << left << temp->tinchi << setw(10) << left << temp->time.thu << setw(20) << left << temp->time.gioBatDau << setw(20) << left << temp->time.gioKetThuc << setw(0) << left << temp->top << setw(0) << left << "/" << setw(18) << left << temp->soluong << setw(20) << left << temp->hki << temp->nam << " - " << temp->nam + 1 << endl;
			j++;
		}
		temp = temp->next;
	}
	if (j == 1)
		return 0;
	cout << endl;

	cout << "Nhap Ma Hoc (0. Thoat) : ";
	string str;
	cin.ignore();
	getline(cin, str);
	if (str == "0") return 1;
	string str1;
	cout << "nhap ten lop : ";
	getline(cin, str1);
	temp = k.HP;
	while (temp != NULL)
	{
		if (temp->MaHP == str and temp->Tenlop ==str1)
			break;

		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "lop khong duoc tim thay" << endl;
		return 0;
	}
	xuatMonHhoc(temp);
	if (temp->top == 0)
	{
		cout << endl;
		cout << "lop trong khong the xoa" << endl;
		return 0;
	}
	cout << endl;
	cout << "nhap MSSV can xoa : " << endl;
	int x;
	cin >> x;
	for(int i=0;i<temp->top;i++)
		if (temp->danhsach[i].info.MSSV == x)
		{
			for (int j = i + 1; j < temp->top; j++)
				temp->danhsach[j - 1] = temp->danhsach[j];
			temp->top--;
			system("cls");
			xuatMonHhoc(temp);
			ghiFileMonHoc(k);
			return 1;
		}

	cout << "khong tim thay thong tin sinh vien trong mon hoc." << endl;
	return 0;
}


void xoaKhoaHoc(Khoahoc& k)//XOA DI MOT MON HOC
{
	
	Hocphan* hp = k.HP;
	Hocphan* temp1 = k.HP;
	string str;
	cout << setw(10) << left << "stt" << setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << setw(20) << left << "si so" << setw(20) << left << "hoc ki" << setw(20) << left << "nam hoc" << endl;
	int j = 1;
	while (temp1 != NULL)
	{
		cout << setw(10) << left << j << setw(15) << left << temp1->MaHP << setw(25) << left << temp1->TenHP << setw(15) << left << temp1->Tenlop << setw(25) << left << temp1->GV << setw(20) << left << temp1->tinchi << setw(10) << left << temp1->time.thu << setw(20) << left << temp1->time.gioBatDau << setw(20) << left << temp1->time.gioKetThuc << setw(0) << left << temp1->top << setw(0) << left << "/" << setw(18) << left << temp1->soluong << setw(20) << left << temp1->hki << temp1->nam << " - " << temp1->nam + 1 << endl;
			j++;
		temp1 = temp1->next;
	}
	if (j == 1)
		return ;
	cout << endl;
	cout << "nhap ma hoc phan (0. Thoat): ";
	cin.ignore();
	getline(cin, str);
	if (str == "0") return ;
	string str1;
	cout << "nhap ten lop : ";
	getline(cin, str1);
	hp = k.HP;
	while (hp != NULL)
	{
		if (hp->MaHP == str and hp->Tenlop==str1)
			break;
		hp = hp->next;
	}
	if (hp == NULL)
	{
		cout << "khong thay ma hoc phan." << endl;
		return;
	}
	str = "../Project/Mon Hoc/Danh Sach/"+hp->MaHP +"-" + hp->Tenlop + ".csv";
	remove(str.c_str());
	str = "../Project/Mon Hoc/Diem/Diem-" + hp->MaHP +"-"+hp->Tenlop + ".csv";
	remove(str.c_str());
	if (k.HP == hp)
	{
		k.HP = hp->next;
		delete hp;
		ghiFileMonHoc(k);
		return;
	}
	Hocphan* temp = k.HP;
	while (temp != NULL)
	{
		if (temp->next == hp)
		{
			temp->next = hp->next;
			delete hp;
		}
		temp = temp->next;
	}
	ghiFileMonHoc(k);
}

void xuatDSDiem(Hocphan *temp)//XUAT DANH SACH DIEM CUA SINH VIEN TRONG 1 MON HOC
{
	system("cls");
	cout << "Ma hoc phan : " << temp->MaHP << endl;
	cout << "Ten hoc phan : " << temp->TenHP << endl;
	cout << "Lop : " << temp->Tenlop << endl;
	cout << "Giao vien : " << temp->GV << endl;
	cout << "So tinh chi : " << temp->tinchi << endl;
	cout << "Si so : " << temp->top << "/" << temp->soluong << endl;
	cout << endl;
	cout << setw(10) << left << "stt" << setw(15) << left << "MSSV" << setw(30) << left << "ho va ten" << setw(15) << left << "diem giua ki" << setw(15) << left << "cuoi ki" << setw(15) << left << "diem trung binh"  << endl;
	for (int i = 0; i < temp->top; i++)
		cout << setw(10) << left << i + 1 << setw(15) << left << temp->danhsach[i].info.MSSV << setw(30) << left << temp->danhsach[i].info.tensv << setw(15) << left << temp->danhsach[i].diem.giuaki << setw(15) << left << temp->danhsach[i].diem.cuoiki << setw(15) << left << temp->danhsach[i].diem.diemtb <<  endl;
}



void svxemThongTinLop(Khoahoc k, SinhVien* sv)//XEM THONG TIN CUA 1 SINH VIEN DUOC DANG KI TRONG CAC MON HOC
{
	Hocphan* temp = k.HP;
	cout << setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << setw(20) << left << "si so" << setw(20) << left << "hoc ki" << setw(20) << left << "nam hoc" << endl;
	while (temp != NULL)
	{
		for (int i = 0; i < temp->top; i++)
			if (sv->info.MSSV == temp->danhsach[i].info.MSSV)
			{
				cout <<setw(15) << left << temp->MaHP << setw(25) << left << temp->TenHP << setw(15) << left << temp->Tenlop << setw(25) << left << temp->GV << setw(20) << left << temp->tinchi << setw(10) << left << temp->time.thu << setw(20) << left << temp->time.gioBatDau << setw(20) << left << temp->time.gioKetThuc << setw(0) << left << temp->top << setw(0) << left << "/" << setw(18) << left << temp->soluong << setw(20) << left << temp->hki << temp->nam << " - " << temp->nam + 1 << endl;
				 break;
			}
		temp = temp->next;
	}
}

void svxemDiem(Khoahoc k, SinhVien* sv)// XEM DIEM CUA 1 SINH VIEN TRONG CAC MON HOC
{
	float sum = 0;
	int heso = 0;
	Hocphan* temp = k.HP;
	cout<< setw(15) << left << "Ma hoc phan" << setw(30) << left << "Ten hoc phan" << setw(15) << left<<"hoc ki"<<setw(20) << left<<"nam hoc"<< setw(15) << left << "diem giua ki" << setw(15) << left << "cuoi ki" << setw(15) << left << "diem trung binh" << endl;
	while (temp != NULL)
	{
		for (int i = 0; i < temp->top; i++)
			if (sv->info.MSSV == temp->danhsach[i].info.MSSV)
			{
				cout <<setw(15) << left << temp->MaHP << setw(30) << left << temp->TenHP << setw(15) << left << temp->hki << setw(0) << left << temp->nam<<" - "<<  setw(13) << left<<temp->nam+1<< setw(15) << left << temp->danhsach[i].diem.giuaki << setw(15) << left << temp->danhsach[i].diem.cuoiki << setw(15) << left << temp->danhsach[i].diem.diemtb << endl;
				sum += temp->danhsach[i].diem.diemtb*temp->tinchi;
				heso += temp->tinchi;
				break;
			}
		temp = temp->next;
	}
	float diemtb_all;
	if (heso != 0)
	{
		diemtb_all = sum / heso;
	}
	else
	{
		diemtb_all = 0;
	}
	cout << endl;
	cout << "diem trung binh hoc ki cac mon : " << diemtb_all << endl;

}