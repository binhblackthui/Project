#include"student.h"
#include"teacher.h"


int main()
{
	Khoahoc k;
	list s;
	int namhoc=0;
	listteacher t;
	student* temp;
	teacher* temp1;
	classroom* lop=NULL;
	GanNULLSV(s);
	demsoluongsv(s);
	docfileSV(s);
	int n;
	int x;
	ganNULLGV(t);
	taoDSGV(t);
	docfileGV(t);
	doiFileMonHoc(k);
	do
	{
	quaylai:
		system("cls");
		cout << "1. sinh vien." << endl;;
		cout << "2. giao vien" << endl;
		cout << "0. thoat" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			do {
			quaylai0:
				system("cls");
				cout << "1. dang nhap." << endl;
				cout << "0. quay lai" << endl;
				cin >> x;
				switch (x)
				{
				case 1:
				{
					system("cls");
				quaylai1:
					cin.ignore();
					temp = dangnhapSV(s);
					if (temp == NULL)
					{
						cout << "Ban co muon dang nhap lai khong" << endl;
						cout << "1. co \t 2. khong" << endl;
						do
						{
							cin >> x;
						} while (x != 1 and x != 2);
						if (x == 1)
							goto quaylai1;
						else
							goto quaylai0;
					}
					else
					{
						do
						{
						quaylai2:
							system("cls");
							cout << "1. Xem thong tin ca nhan." << endl;
							cout << "2. doi mat khau." << endl;
							cout << "0. dang xuat" << endl;
							do
							{
								cin >> x;
							} while (x < 0 || x>2);
							switch (x)
							{
							case 1:
							{
								system("cls");
								xuatthongtinSV(temp);
								cout << endl;
								cout << "0. Quay lai." << endl;
								do
								{
									cin >> x;
								} while (x != 0);
								goto quaylai2;
								break;
							}
							case 2:
							{
								system("cls");
								temp = doiMatKhau(temp, s);
								cout << endl;
								cout << "0.quay lai." << endl;

								do
								{
									cin >> x;
								} while (x != 0);
								goto quaylai2;
								break;
							}
							}
							if (x == 0)
								goto quaylai0;
						} while (x != 0);
					}
					break;
				}
				}
				if (x == 0)
					goto quaylai;
			} while (x != 0);
		case 2:
		{
			
			do {
			quaylai3:
				system("cls");
				cout << "1. dang nhap." << endl;
				cout << "0. quay lai" << endl;
				cin >> x;
				if (x == 1)
				{
					system("cls");
				quaylai4:
					cin.ignore();
					temp1 = dangnhapGV(t);
					if (temp1 == NULL)
					{
						cout << "Ban co muon dang nhap lai khong" << endl;
						cout << "1. co \t 2. khong" << endl;
						do
						{
							cin >> x;
						} while (x != 1 and x != 2);
						if (x == 1)
							goto quaylai4;
						else
							goto quaylai3;
					}
					else
					{
					quaylai5:
						system("cls");
						cout << "1. Xem thong tin ca nhan." << endl;
						cout << "2. Doi mat khau." << endl;
						cout << "3. Xem danh sach lop" << endl;
						cout << "4. tao nam hoc moi." << endl;
						cout << "5. tao lop hoc." << endl;
						cout << "6. them mot sinh vien vao 1 lop." << endl;
						cout << "7. xoa 1 sinh vien." << endl;
						cout << "8. tao hoc ki." << endl;
						cout << "9. tao mon hoc." << endl;
						cout << "10. xem danh sach mon hoc." << endl;
						cout << "0. Dang xuat" << endl;
						do {
							cin >> x;
							switch (x)
							{
							case 1:
							{
								system("cls");
								xuatThongTinGV(temp1); cout << endl;
								cout << "0. quay lai." << endl;
								do {
									cin >> x;
								} while (x != 0);
								break;
							}
							case 2:
							{
								system("cls");
								doiMatKhauGV(temp1, t);
								cout << endl;
								cout << "0. quay lai." << endl;
								do {
									cin >> x;
								} while (x != 0);
								break;
							}
							case 3:
							{
								system("cls");
								n = 0;
								dslop(s, lop, n);
								xuatlop(lop, n,s);
								delete[] lop;
								n = 0;
								cout << endl;
								cout << "0. quay lai." << endl;
								do {
									cin >> x;
								} while (x != 0);
								break;
							}
							case 4:
							{
								system("cls");
								taonamhoc(namhoc);
								cout << endl;
								cout << "0. quay lai" << endl;
								do {
									cin >> x;
								} while (x != 0);
								break;
							}
							case 5:
							{
								lop = NULL;
								system("cls");
								if (namhoc == 0) {
									cout << "vui long toa nam hoc truoc." << endl;
									cout << endl;
									cout << "0. quay lai" << endl;
									do {
										cin >> x;
									} while (x != 0);
									break;
								}
								taolop(s, lop, namhoc);
								if (lop == NULL)
								{
									cout << endl;
									cout << "0. quay lai" << endl;
									do {
										cin >> x;
									} while (x != 0);
									break;
								}
								cout << "chon cach nhap danh sach sinh vien" << endl;
								cout << "1. nhap tay" << endl;
								cout << "2. nhap vao bang file." << endl;
								cin >> x;
								if (x == 1)
									nhaptay(s, lop);
								if (x == 2)
									nhapfile(s, lop);
								delete lop;
								cout << endl;
								cout << "0. quay lai" << endl;
								do {
									cin >> x;
								} while (x != 0);
								break;
							}
							case 6:
							{
								system("cls");
								them1SV(s);
								cout << endl;
								cout << "0. quay lai" << endl;
								do {
									cin >> x;
								} while (x != 0);
								break;
							}
							case 7:
							{
								system("cls");
								xoa1SV(s);
								cout << endl;
								cout << "0. quay lai" << endl;
								do {
									cin >> x;
								} while (x != 0);
								break;
							}
							case 8:
							{
								{
									system("cls");
									taoHocKi(k);
									cout << endl;
									cout << "0. quay lai" << endl;
									do {
										cin >> x;
									} while (x != 0);
									break;
								}
							}
							case 9:
							{
								system("cls");
								taoMonHoc(k);
								cout << endl;
								cout << "0. quay lai" << endl;
								do {
									cin >> x;
								} while (x != 0);
								break;
							}
							case 10:
							{
								{
									system("cls");
									xuatKhoaHoc(k);
									cout << endl;
									cout << "0. quay lai" << endl;
									do {
										cin >> x;
									} while (x != 0);
									break;
								}
							}
							}
							if (x == 0)
							{
								goto quaylai5;
							}
						} while (x<0||x>5);
						if (x == 0)
							goto quaylai;
					}while (1);
				}
			} while (x!=0);
		}
		}
		
		}
	} while (x != 0);
}
