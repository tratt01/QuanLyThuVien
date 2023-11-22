#include "QuanLyDocGia.h";

void KhoiTao(DSDG& d) {
	d.pHead = d.pTail = NULL;
}

NODE* KhoiTaoNode(THONGTINDOCGIA t) {
	NODE* p = new NODE;
	if (p == NULL) {
		cout << "Khong du bo nho";
		return NULL;
	}
	p->ttdg = t;
	p->pNext = NULL;
	return p;
}

void ThemVaoCuoi(DSDG& d, NODE* p) {
	if (d.pHead == NULL) {
		d.pHead = d.pTail = p;
	}
	else {
		d.pTail->pNext = p;
		d.pTail = p;
	}
}

void NhapThongTinDocGia(THONGTINDOCGIA& t) {
	cin.ignore();
	cout << "Nhap ho ten doc gia: "; getline(cin, t.hoten);
	cout << "Nhap gioi tinh doc gia: "; cin >> t.gioitinh;
	cout << "Nhap email doc gia: "; cin >> t.email;
	cin.ignore();
	cout << "Nhap dia chi doc gia: "; getline(cin, t.diachi);
	cout << "-----NHAP NGAY SINH-----\n";
	int time1 = KiemTraNgayThangNam(t.ngaysinh, t.thangsinh, t.namsinh);
	cout << "Nhap so CMND doc gia: "; cin >> t.cmnd;
	cout << "Nhap MSDG cua doc gia: "; cin >> t.madocgia;
	cout << "-----NHAP THOI GIAN MUON THE-----\n";
	int time2 = KiemTraNgayThangNam(t.ngaymuon, t.thangmuon, t.nammuon);
	t.ngayhet = t.ngaymuon;
	t.thanghet = t.thangmuon;
	t.namhet = t.nammuon + 4;
}

int KiemTraNgayThangNam(int& CheckNgay, int& CheckThang, int& CheckNam)
{
	int Ngay, Thang, Nam, Check = 0;
	do {
		Check = 0;
		cout << "Nhap ngay : "; cin >> Ngay;
		cout << "Nhap thang : "; cin >> Thang;
		cout << "Nhap nam : "; cin >> Nam;

		if (Ngay > 31 || Ngay < 0 || Thang < 0 || Thang > 12 || Nam < 0)
		{
			Check = -1;
		}
		else
		{// 1 3 5 7 8 10 12
			if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)
			{
				CheckNam = Nam;
				if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
				{
					CheckNgay = Ngay;
					CheckThang = Thang;
				}
				else if ((Thang == 4 || Thang == 6 || Thang == 5 || Thang == 7 || Thang == 9 || Thang == 11))
				{
					if (Ngay < 31)
					{
						CheckNgay = Ngay;
						CheckThang = Thang;
					}
					else
					{
						Check = -1;
					}
				}
				else if (Thang == 2)
				{
					if (Ngay < 30)
					{
						CheckNgay = Ngay;
						CheckThang = Thang;
					}
					else {
						Check = -1;
					}
				}

			}
			else
			{
				CheckNam = Nam;
				if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12)
				{
					CheckNgay = Ngay;
					CheckThang = Thang;
				}
				else if ((Thang == 4 || Thang == 6 || Thang == 5 || Thang == 7 || Thang == 9 || Thang == 11))
				{
					if (Ngay < 31)
					{
						CheckNgay = Ngay;
						CheckThang = Thang;
					}
					else {
						Check = -1;
					}
				}
				else if (Thang == 2 && Ngay < 29)
				{
					if (Ngay < 29)
					{
						CheckNgay = Ngay;
						CheckThang = Thang;
					}
					else {
						Check = -1;
					}
				}

			}
		}
		if (Check == -1)
		{
			cout << "Kiem tra lai ! Xin moi nhap lai !!!\n";
			system("cls");
		}
	} while (Check == -1);
	return 0;
}

