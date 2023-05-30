#include"student.h"


void demsoluongsv(list& l)//dem so luong sinh vien trong file csv
{
	char temp[10000];
	ifstream file;
	file.open("accstudent.csv", ios::in);
	if (file.fail() == true)
		cout << "mo file khon thanh cong";
	file.getline(temp, 1000);
	while (file.getline(temp, 1000))
	{
		themDauDSSV(l);
	}
	file.close();
}


void docfileSV(list& l)
{
	char temp1[1000];//chep chuoi ra tu file
	char temp2[100];//chep chuoi ra tu temp1
	student* s = l.pHead;
	ifstream file1;
	ifstream file2;
	file1.open("accstudent.csv", ios::in);
	file2.open("infostudent.csv", ios::in);
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
			if (temp1[k] == ',')
			{
				k++;
				temp2[j + 1] = '\0';
				s->info.chucvu = new char[strlen(temp2) + 1];
				strcpy(s->info.chucvu, temp2);
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



void dangkiSV(list& l,classroom*lop)
{
	student* s = l.pHead;
	char temp2[100];// bien de tao mang dong
	student* temp = creatstudent();//them sinh vien moi vao
	ofstream file1;
	ofstream file2;
	file1.open("infostudent.csv", ios::app);
	file2.open("accstudent.csv", ios::app);
nhaplai :
	cout << "Ma so sinh vien : ";
	cin.getline(temp2, 100);
	while (s != NULL)
	{
		if (strcmp(temp2, s->acc.tenTK) == 0)
		{
			s = l.pHead;
			goto nhaplai;
		}
		s = s->pNext;
	}
	temp->acc.tenTK = new char[strlen(temp2) + 1];
	strcpy(temp->acc.tenTK, temp2);
	file2 << temp->acc.tenTK << ",";

	strcpy(temp2, "123");
	temp->acc.password = new char[strlen(temp2) + 1];
	strcpy(temp->acc.password, temp2);
	file2 << temp->acc.password << ",\n";

	temp->info.MSSV = atoi(temp->acc.tenTK);
	file1 << temp->info.MSSV << ",";

	cout << "Ho va ten : ";
	cin.getline(temp2, 100);
	temp->info.tensv = new char(strlen(temp2) + 1);
	strcpy(temp->info.tensv, temp2);
	vietHoaTen(temp->info.tensv);
	file1 << temp->info.tensv << ",";

	temp->info.lop = new char(strlen(lop->tenlop) + 1);
	strcpy(temp->info.lop, lop->tenlop);
	file1 << temp->info.lop<< ",";

	cout << "Gioi tinh : "; cin.getline(temp2, 100);
	temp->info.gtinh = new char(strlen(temp2) + 1);
	strcpy(temp->info.gtinh, temp2);
	file1 << temp->info.gtinh << ",";

	cout << "Ngay sinh (xx/xx/xxxx) : "; cin.getline(temp2, 100);
	temp->info.ngsinh = new char(strlen(temp2) + 1);
	strcpy(temp->info.ngsinh, temp2);
	file1 << temp->info.ngsinh << ",";

	strcpy(temp2, "hoc sinh");
	temp->info.chucvu = new char(strlen(temp2) + 1);
	strcpy(temp->info.chucvu, temp2);
	file1 << temp->info.chucvu << ",";

	cout << "Ma dinh danh cccd (9 so): ";
	do {
		cin >> temp->info.CCCD;
	} while (temp->info.CCCD < 100000000 || temp->info.CCCD>999999999);
	file1 << temp->info.CCCD << ",\n";

	if (l.pHead == NULL)
	{
		l.pHead = temp;
	}
	else
	{
		s = l.pHead;
		while (s != NULL)
		{
			if (s->pNext == NULL)
			{
				s->pNext = temp;
				break;
			}
			s = s->pNext;
		}
	}
	file1.close();
	file2.close();
}



student* dangnhapSV(list& l)
{
	student* temp = l.pHead;
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




void xuatthongtinSV(student* s)
{
	cout << "Ma so sinh vien : " << s->info.MSSV << endl;
	cout << "Ho va ten : " << s->info.tensv << endl;
	cout << "Lop : " << s->info.lop << endl;
	cout << "Gioi tinh : " << s->info.gtinh << endl;
	cout << "Ngay sinh : " << s->info.ngsinh << endl;
	cout << "Chuc vu : " << s->info.chucvu << endl;
	cout << "Can cuoc cong dan : " << s->info.CCCD << endl;
}



student* creatstudent()
{
	student* s = new student;
	s->pNext = NULL;
	return s;
}



void GanNULLSV(list& l)
{
	l.pHead = NULL;
}



void themDauDSSV(list& l)
{

	student* s = creatstudent();
	s->pNext = l.pHead;
	l.pHead = s;
}



void vietHoaTen(char s[])
{
	s[0] = toupper(s[0]);
	for (int i = 1; i < strlen(s); i++)
	{
		if (s[i - 1] == ' ')
		{
			s[i] = toupper(s[i]);
			continue;
		}
		s[i] = towlower(s[i]);
	}
}



student* doiMatKhau(student*& temp, list l)
{
	student* acc = l.pHead;
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
		file.open("accstudent.csv", ios::out);
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



void dslop(list s, classroom* &lop, int& n)
{
	int i = 1;
	student* t1 = s.pHead;
	student* t2;
	while (t1 != NULL)
	{
		t2 = s.pHead;
		while (t1 != t2)
		{
			if (strcmp(t1->info.lop, t2->info.lop) == 0)
				break;
			if (t2->pNext == t1)
				i++;
			t2 = t2->pNext;
		}
		t1 = t1->pNext;
	}
	lop = new classroom[i];
	n = i;
	i = 0;
	t1 = s.pHead;
	if (t1 == NULL)
	{
		cout << i;
		return;
	}
	strcpy(lop[0].tenlop,t1->info.lop);
	i = 1;
	while (t1 != NULL)
	{
		t2 = s.pHead;
		while (t1 != t2)
		{
			if (strcmp(t1->info.lop, t2->info.lop) == 0)
				break;
			if (t2->pNext == t1)
			{
				strcpy(lop[i].tenlop, t1->info.lop);
				i++;
			}
			t2 = t2->pNext;
		}
		t1 = t1->pNext;
	}
	
	for (int i = 0; i < n; i++)
	{
		lop[i].n = 0;
		t1 = s.pHead;
		while (t1 != NULL)
		{
			if (strcmp(lop[i].tenlop, t1->info.lop) == 0)
			{
				lop[i].n++;
			}
			t1 = t1->pNext;
		}
		if (strstr(lop[i].tenlop, "CTT"))
		{
			strcpy(lop[i].nganh, "Cong nghe thong tinh");
		}
		lop[i].nam = 2000 + atoi(lop[i].tenlop);
	}
	
}





int taonamhoc(int& namhoc)
{
	char temp[20];
	cout << "tao nam hoc (vd: 2020-2021) : "; 
nhaplai:
	cin >> temp;
	if (strcmp(temp, "2022-2023") != 0)
	{
		system("cls");
		cout << "tao nam hoc khong thanh cong." << endl;
		cout << "vui long nhap lai : ";
		goto nhaplai;
	}
	cout << "tao nam hoc thanh cong" << endl;
	namhoc = atoi(temp);
	return namhoc;
}



void taolop(list s,classroom* &lop,int namhoc)
{
	lop = new classroom;
	cout << "ten lop hoc : ";
	cin >> lop->tenlop;
	_strupr(lop->tenlop);
	cout << "Nganh hoc :";
	cin.ignore();
	cin.getline(lop->nganh, 30);
	cout << "so luong sinh vien (MAX = 50) : "; 
	do {
		cin >> lop->n;
	} while (lop->n < 1 || lop->n>50);
	student* temp1 = s.pHead;
	while (temp1!=NULL)
	{
		if (strcmp(temp1->info.lop, lop->tenlop) == 0)
		{
			cout << "Tao lop khong thanh cong." << endl;
			delete lop;
			lop = NULL;
			return;
		}
		temp1 = temp1->pNext;
	}
	cout << "tao lop thanh cong." << endl;
}

void nhaptay(list s, classroom* lop)
{
	system("cls");;
	for (int i = 0; i < lop->n; i++)
	{
		dangkiSV(s, lop);
	}
}

void nhapfile(list s, classroom* lop)
{
	system("cls");
	char temp[100];
	cout << "nhap file can them danh sach sinh vien vao (vd: 22CCT1.csv) : ";
nhaplai:
	cin >> temp;
	ifstream file;
	file.open(temp, ios::in);
	if (file.fail() == true)
	{
		cout << "Mo file khong thanh cong.Vui long nhap lai ten file.";
		goto nhaplai;
	}
	
	list l;
	l.pHead = NULL;
	for (int i = 0; i < lop->n; i++)
		themDauDSSV(l);
	student* sv = l.pHead;
	char temp1[1000];
	char temp2[100];
	int k = 0;
	while (sv != NULL)
	{
		k = 0;
		file.getline(temp1, 1000);
		for (int j = 0; 1; j++)
		{
			temp2[j] = temp1[k];
			k++;
			if (temp1[k] == ',')
			{
				k++;
				temp2[j + 1] = '\0';
				sv->acc.tenTK = new char[strlen(temp2) + 1];
				strcpy(sv->acc.tenTK, temp2);
				sv->info.MSSV = atoi(sv->acc.tenTK);
				strcpy(temp2, "123");
				sv->acc.password = new char[strlen(temp2) + 1];
				strcpy(sv->acc.password, temp2);
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
				sv->info.tensv = new char[strlen(temp2) + 1];
				strcpy(sv->info.tensv, temp2);
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
				sv->info.gtinh = new char[strlen(temp2) + 1];
				strcpy(sv->info.gtinh, temp2);
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
				sv->info.ngsinh = new char[strlen(temp2) + 1];
				strcpy(sv->info.ngsinh, temp2);
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
				sv->info.CCCD = atoi(temp2);
				break;
			}
		}
		strcpy(temp2, lop->tenlop);
		sv->info.lop = new char[strlen(temp2) + 1];
		strcpy(sv->info.lop, temp2);

		strcpy(temp2, "hoc sinh");
		sv->info.chucvu = new char[strlen(temp2) + 1];
		strcpy(sv->info.chucvu, temp2);

		sv = sv->pNext;
	}
	
	file.close();

	ofstream file1;
	ofstream file2;
	ofstream file3;
	strcpy(temp, lop->tenlop);
	strcat(temp, ".csv");
	file3.open(temp, ios::out);
	sv = l.pHead;
	while (sv != NULL)
	{
		file3 << sv->info.MSSV << ","; file3 << sv->info.tensv << ",", file3 << sv->info.lop << ","; file3 << sv->info.gtinh << ","; file3 << sv->info.ngsinh << ","; file3 << sv->info.CCCD << ",\n";
		sv = sv->pNext;
	}
	file3.close();
	file1.open("infostudent.csv", ios::out);
	file2.open("accstudent.csv", ios::out);

	sv = s.pHead;
	while (sv!=NULL)
	{
		if (sv->pNext == NULL)
		{
			sv->pNext = l.pHead;
			break;
		}
		sv = sv->pNext;
	}
	sv = s.pHead;
	file1 << "MSSV,ho va ten,lop,gioi tinh,ngay sinh,chuc vu,CCCD,\n";
	file2 << "ten tai khoan,mat khau,\n";
	while (sv != NULL)
	{
		file1 << sv->info.MSSV << ","; file1 << sv->info.tensv << ",", file1 << sv->info.lop << ","; file1 << sv->info.gtinh << ","; file1 << sv->info.ngsinh << ","; file1 << sv->info.chucvu << ","; file1 << sv->info.CCCD << ",\n";
		file2 << sv->acc.tenTK << "," << sv->acc.password << "\n";
		sv = sv->pNext;
	}
	cout << "them danh sach thann cong." << endl;
	file1.close();
	file2.close();
}


void xuatlop(classroom* lop, int n, list s)
{
	student* sv = s.pHead;
	cout << setw(10) << left << "stt" << setw(15) << left << "ten lop" <<setw(15)<<left<<"so luong" << setw(30) << left << "chuyen nganh" << setw(10) << left << "nam" << endl;
	for (int i = 0; i < n; i++)
		cout << setw(10) << left << i << setw(15) << left << lop[i].tenlop << setw(15) << left <<lop[i].n<< setw(30) << left << lop[i].nganh << setw(10) << left << lop[i].nam << endl;
	cout << "nhap lop can xem : ";
	int x;
	do {
		cin >> x;
	} while (x < 0 || x > n);
	system("cls");
	int i = 0;
	cout << setw(10) << left << "stt" << setw(15) << left << "MSSV" << setw(30) << left << "ho va ten" << setw(20) << left << "gioi tinh" << setw(20) << left << "ngay sinh" << setw(10) << left << "CCCD" << endl;
	while (sv != NULL)
	{
		if (strcmp(lop[x].tenlop, sv->info.lop) == 0)
		{
			cout<<setw(10)<<left<<i<< setw(15) << left << sv->info.MSSV << setw(30) << left << sv->info.tensv << setw(20) << left << sv->info.gtinh << setw(20) << left<<sv->info.ngsinh<< setw(10) << left<<sv->info.CCCD<< endl;
			i++;
		}
		sv = sv->pNext;
	}
}


void them1SV(list &s)
{
	char temp[20];
	cout << "nhap lop can them sinh vien : "; cin >> temp;
	_strupr(temp);
	student* sv = s.pHead;
	int i = 0;
	while (sv != NULL)
	{
		if (strcmp(temp, sv->info.lop) == 0)
		{
			i = 1;
			break;
		}
		sv = sv->pNext;
	}
	if (i == 0) {
		cout << "khong tim thay lop" << endl;
		return;
	}
	system("cls");
	cout << "nhap thong tin sinh vien." << endl;
	student* sv1 = creatstudent();

	sv1->info.lop = new char[strlen(temp) + 1];
	strcpy(sv1->info.lop, temp);

	strcat(temp, ".csv");
	ofstream file;
	file.open(temp, ios::out);

	strcpy(temp, "hoc sinh");
	sv1->info.chucvu = new char[strlen(temp) + 1];
	strcpy(sv1->info.chucvu, temp);

	cout << "MSSV : ";
	do {
		cin >> temp;
	} while (atoi(temp) < 10000000 || atoi(temp) > 99999999);

	sv1->acc.tenTK = new char[strlen(temp) + 1];
	strcpy(sv1->acc.tenTK, temp);

	sv1->info.MSSV = atoi(temp);

	sv1->acc.password = new char[4];
	strcpy(sv1->acc.password, "123");

	cout << "ho va ten : ";
	cin.ignore();
	cin.getline(temp, 100);
	_strupr(temp);
	sv1->info.tensv = new char[strlen(temp) + 1];
	strcpy(sv1->info.tensv, temp);

	cout << "gioi tinh : ";
	do {
		cin >> temp;
	} while (strcmp(temp, "nam") != 0 and strcmp(temp, "nu") != 0);
	sv1->info.gtinh = new char[strlen(temp) + 1];
	strcpy(sv1->info.gtinh, temp);

	cout << "ngay sinh (vd : 01/01/1999) : ";
	cin >> temp;
	sv1->info.ngsinh = new char[strlen(temp) + 1];
	strcpy(sv1->info.ngsinh, temp);

	cout << "can cuoc cong dan : ";
	do {
		cin >> temp;
	} while (atoi(temp) < 100000000 || atoi(temp) > 999999999);
	sv1->info.CCCD = atoi(temp);

	sv = s.pHead;
	while (sv != NULL)
	{
		if (sv->pNext->info.MSSV > sv1->info.MSSV)
		{
			sv1->pNext = sv->pNext;
			sv->pNext = sv1;
			break;
		}
		sv = sv->pNext;
	}
	sv = s.pHead;
	while (sv != NULL)
	{
		if (strcmp(sv1->info.lop, sv->info.lop) == 0)
		{
			file << sv->info.MSSV << ","; file << sv->info.tensv << ",", file << sv->info.lop << ","; file << sv->info.gtinh << ","; file << sv->info.ngsinh <<","; file << sv->info.CCCD << ",\n";
		}
		sv = sv->pNext;
	}
	file.close();
	ghifile(s);
}

void ghifile(list s)
{
	student* sv = s.pHead;
	ofstream file1;
	ofstream file2;
	file1.open("infostudent.csv", ios::out);
	file2.open("accstudent.csv", ios::out);
	file1 << "MSSV,ho va ten,lop,gioi tinh,ngay sinh,chuc vu,CCCD,\n";
	file2 << "ten tai khoan,mat khau,\n";
	while (sv != NULL)
	{
		file1 << sv->info.MSSV << ","; file1 << sv->info.tensv << ",", file1 << sv->info.lop << ","; file1 << sv->info.gtinh << ","; file1 << sv->info.ngsinh << ","; file1 << sv->info.chucvu << ","; file1 << sv->info.CCCD << ",\n";
		file2 << sv->acc.tenTK << "," << sv->acc.password << "\n";
		sv = sv->pNext;
	}
	file1.close();
	file2.close();
}

void xoa1SV(list& s)
{
	int id;
	char lop[100];
	cout << "nhap ma so sinh vien can xoa : ";
	cin >> id;
	student* sv = s.pHead;
	while (sv != NULL)
	{
		if (id == sv->info.MSSV)
			break;
		if (sv->pNext == NULL)
		{
			cout << "khong tim thay sinh vien can xoa." << endl;
			return;
		}
		sv = sv->pNext;
	}
	if (s.pHead == NULL)
		return;
	sv = s.pHead;
	if (s.pHead==sv and sv->info.MSSV == id)
	{
		sv = s.pHead;
		s.pHead = s.pHead->pNext;
		delete sv;
		cout << "xoa thanh cong." << endl;
		return;
	}
	while (sv != NULL)
	{
		if (sv->pNext->info.MSSV == id)
		{
			student* temp = sv->pNext;
			strcpy(lop, temp->info.lop);
			sv->pNext = temp->pNext;
			delete temp;
			cout << "xoa thanh cong" << endl;
			break;
		}
		sv = sv->pNext;
	}
	ghifile(s);
	sv = s.pHead;
	strcat(lop, ".csv");
	ofstream file;
	file.open(lop, ios::out);
	for (int i = 0; i < strlen(lop); i++)
	{
		if (lop[i] == '.')
		{
			lop[i] = '\0';
			break;
		}
	}
	while (sv != NULL)
	{
		if (strcmp(lop, sv->info.lop) == 0)
		{
			file << sv->info.MSSV << ","; file << sv->info.tensv << ",", file << sv->info.lop << ","; file << sv->info.gtinh << ","; file << sv->info.ngsinh << ","; file << sv->info.CCCD << ",\n";
		}
		sv = sv->pNext;
	}
	file.close();
}




Ngay taoNgay(string str) {
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

void taoHocKi(Khoahoc& k)
{
	string temp;
	cout << "Hoc ki : "; cin >> k.hocki;
	cout << "Ngay bat dau : "; cin.ignore();
	getline(cin, temp);
	k.batdau = taoNgay(temp);
	cout << "Ngay ket thuc : ";
	getline(cin, temp);
	k.ketthuc = taoNgay(temp);
	k.HP = NULL;
	ghiFileMonHoc(k);
}


Hocphan* taoMon()
{
	Hocphan *temp = new Hocphan;
	temp->next = NULL;
	return temp;
}

void inHoa(string& str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = towupper(str[i]);
}
void taoMonHoc(Khoahoc& k)
{
	Hocphan* mon = taoMon();
	cout << "nhap ma hoc pha : ";
	cin >> mon->MaHP;
	inHoa(mon->MaHP);
	cout << "ten hoc phan : ";
	cin.ignore();
	getline(cin, mon->TenHP);
	cout << "lop : ";
	
	getline(cin, mon->Tenlop);
	inHoa(mon->Tenlop);
	cout << "ten giao vien : ";
	getline(cin, mon->GV);
	cout << "so tin chi : ";
	cin >> mon->tinchi;
	cout << "so luong sinh vien (MAX=50) : ";
	cin >> mon->soluong;
	cout << "thu trong tuan : ";
	cin.ignore();
	getline(cin, mon->time.thu);
	inHoa(mon->time.thu);
	cout << "tiet bat dau: ";
	getline(cin, mon->time.gioBatDau);
	inHoa(mon->time.gioBatDau);
	cout << "tiet ket thuc : ";
	getline(cin, mon->time.gioKetThuc);
	inHoa(mon->time.gioKetThuc);
	mon->danhsach = new infostudent[mon->soluong];
	mon->top = 0;
	if (k.HP == NULL)
	{
		k.HP = mon;
	}
	else
	{
		mon->next = k.HP;
		k.HP = mon;
	}


	

	ghiFileMonHoc(k);
}


int themSVVaoMonHoc(Khoahoc k)
{
	Hocphan* hp = k.HP;
	int i = 1;
	cout << setw(10) << left << "stt" << setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << endl;
	while (hp != NULL)
	{
		cout << setw(10) << left << i << setw(15) << left << hp->MaHP << setw(25) << left << hp->TenHP << setw(15) << left << hp->Tenlop << setw(25) << left << hp->GV << setw(20) << left << hp->tinchi << setw(10) << left << hp->time.thu << setw(20) << left << hp->time.gioBatDau << setw(20) << left << hp->time.gioKetThuc << endl;
		hp = hp->next;
		i++;
	}

	string str;

	cout << "nhap ma hoc phan lop can them vao : ";
	cin.ignore();
	getline(cin, str);
	hp = k.HP;
	while (hp != NULL)
	{
		if (hp->MaHP == str)
			break;
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
	do {
		cout << "vui long nhap ten file (ex: 123.csv): ";

		getline(cin, str);
		 file.open(str, ios::in);
		 if(file.fail())
		cout << "khong tim thay file." << endl;
		 cout << endl;
	} while (file.fail());
	string str1;
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

		hp->danhsach[i].MSSV = stoi(str.substr(0, str.find(",")));
		str = str.substr(str.find(",") + 1, str.length());

		temp = str.substr(0, str.find(","));
		hp->danhsach[i].tensv = new char[temp.length() + 1];
		strcpy(hp->danhsach[i].tensv, temp.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		temp = str.substr(0, str.find(","));
		hp->danhsach[i].lop = new char[temp.length() + 1];
		strcpy(hp->danhsach[i].lop, temp.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		temp = str.substr(0, str.find(","));
		hp->danhsach[i].gtinh = new char[temp.length() + 1];
		strcpy(hp->danhsach[i].gtinh, temp.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		temp = str.substr(0, str.find(","));

		hp->danhsach[i].ngsinh = new char[temp.length() + 1];
		strcpy(hp->danhsach[i].ngsinh, temp.c_str());
		str = str.substr(str.find(",") + 1, str.length());

		hp->danhsach[i].CCCD = stoi(str);
	}
	hp->top += n;
	ghiFileMonHoc(k);
	return 0;
}

void xuatKhoaHoc(Khoahoc k)
{
	Hocphan* temp = k.HP;
	int i = 1;
	cout << setw(10) << left<<"stt" <<setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << endl;
	while (temp != NULL)
	{
		cout<< setw(10) << left << i << setw(15) << left << temp->MaHP << setw(25) << left << temp->TenHP << setw(15) << left << temp->Tenlop << setw(25) << left << temp->GV << setw(20) << left << temp->tinchi << setw(10) << left << temp->time.thu << setw(20) << left << temp->time.gioBatDau<< setw(20) << left <<temp->time.gioKetThuc << endl;
		temp = temp->next;
		i++;
	}
	if (i == 1)
		return;
	string str;
	cout << endl;

	cout << "nhap ma hoc phan lop muon xem : ";
	cin.ignore();
	getline(cin, str);

	temp = k.HP;
	while (temp != NULL)
	{
		if (temp->MaHP==str)
		{
			xuatMonHhoc(temp);
			return;
		}
		temp = temp->next;
	}
	cout << "khong tim thay lop co ma hoc phan da nhap ";

}

void xuatMonHhoc(Hocphan *h)
{
	system("cls");
	cout << "Ma hoc phan : " << h->MaHP<<endl;
	cout << "Ten hoc pha : " << h->TenHP << endl;
	cout << "Lop : " << h->Tenlop << endl;
	cout << "Giao vien : " <<h->GV<< endl;
	cout << "So tinh chi : " << h->tinchi << endl;
	cout << "Si so : " << h->top << "/" << h->soluong << endl;
	cout << endl;
	cout << setw(10) << left << "stt" << setw(15) << left << "MSSV" << setw(30) << left << "ho va ten" << setw(20) << left << setw(20) << left <<"lop" << setw(20) << left << "gioi tinh" << setw(20) << left << "ngay sinh" << setw(10) << left << "CCCD" << endl;
	for(int i=0;i<h->top;i++)
		cout << setw(10) << left << i+1 << setw(15) << left << h->danhsach[i].MSSV << setw(30) << left << h->danhsach[i].tensv << setw(20) << left <<h->danhsach[i].lop<< setw(20) << left << h->danhsach[i].gtinh << setw(20) << left << h->danhsach[i].ngsinh << setw(10) << left << h->danhsach[i].CCCD << endl;
}

void ghiFileMonHoc(Khoahoc k)
{
	ofstream file("mon hoc.csv");
	file << k.hocki << "," << k.batdau.ngay << "/" << k.batdau.thang << "/" << k.batdau.nam << "," << k.ketthuc.ngay << "/" << k.ketthuc.thang << "/" << k.ketthuc.nam << ",\n";
	Hocphan *h = k.HP;
	while (h != NULL)
	{
		file << h->MaHP << "," << h->TenHP << "," << h->Tenlop << "," << h->GV << "," << h->tinchi << "," << h->top << "," << h->soluong << "," << h->time.gioBatDau << "," << h->time.gioKetThuc << "," << h->time.thu << ",\n";
		h = h->next;
	}
	file.close();
	h = k.HP;
	while (h != NULL)
	{
		string str = h->MaHP+".csv";
		ofstream file (str, ios::binary);
		for (int i = 0; i < h->top; i++)
			file << h->danhsach[i].MSSV << "," << h->danhsach[i].tensv << "," << h->danhsach[i].lop << "," << h->danhsach[i].gtinh << "," << h->danhsach[i].ngsinh << "," << h->danhsach[i].CCCD << ",\n";
		h = h->next;
		file.close();
	}
}

void docFileMonHoc(Khoahoc& k)
{
	ifstream file("mon hoc.csv", ios::in);
	if (file.fail())
		return;
	int n = 0;
	
	string str;
	string temp;
	while (getline(file, str))
	{
			n++;
	}

	file.close();
	file.open("mon hoc.csv", ios::in);
	if (n == 1)
	{
		getline(file, str);
		k.hocki = stoi(str);
		str = str.substr(str.find(",") + 1, str.length());
		temp = str.substr(0, str.find(",") - 1);

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
		
		h->danhsach = new infostudent[h->soluong];

		temp = h->MaHP + ".csv";


		ifstream file1(temp, ios::in);
		if (file1.fail())
		{
			return;
		}

		for (int j = 0; j < h->top; j++)
		{
			getline(file1, str);
			
			temp = str.substr(0, str.find(","));
			h->danhsach[j].MSSV = stoi(temp);
			str = str.substr(str.find(",") + 1, str.length());

			temp = str.substr(0, str.find(","));
			h->danhsach[j].tensv = new char[temp.length()+1];
			strcpy(h->danhsach[j].tensv, temp.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			temp = str.substr(0, str.find(","));
			h->danhsach[j].lop = new char[temp.length() + 1];
			strcpy(h->danhsach[j].lop, temp.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			temp = str.substr(0, str.find(","));
			h->danhsach[j].gtinh = new char[temp.length() + 1];
			strcpy(h->danhsach[j].gtinh, temp.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			temp = str.substr(0, str.find(","));

			h->danhsach[j].ngsinh = new char[temp.length() + 1];
			strcpy(h->danhsach[j].ngsinh, temp.c_str());
			str = str.substr(str.find(",") + 1, str.length());

			h->danhsach[j].CCCD = stoi(str);
		}
		if (k.HP == NULL)
			k.HP = h;
		else
		{
			h->next = k.HP;
			k.HP = h;
		}
	}
	file.close();
}

int suaMonHoc(Khoahoc k)
{
	string str;
	cin.ignore();
	cout << "nhap ma hoc phan : ";
	getline(cin,str);
	cout << str;
	Hocphan* temp = k.HP;
	while (temp != NULL)
	{
		if (str.compare(temp->MaHP) == 0)
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
		cout << "5. So luong sinh vien toi da : " << temp->soluong << endl;
		cout << "6. Buoi hoc : " << temp->time.thu << endl;
		cout << "7. Tiet bat dau : " << temp->time.gioBatDau << endl;
		cout << "8. Tiet ket thuc : " << temp->time.gioKetThuc << endl;
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


int themSVMonHoc(Khoahoc& k, list l)
{
	cout << "Nhap Ma Hoc : ";
	string str;
	cin.ignore();
	getline(cin, str);
	Hocphan* temp = k.HP;
	while (temp != NULL)
	{
		if (temp->MaHP == str)
			break;
		
		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "lop khong duoc tim thay" << endl;
		return 0;
	}
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
	student* sv = l.pHead;
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
		if (temp->danhsach[i].MSSV == sv->info.MSSV)
		{
			cout << "sinh vien da co trong lop." << endl;
			return 0;
		}
	}
	
	temp->danhsach[temp->top] = sv->info;
	temp->top++;
	cout << "them sinh vien vao thanh cong" << endl;
	docFileMonHoc(k);
	return 1;
}


int xoa1SVRaKhoiMonHoc(Khoahoc k)
{
	cout << "Nhap Ma Hoc : ";
	string str;
	cin.ignore();
	getline(cin, str);
	Hocphan* temp = k.HP;
	while (temp != NULL)
	{
		if (temp->MaHP == str)
			break;

		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "lop khong duoc tim thay" << endl;
		return 0;
	}
	xuatMonHhoc(temp);
	if (temp->top == 0);
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
		if (temp->danhsach[i].MSSV == x)
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


void xoaKhoaHoc(Khoahoc& k)
{
	if (k.HP == NULL)
	{
		cout << "danh sach cac mon trong" << endl;
		return;
	}
	Hocphan* hp = k.HP;
	int i = 1;
	cout << setw(10) << left << "stt" << setw(15) << left << "Ma hoc phan" << setw(25) << left << "Ten hoc phan" << setw(15) << left << "Ten Lop" << setw(25) << left << "Ten giao vien" << setw(20) << left << "so tin chi" << setw(10) << left << "buoi" << setw(20) << left << "tiet bat dau" << setw(20) << left << "tiet ket thuc" << endl;
	while (hp != NULL)
	{
		cout << setw(10) << left << i << setw(15) << left << hp->MaHP << setw(25) << left << hp->TenHP << setw(15) << left << hp->Tenlop << setw(25) << left << hp->GV << setw(20) << left << hp->tinchi << setw(10) << left << hp->time.thu << setw(20) << left << hp->time.gioBatDau << setw(20) << left << hp->time.gioKetThuc << endl;
		hp = hp->next;
		i++;
	}
	cout << "nhap ma hoc phan lop can xoa ";
	cin.ignore();
	string str;
	getline(cin, str);
	hp = k.HP;
	while (hp != NULL)
	{
		if (hp->MaHP == str)
			break;
		hp = hp->next;
	}
	if (hp == NULL)
	{
		cout << "khong thay ma hoc phan." << endl;
		return;
	}
	str = hp->MaHP+ ".csv";
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