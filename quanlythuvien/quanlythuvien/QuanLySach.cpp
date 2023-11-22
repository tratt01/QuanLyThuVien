#include "QuanLySach.h"

void KhoiTao(DSS& d) {
	d.pHead = d.pTail = NULL;
}

NODES* KhoiTaoNode(THONGTINSACH t) {
	NODES* p = new NODES;
	if (p == NULL) {
		cout << "Khong du bo nho";
		return NULL;
	}
	p->tts = t;
	p->pNext = NULL;
	return p;
}

void ThemVaoCuoi(DSS& d, NODES* p) {
	if (d.pHead == NULL) {
		d.pHead = d.pTail = p;
	}
	else {
		d.pTail->pNext = p;
		d.pTail = p;
	}
}

void LuuVaoTepTin(THONGTINSACH tt, ofstream& fileOut) {
	if (fileOut.fail()) {
		cout << "Cannot open file at DSDG.txt" << endl;
		return;
	}
	fileOut << tt.tensach << ", " << tt.isbn << ", " << tt.tacgia << ", " << tt.nxb << ", ";
	fileOut << tt.namxuatban << ", " << tt.theloai << ", " << tt.soquyensach << ", " << tt.giasach << "\n";
}

void NhapThongTinSach(THONGTINSACH& tt) {
	cin.ignore();
	cout << "Nhap ten sach: "; getline(cin, tt.tensach);
	cout << "Nhap isbn: "; cin >> tt.isbn;
	cin.ignore();
	cout << "Nhap ten tac gia: "; getline(cin, tt.tacgia);
	//cin.ignore();
	cout << "Nhap NXB: "; getline(cin, tt.nxb);
	cout << "Nam xuat ban: "; cin >> tt.namxuatban;
	cin.ignore();
	cout << "The loai sach: "; getline(cin, tt.theloai);
	cout << "So quyen sach: "; cin >> tt.soquyensach;
	cout << "Nhap gia sach: "; cin >> tt.giasach;
}
void NhapDSS(DSS& d) {
	int n;
	cout << "So luong quyen sach can them vao: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		ofstream fileOut("DSS.txt", ios::app);
		THONGTINSACH t;
		cout << "Nhap thong tin sach thu " << i + 1 << ": \n";
		NhapThongTinSach(t);
		LuuVaoTepTin(t, fileOut);
		NODES* p = KhoiTaoNode(t);
		ThemVaoCuoi(d, p);
	}
}

void XuatThongTinSach(THONGTINSACH tt) {
	cout << "Ten sach: " << tt.tensach << endl;
	cout << "Ma ISBN: " << tt.isbn << endl;
	cout << "Tac gia: " << tt.tacgia << endl;
	cout << "NXB: " << tt.nxb << endl;
	cout << "Nam xuat ban: " << tt.namxuatban << endl;
	cout << "The loai: " << tt.theloai << endl;
	cout << "So quyen sach: " << tt.soquyensach << endl;
	cout << "Gia sach: " << tt.giasach << endl;
}

void XuatDSS(DSS d) {
	int i = 1;
	NODES* p = d.pHead;
	while (p != NULL) {
		cout << "===== Thong tin cuon sach thu " << i << " =====" << endl;
		XuatThongTinSach(p->tts);
		p = p->pNext;
		i++;
	}
}

void XoaThongTinSach(DSS& d, int maso) {
	NODES* temp = d.pHead;
	// Xoa dau
	if (d.pHead->tts.isbn == maso) {
		d.pHead = d.pHead->pNext;
		delete temp;
	} // Xoa cuoi
	else if (d.pTail->tts.isbn == maso) {
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
			if (temp->pNext->tts.isbn == maso) {
				NODES* X = temp->pNext;
				temp->pNext = X->pNext;
				delete X;
			}
		}
	}
}

