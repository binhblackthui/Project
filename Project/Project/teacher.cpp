#include"teacher.h"





GiaoVien* taoGV()//tao mot tai khoan giao vien
{
	GiaoVien* temp = new GiaoVien;
	temp->Next = NULL;
	return temp;
}


void taoDSGV(listGiaoVien& l)//dem so luong sinh vien trong file csv
{
	char temp[10000];
	ifstream file;
	int n = 0;
	file.open("../Project/Tai Khoan/accteacher.csv", ios::in);
	if (file.fail() == true)
		cout << "mo file khon thanh cong";
	file.getline(temp, 1000);
	while (file.getline(temp, 1000))
	{
		themDauDSGV(l);
	}
	file.close();
}


void themDauDSGV(listGiaoVien& l)//them tai khoan moi vao dau danh sach nhan vien
{

	GiaoVien* t = taoGV();
	t->Next = l.Head;
	l.Head = t;
}


void docfileGV(listGiaoVien& l)//doc file tai khoan va thong tin cua nhan vien vao tai khoan rong
{
	char temp1[1000];
	char temp2[100];
	GiaoVien* t = l.Head;
	ifstream file1;
	ifstream file2;
	file1.open("../Project/Tai Khoan/accteacher.csv", ios::in);
	file2.open("../Project/Thong Tin/infoteacher.csv", ios::in);
	file1.getline(temp1, 1000);
	file2.getline(temp1, 1000);
	while (t!=NULL)
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
				t->acc.nameacc= new char[strlen(temp2) + 1];
				strcpy(t->acc.nameacc, temp2);
				break;
			}
		}
		for (int j = 0; 1; j++)
		{
			temp2[j] = temp1[k];
			k++;
			if (temp1[k] == '\0'|| temp1[k] == ',')
			{
				k++;
				temp2[j + 1] = '\0';
				t->acc.pass = new char[strlen(temp2) + 1];
				strcpy(t->acc.pass, temp2);
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
				t->info.tenGV = new char[strlen(temp2) + 1];
				strcpy(t->info.tenGV, temp2);
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
				t->info.mail = new char[strlen(temp2) + 1];
				strcpy(t->info.mail, temp2);
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
				t->info.gtinh = new char[strlen(temp2) + 1];
				strcpy(t->info.gtinh, temp2);
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
				t->info.ngsinh = new char[strlen(temp2) + 1];
				strcpy(t->info.ngsinh, temp2);
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
				t->info.chucvu = new char[strlen(temp2) + 1];
				strcpy(t->info.chucvu, temp2);
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
				t->info.CCCD = stoi(temp2);
				break;
			}
		}
		t = t->Next;
	}
	file1.close();
	file2.close();
}


GiaoVien* dangnhapGV(listGiaoVien& l)//dang nhao tai khoan nhan vien
{
	GiaoVien* temp = l.Head;
	char name[100];
	char pass[100];
quaylai:
	temp = l.Head;
	cout << "Ten dang nhap : "; cin.getline(name, 100);
	cout << "Mat khau : "; cin.getline(pass, 100);
	while (temp!=NULL)
	{
		if (strcmp(name, temp->acc.nameacc) == 0 and strcmp(pass, temp->acc.pass) == 0)
		{
			return temp;
		}
		temp = temp->Next;
	}
	cout << "Dang nhap khong thanh cong." << endl;
	return NULL;
}


void xuatThongTinGV(GiaoVien* t)//xem thong tin ca nhan cua nhan vien
{
	cout << "Ho va ten : " << t->info.tenGV << endl;;
	cout << "Email : " << t->info.mail << endl;
	cout << "Gioi tinh : " << t->info.gtinh<<endl;
	cout << "Ngay sinh : " << t->info.ngsinh << endl;
	cout << "Chuc vu : " << t->info.chucvu << endl;
	cout << "can cuoc cong dan : " << t->info.CCCD << endl;
}


GiaoVien* doiMatKhauGV(GiaoVien*& temp,listGiaoVien l)//doi mat khau tai nhan vien
{
	char pass[1000];
	cin.ignore();
	quaylai:
	system("cls");
	
	cout << "Vui long nhap lai mat khau cu : "; cin.getline(pass,1000);
	if (strcmp(temp->acc.pass, pass) != 0)
	{
		goto quaylai;
	}
	cout << "nhap mat khau moi : "; cin.getline(pass, 1000);
	delete[]temp->acc.pass;
	temp->acc.pass = new char[strlen(pass) + 1];
	strcpy(temp->acc.pass, pass);
	cout << "Doi mat khau thanh cong" << endl;
	ofstream file;
	file.open("../Project/Tai Khoan/accteacher.csv", ios::out);
	file << "ten tai khoan,mat khau,\n";
	GiaoVien* t = l.Head;
	while (t!=NULL)
	{
		file << t->acc.nameacc << "," << t->acc.pass << ",\n";
		t = t->Next;
	}
	file.close();
	return temp;
}