void NhapDSDG(DSDG& d) {
	int n;
	cout << "Nhap so luong doc gia can them vao = "; cin >> n;
	ofstream fileOut("DSDG.txt", ios::app);
	for (int i = 0; i < n; i++)
	{
		THONGTINDOCGIA t;
		cout << "\nNhap thong tin doc gia thu " << i + 1 << ": \n";
		NhapThongTinDocGia(t);
		LuuVaoTiepTin(t, fileOut);
		NODE* p = KhoiTaoNode(t);
		ThemVaoCuoi(d, p);
	}
}

void LuuVaoTiepTin(THONGTINDOCGIA t, ofstream& fileOut) {
	if (fileOut.fail()) {
		cout << "Cannot open file at DSDG.txt" << endl;
		return;
	}
	fileOut << t.madocgia << ", " << t.hoten << ", " << t.gioitinh << ", " << t.email << ", " << t.diachi << ", " << t.cmnd;
	fileOut << ", " << t.ngaysinh << "-" << t.thangsinh << "-" << t.namsinh << ", ";
	fileOut << t.ngaymuon << "-" << t.thangmuon << "-" << t.nammuon << ", ";
	fileOut << t.ngayhet << "-" << t.thanghet << "-" << t.namhet << "\n";
}

void XuatThongTinDocGia(THONGTINDOCGIA t) {
	cout << "Ma doc gia: " << t.madocgia << endl;
	cout << "Ho ten: " << t.hoten << endl;
	cout << "Gioi tinh: " << t.gioitinh << endl;
	cout << "Email: " << t.email << endl;
	cout << "Dia chi: " << t.diachi << endl;
	cout << "CMND: " << t.cmnd << endl;
	cout << "Ngay sinh: " << t.ngaysinh << "-" << t.thangsinh << "-" << t.namsinh << endl;
	cout << "Ngay muon: "<< t.ngaymuon << "-" << t.thangmuon << "-" << t.nammuon << endl;
	cout << "Ngay het han: " << t.ngayhet << "-" << t.thanghet << "-" << t.namhet << endl;
	cout << "-------------end--" << endl;
}

void XuatDSDG(DSDG d) {
	NODE* p = d.pHead;
	while (p != NULL) {
		XuatThongTinDocGia(p->ttdg);
		p = p->pNext;
	}
}

void DocThongTinMotDocGia(ifstream& file, THONGTINDOCGIA& t) {
	file >> t.madocgia;
	file.seekg(1, 1);
	file.seekg(1, 1);
	getline(file, t.hoten, ',');
	file.seekg(1, 1);
	getline(file, t.gioitinh, ',');
	file.seekg(1, 1);
	getline(file, t.email, ',');
	file.seekg(1, 1);
	getline(file, t.diachi, ',');
	file.seekg(1, 1);
	file >> t.cmnd;
	file.seekg(1, 1);
	file >> t.ngaysinh;
	file.seekg(1, 1);
	file >> t.thangsinh;
	file.seekg(1, 1);
	file >> t.namsinh;
	file.seekg(1, 1);
	file >> t.ngaymuon;
	file.seekg(1, 1);
	file >> t.thangmuon;
	file.seekg(1, 1);
	file >> t.nammuon;
	file.seekg(1, 1);
	file >> t.ngayhet;
	file.seekg(1, 1);
	file >> t.thanghet;
	file.seekg(1, 1);
	file >> t.namhet;

	string temp;
	getline(file, temp);
}

void DocThongTinNhieuDocGia(DSDG& d) {
	ifstream fileIn;
	fileIn.open("DSDG.txt", ios::in);
	while (!fileIn.eof()) {
		THONGTINDOCGIA t;
		DocThongTinMotDocGia(fileIn, t);
		NODE* p = KhoiTaoNode(t);

		if (p->ttdg.hoten == "") {
			break;
		}
		ThemVaoCuoi(d, p);
	}
	fileIn.close();
}