bool KiemTraMaSoSach(DSS d, int q) {
	NODES* p = d.pHead;
	while (p != NULL)
	{
		if (p->tts.isbn == q)
		{
			return true;
		}
		p = p->pNext;
	}
	return false;
}

NODES* TimKiemMaSoSach(DSS d, int q) {
	NODES* p = d.pHead;
	while (p != NULL)
	{
		if (p->tts.isbn == q)
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}


NODES* TimKiemSachTheoTen(DSS d, string q) {
	NODES* p = d.pHead;
	while (p != NULL)
	{
		if (p->tts.tensach == q)
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}

void DocThongTinSach(ifstream& file, THONGTINSACH& tt) {
	getline(file, tt.tensach, ',');
	file.seekg(1, 1);
	file >> tt.isbn;
	file.seekg(1, 1);
	file.seekg(1, 1);
	getline(file, tt.tacgia, ',');
	file.seekg(1, 1);
	getline(file, tt.nxb, ',');
	file.seekg(1, 1);
	file >> tt.namxuatban;
	file.seekg(1, 1);
	file.seekg(1, 1);
	getline(file, tt.theloai, ',');
	file.seekg(1, 1);
	file >> tt.soquyensach;
	file.seekg(1, 1);
	file >> tt.giasach;

	string temp;
	getline(file, temp);
}

void DocThongTinNhieuSach(DSS& d) {
	ifstream fileIn;
	fileIn.open("DSS.txt", ios::in);
	while (!fileIn.eof()) {
		THONGTINSACH t;
		DocThongTinSach(fileIn, t);
		NODES* p = KhoiTaoNode(t);

		if (p->tts.tensach == "") {
			break;
		}
		ThemVaoCuoi(d, p);
	}
	fileIn.close();
}
void ThongKeSachTheoTheLoai(DSS d) {

}

void menuSach(DSS d) {
	int ChucNang = 1;
	
	while (ChucNang >= 1 && ChucNang <= 6) {
		system("cls");
		cout << " ===Quan li sach=== \n";
		cout << " [1] : Xem thong tin sach trong thu vien \n";
		cout << " [2] : Them sach \n";
		cout << " [3] : Chinh sua thong tin 1 quyen sach thu vien \n";
		cout << " [4] : Xoa thong tin quyen sach \n";
		cout << " [5] : Tim kiem sach theo ISBN\n";
		cout << " [6] : Tim Kiem sach theo ten sach\n";
		cout << " [7] : Quay Lai Menu chinh\n";
		KhoiTao(d);
		DocThongTinNhieuSach(d);
		cout << "Chon chuc nang: "; cin >> ChucNang;

		switch (ChucNang) {
		case 1: {
			ifstream file;
			file.open("DSS.txt", ios::in);
			if (!file)
			{
				cout << "Khong co sach trong danh sach ! Kiem tra lai\n";
			}
			else {
				XuatDSS(d);
			}
			file.close();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			NhapDSS(d);
			break;
		}
		// Chinh sua thong tin sach
		case 3:
		{
			cout << "Chuc nang chinh sua thong tin sach\n";
			int q;
			cout << "Nhap ma ISBN: "; cin >> q;
			// Khong tim thay ma so sach trong thu vien
			if (!KiemTraMaSoSach(d, q))
			{
				int ChucNang2;
				cout << "Khong co so ISBN can tim\n";
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
			// Co tim thay ma so isbn trong thu vien
			else
			{
				int ChucNang3 = 1;
				while (ChucNang3 >= 1 && ChucNang3 <= 8) {

					NODES* p = TimKiemMaSoSach(d, q);
					cout << "== Chuc nang chinh sua thong tin sach ==\n";
					cout << "[1] : Chinh sua ten sach \n";
					cout << "[2] : Chinh sua ma isbn \n";
					cout << "[3] : Chinh sua ten tac gia\n";
					cout << "[4] : Chinh sua NXB\n";
					cout << "[5] : Chinh sua nam xuat ban \n";
					cout << "[6] : Chinh sua the loai sach \n";
					cout << "[7] : Chinh sua so quyen sach \n";
					cout << "[8] : Chinh sua so gia sach \n";
					cout << "[9] : Luu chinh sua ! Du lieu cu se mat \n";
					cout << "[10] : Quay lai Menu chinh \n";
					cout << "Nhap chuc nang: "; cin >> ChucNang3;
					switch (ChucNang3)
					{
						/* chuc nang chinh sua ten sach
						nhan vao : ma ten sach moi*/
					case 1:
					{
						int ChucNang2;
						cout << "Nhap gia tri ten sach moi: "; getline(cin, p->tts.tensach);
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
					Chuc nang chinh sua ma isbn
					nhan vao: ma isbn moi
					*/
					case 2:
					{
						int ChucNang2;
						cout << "Nhap vao ma isbn moi: "; cin >> p->tts.isbn;
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
					Chinh sua ten tac gia
					nhap vao : ten tac gia moi
					*/
					case 3:
					{
						int ChucNang2;
						cin.ignore();
						cout << "Nhap vao ten tac gia moi: "; getline(cin, p->tts.tacgia);
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
					Chinh sua NXB
					nhan vao : NXB moi
					*/
					case 4:
					{
						cin.ignore();
						int ChucNang2;
						cout << "Nhap gia tri NXB moi: "; getline(cin, p->tts.nxb);
						cout << "Chinh sua Thanh cong! ";
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
					Chinh sua nam xuat ban
					nhan vao : nam xuat ban moi
					*/
					case 5: {
						int ChucNang2;
						cout << "Nhap gia tri nam xuat ban moi: "; cin >> p->tts.namxuatban;
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
					Chinh sua the loai
					nhan vao : the loai sinh moi
					*/
					case 6: {
						cin.ignore();
						int ChucNang2;
						cout << "Nhap gia tri the loai moi: "; getline(cin, p->tts.theloai);
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
					Chinh sua so quyen sach
					nhan vao : so quyen sach moi
					*/
					case 7: {
						int ChucNang2;
						cout << "Nhap gia tri so quyen sach moi: "; cin >> p->tts.soquyensach;
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
						  Chinh sua gia sach
						  nhan vao : gia sach moi
						  */
					case 8: {
						int ChucNang2;
						cout << "Nhap gia sach moi: "; cin >> p->tts.giasach;
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
					case 9:
					{
						ofstream fileOut("DSS.txt", ios::out);
						NODES* p = d.pHead;
						while (p != NULL) {
							LuuVaoTepTin(p->tts, fileOut);
							p = p->pNext;
						}
						break;

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
		//	Xoa thong tin sach
		case 4:
		{
			int q;
			cout << "Nhap ma isbn sach can xoa: "; cin >> q;
			if (KiemTraMaSoSach(d, q)) {
				XoaThongTinSach(d, q);
				ofstream fileOut("DSS.txt", ios::out);
				NODES* p = d.pHead;
				while (p != NULL) {
					LuuVaoTepTin(p->tts, fileOut);
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
		Tim kiem sach bang ma isbn
		*/
		case 5:
		{
			int q;
			cout << "Nhap ma so isbn sach can tiem kiem: "; cin >> q;
			NODES* p = TimKiemMaSoSach(d, q);
			if (p != NULL) {
				XuatThongTinSach(p->tts);
				system("pause");
				break;

			}
			else {
				cout << "Khong ton tai CMND ! Kiem tra lai !\n";
				system("pause");
				break;
			}
		}
		/*
		Tiem kiem sach theo ten sach
		*/
		case 6:
		{
			string q;
			cin.ignore();
			cout << "Nhap ten sach can tiem kiem: "; getline(cin, q);
			NODES* p = TimKiemSachTheoTen(d, q);
			if (p != NULL) {
				XuatThongTinSach(p->tts);
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