#include"student.h"
#include"teacher.h"


int main()
{
	Khoahoc k;
	listSinhVien s;
	int namhoc = 0;
	listGiaoVien t;
	SinhVien* temp;
	GiaoVien* temp1;
	listLop lop;
	demsoluongsv(s);
	docfileSV(s);
	int n;
	int x;
	taoDSGV(t);
	docfileGV(t);
	docFileMonHoc(k);
	docFileLop(lop);
	do
	{
	menu:
		system("cls");
		cout << "1. sinh vien." << endl;;
		cout << "2. giao vien" << endl;
		cout << "0. thoat" << endl;
		cout << endl;
		cout << "nhap su lua chon : "; cin >> x;
		switch (x)
		{
		case 1:
		{
			do {
			dangnhapsv:
				system("cls");
				cout << "1. dang nhap." << endl;
				cout << "0. quay lai" << endl;
				cout << endl;
				cout << "nhap su lua chon : "; cin >> x;
				switch (x)
				{
				case 1:
				{
				dangnhaplaiSV:
					system("cls");
					cin.ignore();
					temp = dangnhapSV(s);
					if (temp == NULL)
					{
						cout << "Ban co muon dang nhap lai khong" << endl;
						cout << "1. co \t 2. khong" << endl;
						cout << endl;
						cout << "nhap su lua chon : ";
						do
						{
							 cin >> x;
						} while (x != 1 and x != 2);
						if (x == 1)
							goto dangnhaplaiSV;
						else
							goto dangnhapsv;
					}
					else
					{
						do
						{
						menusv:
							system("cls");
							cout << "1. Xem thong tin ca nhan." << endl;
							cout << "2. doi mat khau." << endl;
							cout << "3. danh sach mon hoc duoc dang ki." << endl;
							cout << "4. diem cac mon hoc." << endl;
							cout << "0. dang xuat" << endl;
							cout << endl;
							cout << "nhap su lua chon : ";
							do
							{
								cin >> x;
							} while (x < 0 || x>4);
							if (x == 0)
							{
								goto dangnhapsv;
							}
							switch (x)
							{
							case 1:
							{
								system("cls");
								xuatthongtinSV(temp);
								cout << endl;
								cout << "0. Quay lai." << endl;
								cout << endl;
								cout << "nhap su lua chon : ";
								do
								{
									cin >> x;
								} while (x != 0);
								goto menusv;
								break;
							}
							case 2:
							{
								system("cls");
								temp = doiMKSV(temp, s);
								cout << endl;
								cout << "0.quay lai." << endl;
								cout << endl;
								cout << "nhap su lua chon : ";
								do
								{
									cin >> x;
								} while (x != 0);
								goto menusv;
								break;
							}
							case 3:
							{
								system("cls");
								svxemThongTinLop(k, temp);
								cout << endl;
								cout << "0.quay lai." << endl;
								cout << endl;
								cout << "nhap su lua chon : ";
								do
								{
									cin >> x;
								} while (x != 0);
								goto menusv;
								break;
							}
							case 4:
							{
								system("cls");
								svxemDiem(k, temp);
								cout << endl;
								cout << "0.quay lai." << endl;
								cout << endl;
								cout << "nhap su lua chon : ";
								do
								{
									cin >> x;
								} while (x != 0);
								goto menusv;
								break;
							}
							}
							if (x == 0)
								goto dangnhapsv;
						} while (x != 0);
					}
					break;
				}
				case 0:
				{
					goto menu;
				}
				}
			} while (1);
		}
		case 2:
		{

			do {
			dangnhapGV:
				system("cls");
				cout << "1. dang nhap." << endl;
				cout << "0. quay lai" << endl;
				cout << endl;
				cout << "nhap su lua chon : ";
				cin >> x;
				if (x == 0)
					goto menu;
				if (x == 1)
				{

				dangnhaplaiGV:
					system("cls");
					cin.ignore();
					temp1 = dangnhapGV(t);
					if (temp1 == NULL)
					{
						cout << "Ban co muon dang nhap lai khong" << endl;
						cout << "1. co \t 2. khong" << endl;
						cout << endl;
						cout << "nhap su lua chon : ";
						do
						{
							cin >> x;
						} while (x != 1 and x != 2);
						if (x == 1)
							goto dangnhaplaiGV;
						else
							goto dangnhapGV;
					}
					else {
						do {
							menuGV:
							system("cls");
							cout << "1. xem thong tin ca nhan." << endl;
							cout << "2. doi mat khau" << endl;
							cout << "3. quan ly danh sach cac lop." << endl;
							cout << "4. quan ly danh sach mon hoc." << endl;
							cout << "0. dang xuat" << endl;
							cout << endl;
							cout << "nhap su lua chon : ";
							cin >> x;
							switch (x)
							{
							case 0:
							{
								goto dangnhapGV;
								break;
							}
							case 1:
							{
								system("cls");
								xuatThongTinGV(temp1); cout << endl;
								cout << "0. quay lai." << endl;
								cout << endl;
								cout << "nhap su lua chon : ";
								do {
									cin >> x;
								} while (x != 0);
								break;
							}
							case 2:
							{
								system("cls");
								temp1=doiMatKhauGV(temp1, t);
								cout << endl;
								cout << "0. quay lai." << endl;
								cout << endl;
								cout << "nhap su lua chon : ";
								do {
									cin >> x;
								} while (x != 0);
								break;
							}
							case 3:
							{
								do {
								lophoc:
									system("cls");
									cout << "1. tao nam hoc moi." << endl;
									cout << "2. tao lop moi." << endl;
									cout << "3. them sinh vien vao lop bang file CSV." << endl;
									cout << "4. them 1 sinh vien vao lop." << endl;
									cout << "5. xem danh sach cac lop" << endl;
									cout << "0. quay lai" << endl;
									cout << endl;
									cout << "nhap su lua chon : ";
									cin >> x;
									switch (x)
									{
									case 0:
									{
										goto menuGV;
									}
									case 1:
									{
										system("cls");
										taoNamHoc(lop);
										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									case 2:
									{
										system("cls");

										taoLopHoc(lop);

										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									case 3:
									{
										system("cls");
										xuatDSLop(lop);

										themVaoLopFile(lop, s);

										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									case 4:
									{
										{
											system("cls");

											them1SVLop(lop, s);

											cout << endl;
											cout << "0. quay lai" << endl;
											cout << endl;
											cout << "nhap su lua chon : ";
											do {
												cin >> x;
											} while (x != 0);
											break;
										}
									}
									case 5:
									{
										{
											system("cls");
											xuatDSLop(lop);
											cout << endl;
											xuatLop(lop);

											cout << endl;
											cout << "0. quay lai" << endl;
											cout << endl;
											cout << "nhap su lua chon : ";
											do {
												cin >> x;
											} while (x != 0);
											break;
										}
									}
									}
								} while (1);
							}
							case 4:
							{
								do
								{
									monhoc:
									system("cls");
									cout << "1. tao hoc ki." << endl;
									cout << "2. tao mon hoc." << endl;
									cout << "3. xem danh sach mon hoc." << endl;
									cout << "4. sua thong tin mon hoc." << endl;
									cout << "5. them 1 sinh vien vao mon hoc." << endl;
									cout << "6. them danh sach sinh vien vao mon hoc bang file CSV." << endl;
									cout << "7. xoa 1 sinh vien ra khoi mon hoc." << endl;
									cout << "8. xoa 1 mon hoc." << endl;
									cout << "0. quay lai" << endl;
									cout << endl;
									cout << "nhap su lua chon : ";
									cin >> x;
									switch (x)
									{
									case 0:
										goto menuGV;
									case 1:
									{
										system("cls");
										if (k.hocki == 0)
										{
											taoHocKi(k);
											cout << "hoc ki da duoc tao." << endl;
										}
										else {
											cout << "Hoc ki : " << k.hocki << endl;
											cout << "Ngay bat dau : " << k.batdau.ngay << "/" << k.batdau.thang << "/" << k.batdau.nam << endl;
											cout << "Ngay ket thuc : " << k.ketthuc.ngay << "/" << k.ketthuc.thang << "/" << k.ketthuc.nam << endl;
											cout << endl;
											cout << "ban co muon tao hoc ki moi khong ?" << endl;
											cout << "1. co \t 2. khong" << endl;
											cout << endl;
											cout << endl;
											cout << "nhap su lua chon : ";
											do {
												cin >> x;
											} while (x != 1 and x != 2);
											if (x == 1)
											{
												system("cls");
												taoHocKi(k);
												cout << "hoc ki da duoc tao." << endl;
											}
										}

										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									case 2:
									{
										system("cls");
										if (k.hocki != 0)
											taoMonHoc(k,lop);
										else
											cout << "vui long tao hoc ki" << endl;
										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									case 3:
									{
										system("cls");
										if (xuatKhoaHoc(k)) goto monhoc;
										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									case 4:
									{
										system("cls");
										if (suaMonHoc(k,lop))
											goto monhoc;
										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									case 5:
									{
										system("cls");
										themSVMonHoc(k, s,lop);
										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									case 6:
									{
										system("cls");
										themSVVaoMonHocFile(k, lop);
										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									case 7:
									{
										system("cls");
										xoa1SVRaKhoiMonHoc(k,lop);
										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									case 8:
									{
										system("cls");
										xoaKhoaHoc(k);
										cout << endl;
										cout << "0. quay lai" << endl;
										cout << endl;
										cout << "nhap su lua chon : ";
										do {
											cin >> x;
										} while (x != 0);
										break;
									}
									}
								} while (1);
							}
							}
							if (x == 0)
							{
								goto menuGV;
							}

						} while (1);
					}

				}
			} while (1);


		}

		}
		} while (x != 0);

}