bool KiemTraMaSo(DSDG d, int q) {
	NODE* p = d.pHead;
	while (p != NULL)
	{
		if (p->ttdg.madocgia == q)
		{
			return true;
		}
		p = p->pNext;
	}
	return false;
}

int NhapMaSo()
{
	int q;
	cout << "Nhap Ma so can sua : "; cin >> q;
	return q;
}

int NhapCmnd() {
	int q;
	cout << "Nhap so CMND can tim : "; cin >> q;
	return q;
}

string NhapHoTen() {
	string hoten;
	cin.ignore();
	cout << "Nhap ho ten can tim : "; getline(cin, hoten);
	return hoten;
}

NODE* TimKiemBangMaSo(DSDG d, int q) {
	NODE* p = d.pHead;
	while (p != NULL)
	{
		if (p->ttdg.madocgia == q)
		{
			return p;
		}
		p = p->pNext;
	}
}

NODE* TimKiemBangCmnd(DSDG d) {
	int q = NhapCmnd();
	NODE* p = d.pHead;
	while (p != NULL)
	{
		if (p->ttdg.cmnd == q)
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}

/*
Tim kiem doc gia theo ho ten
nhan vao: Ho ten doc gia can tim
xuat ra : Thong tin cua doc gia
*/
NODE* TimKiemBangHoTen(DSDG d) {
	string q = NhapHoTen();
	NODE* p = d.pHead;
	while (p != NULL)
	{
		if (p->ttdg.hoten == q)
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}

void XoaThongTinDocGia(DSDG& d, int maso) {
	NODE* temp = d.pHead;
	// Xoa dau
	if (d.pHead->ttdg.madocgia == maso) {
		d.pHead = d.pHead->pNext;
		delete temp;
	} // Xoa cuoi
	else if (d.pTail->ttdg.madocgia == maso) {
		for (temp; temp != NULL; temp = temp->pNext) {
			if (temp->pNext == d.pTail) {
				delete d.pTail;
				temp->pNext = NULL;
				d.pTail = temp;
			}
		}
	} // Xoa giua
	else {
		for (temp; temp != NULL; temp = temp->pNext) {
			if (temp->pNext->ttdg.madocgia == maso) {
				NODE* X = temp->pNext;
				temp->pNext = X->pNext;
				delete X;
			}
		}
	}
}

void menuDocGia(DSDG d) {
	
	int ChucNang = 1;
	// Cap nhat doc gia tu File .txt

	while (ChucNang >= 1 && ChucNang <= 6) {
		system("cls");
		cout << "Quan li thong tin doc gia\n";
		cout << "[1] : Xem danh sach doc gia trong thu vien \n";
		cout << "[2] : Them doc gia \n";
		cout << "[3] : Chinh sua thong tin mot doc gia \n";
		cout << "[4] : Xoa thong tin mot doc gia \n";
		cout << "[5] : Tim kiem danh sach doc gia theo CMND \n";
		cout << "[6] : Tim kiem	doc gia theo ho ten \n";
		cout << "[7] : Quay lai Menu chinh \n";
		cout << "Chon chuc nang : "; cin >> ChucNang;
		KhoiTao(d);
		DocThongTinNhieuDocGia(d);

		switch (ChucNang) {
		// Hien danh sach thong tin doc gia
		case 1:
		{
			ifstream file;
			file.open("DSDG.txt", ios::in);
			if (!file)
			{
				cout << "Khong co doc gia trong danh sach ! Kiem tra lai\n";
			}
			else {
				XuatDSDG(d);
			}
			file.close();
			system("pause");
			break;
		}
		// Them thong tin cua doc gia
		case 2:
		{
			system("cls");
			NhapDSDG(d);
			break;
		}
		// Chinh sua thong tin doc gia
		case 3:
		{
			cout << "Chuc nang chinh sua thong tin doc gia\n";
			int q = NhapMaSo();
			// Khong tim thay ma so doc gia trong thu vien
			if (!KiemTraMaSo(d, q))
			{
				int ChucNang2;
				cout << "Khong Co so MSDG can tim\n";
				cout << "[1] tro lai Menu\n";
				cout << "[2] Thoat Khoi Chung trinh\n";
				cout << "Nhap chuc nang: "; cin >> ChucNang2;
				if (ChucNang2 == 1)
				{
					break;
				}
				else {
					exit(0);
				}
			}
			// Co tim thay ma so doc gia trong thu vien
			else
			{
				int ChucNang3 = 1;
				while (ChucNang3 >= 1 && ChucNang3 <= 8) {
					
					NODE* p = TimKiemBangMaSo(d, q);
					cout << "== Chuc nang chinh sua thong tin doc gia ==\n";
					cout << "[1] : Chinh sua ma so \n";
					cout << "[2] : Chinh sua CMND \n";
					cout << "[3] : Chinh sua ten \n";
					cout << "[4] : Chinh sua gioi tinh\n";
					cout << "[5] : Chinh sua email \n";
					cout << "[6] : Chinh sua ngay : thang : nam sinh\n";
					cout << "[7] : Chinh sua ngay : thang : nam lap the\n";
					cout << "[8] : Luu chinh sua ! Du lieu cu se mat \n";
					cout << "[9] : Quay lai Menu chinh \n";
					cout << "Nhap chuc nang: "; cin >> ChucNang3;
					switch (ChucNang3)
					{
						/* chuc nang chinh sua ma so doc gia
						nhan vao : ma so doc gia moi*/
					case 1:
					{
						int ChucNang2;
						cout << "Nhap vao so MSDG moi: "; cin >> p->ttdg.madocgia;
						cout << "Chinh sua Thanh cong ! ";
						{
							cout << "[1] Tro lai Menu\n";
							cout << "[2] Thoat Khoi Chung trinh\n";
							cout << "Nhap chuc nang : "; cin >> ChucNang2;
							if (ChucNang2 == 1)
							{
								break;
							}
							else {
								exit(0);
							}
						}
					}
					/*
					Chuc nang chin sua chung minh dan dan
					nhan vao: chuc minh nhan dan moi
					*/
					case 2:
					{
						int ChucNang2;
						cout << "Nhap vao so CMND moi: "; cin >> p->ttdg.cmnd;
						cout << "Chinh sua Thanh cong ! ";
						system("pause");
						system("cls");
						{
							cout << "[1] Tro lai Menu\n";
							cout << "[2] Thoat Khoi Chung trinh\n";
							cout << "Nhap chuc nang : "; cin >> ChucNang2;
							if (ChucNang2 == 1)
							{
								break;
							}
							else {
								exit(0);
							}
						}
					}
					/*
					Chinh sua ho va ten
					nhap vao : ho va ten moi
					*/
					case 3:
					{
						int ChucNang2;
						cin.ignore();
						cout << "Nhap vao ho ten moi: "; getline(cin, p->ttdg.hoten);
						cout << "Chinh sua Thanh cong ! ";
						cout << "Nhap chuc nang : "; cin >> ChucNang2;
						system("pause");
						system("cls");
						{
							cout << "[1] Tro lai Menu\n";
							cout << "[2] Thoat Khoi Chung trinh\n";
							cout << "Nhap chuc nang : ";
							if (ChucNang2 == 1)
							{
								break;
							}
							else {
								exit(0);
							}
						}
					}
					/*
					Chinh sua Email moi
					nhan vao : email moi*/
					case 4:
					{
						int ChucNang2;
						cout << "Nhap vao so emai moi: "; cin >> p->ttdg.email;
						cout << "Chinh sua Thanh cong ! ";
						system("pause");
						system("cls");
						{
							cout << "[1] Tro lai Menu\n";
							cout << "[2] Thoat Khoi Chung trinh\n";
							cout << "Nhap chuc nang: "; cin >> ChucNang2;
							if (ChucNang2 == 1)
							{
								break;
							}
							else {
								exit(0);
							}
						}
					}
					/*
					Chinh sua gioi tinh
					nhan vao : gioi tinh moi
					*/
					case 5: {
						int ChucNang2;
						cout << "Nhap vao gioi tinh moi: "; cin >> p->ttdg.gioitinh;
						cout << "Chinh sua Thanh cong ! ";
						system("pause");
						system("cls");
						{
							cout << "[1] Tro lai Menu\n";
							cout << "[2] Thoat Khoi Chung trinh\n";
							cout << "Nhap chuc nang: "; cin >> ChucNang2;
							if (ChucNang2 == 1)
							{
								break;
							}
							else {
								exit(0);
							}
						}

					}
						  /*
						  Chinh sua ngay thang nam sinh
						  nhan vao : ngay thang nam sinh moi
						  */
					case 6: {
						int time3 = KiemTraNgayThangNam(p->ttdg.ngaysinh, p->ttdg.thangsinh, p->ttdg.namsinh);
						cout << "\n Chinh sua thanh cong ! \n";
						system("pause");
						system("cls");
						{
							int ChucNang2;
							cout << "[1] tro lai Menu\n";
							cout << "[2] Thoat Khoi Chung trinh\n";
							cout << "Nhap chuc nang: "; cin >> ChucNang2;
							
							if (ChucNang2 == 1)
							{
								break;
							}
							else {
								exit(0);
							}

						}

					}
						  /*
						  Chinh sua thoi gian thanh la the
						  nhan vao : thoi gian thanh lap the moi*/
					case 7: {
						int time4 = KiemTraNgayThangNam(p->ttdg.ngaymuon, p->ttdg.thangmuon, p->ttdg.nammuon );
						p->ttdg.ngayhet = p->ttdg.ngaymuon;
						p->ttdg.thanghet = p->ttdg.thangmuon;
						p->ttdg.namhet = p->ttdg.nammuon + 4;
						cout << "\n Chinh sua thanh cong ! \n";
						system("pause");
						system("cls");
						{
							int ChucNang2;
							cout << "[1] tro lai Menu\n";
							cout << "[2] Thoat Khoi Chung trinh\n";
							cout << "Nhap chuc nang : "; cin >> ChucNang2;
							if (ChucNang2 == 1)
							{
								break;
							}
							else {
								exit(0);
							}

						}
					}
					case 8:
					{
						ofstream fileOut("DSDG.txt", ios::out);
						NODE* p = d.pHead;
						while (p != NULL) {
							LuuVaoTiepTin(p->ttdg, fileOut);
							p = p->pNext;
						}
						
					}
					default:
					{
						break;
					}

					}
				}
				break;
			}
		}		
		//	Xoa thong tin cua 1 doc gia
		case 4:
		{
			int q = NhapMaSo();
			if (KiemTraMaSo(d, q)) {
				XoaThongTinDocGia(d, q);
				ofstream fileOut("DSDG.txt", ios::out);
				NODE* p = d.pHead;
				while (p != NULL) {
					LuuVaoTiepTin(p->ttdg, fileOut);
					p = p->pNext;
				}
				cout << "Xoa thanh cong !\n";
				system("pause");
				break;
			}
			else {
				cout << "Khong ton tai doc gia ! Kiem tra lai \n";
				break;
			}
		}
		/*
		Tim kiem doc gia bang Cmnd
		*/
		case 5:
		{
			NODE* p = TimKiemBangCmnd(d);
			if (p != NULL) {
				XuatThongTinDocGia(p->ttdg);
				system("pause");
				break;

			}
			else {
				cout << "Khong ton tai CMND ! Kiem tra lai !\n";
				system("pause");
				break;
			}
		}
		case 6:
		{
			NODE* p = TimKiemBangHoTen(d);
			if (p != NULL)  {
				XuatThongTinDocGia(p->ttdg);
				system("pause");
				break;
			}
			else {
				cout << "Khong ton tai ten nay ! Kiem tra lai !\n";
				system("pause");
				break;
			}
		}
		default:
		{
			break;
		}
		}
	}
}