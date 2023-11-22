#include "QuanLyPhieuTraMuon.h"

void KhoiTao(DSPMS& d) {
	d.pHead = d.pTail = NULL;
}
void KhoiTao(DSPTS& d) {
	d.pHead = d.pTail = NULL;
}
NODE_PMS* KhoiTaoNode_pms(PHIEUMUONSACH pms) {
	NODE_PMS* p = new NODE_PMS;
	if (p == NULL) {
		cout << "Khong du bo nho";
		return NULL;
	}
	p->pms = pms;
	p->pNext = NULL;
	return p;
}
NODE_PTS* KhoiTaoNode_pts(PHIEUTRASACH pts) {
	NODE_PTS* p = new NODE_PTS;
	if (p == NULL) {
		cout << "Khong du bo nho";
		return NULL;
	}
	p->pts = pts;
	p->pNext = NULL;
	return p;
}

void ThemVaoCuoi(DSPMS& d, NODE_PMS* p) {
	if (d.pHead == NULL) {
		d.pHead = d.pTail = p;
	}
	else {
		d.pTail->pNext = p;
		d.pTail = p;
	}
}
void ThemVaoCuoi(DSPTS& d, NODE_PTS* p) {
	if (d.pHead == NULL) {
		d.pHead = d.pTail = p;
	}
	else {
		d.pTail->pNext = p;
		d.pTail = p;
	}
}

int CheckMaSoDocGia(DSDG d, int maso) {
	NODE* p = d.pHead;
	while (p != NULL) {
		if (p->ttdg.madocgia == maso) {
			return maso;
		}
		p = p->pNext;
	}
	return 0;
}

int CheckMaSoSach(DSS d, int maso) {
	NODES* p = d.pHead;
	while (p != NULL) {
		if (p->tts.isbn == maso) {
			return maso;
		}
		p = p->pNext;
	}
	return 0;
}

void NhapPhieuMuonSach(PHIEUMUONSACH& pms) {
	int q1 = KiemTraNgayThangNam(pms.ngaymuon, pms.thangmuon, pms.nammuon);
	int q2 = ThoiGianTraDuKien(pms);
}

int ThoiGianTraDuKien(PHIEUMUONSACH& pms) {
	// Thang muon la thang le -12;
	if ((pms.thangmuon == 1 || pms.thangmuon == 3 || pms.thangmuon == 5 || pms.thangmuon == 7 || pms.thangmuon == 8 || pms.thangmuon == 10))
	{
		if (pms.ngaymuon < 25)
		{
			pms.ngaytradukien = pms.ngaymuon + 7;
			pms.thangtradukien = pms.thangmuon;
			pms.namtradukien = pms.nammuon;

		}
		else {
			pms.ngaytradukien = (pms.ngaymuon + 7) - 31;
			pms.thangtradukien = pms.thangmuon + 1;
			pms.namtradukien = pms.nammuon;

		}
	}
	// thang muon la thang chan tru thang 2
	else if ((pms.thangmuon == 4 || pms.thangmuon == 3 || pms.thangmuon == 6 || pms.thangmuon == 9 || pms.thangmuon == 11))
	{
		if (pms.ngaymuon < 24)
		{
			pms.ngaytradukien = pms.ngaymuon + 7;
			pms.thangtradukien = pms.thangmuon;
			pms.namtradukien = pms.nammuon;
		}
		else {
			pms.ngaytradukien = (pms.ngaymuon + 7) - 30;
			pms.thangtradukien = pms.thangmuon + 1;
			pms.namtradukien = pms.nammuon;
		}
	}
	// Thang muon la thang 12
	else if (pms.thangmuon == 12)
	{
		if (pms.ngaymuon < 25)
		{
			pms.ngaytradukien = pms.ngaymuon + 7;
			pms.thangtradukien = pms.thangmuon;
			pms.namtradukien = pms.nammuon;
		}
		else
		{
			pms.ngaytradukien = (pms.ngaymuon + 7) - 31;
			pms.thangtradukien = 1;
			pms.namtradukien = pms.nammuon + 1;
		}
	}
	// thang muon la thang 2
	else if (pms.thangmuon == 2)
	{
		if (pms.nammuon % 4 == 0)
		{
			if (pms.ngaymuon < 23)
			{
				pms.ngaytradukien = pms.ngaymuon + 7;
				pms.thangtradukien = pms.thangmuon;
				pms.namtradukien = pms.nammuon;
			}
			else
			{
				pms.ngaytradukien = (pms.ngaymuon + 7) - 29;
				pms.thangtradukien = pms.thangmuon + 1;
				pms.namtradukien = pms.nammuon;
			}
		}
		else
		{
			if (pms.ngaymuon < 22)
			{
				pms.ngaytradukien = pms.ngaymuon + 7;
				pms.thangtradukien = pms.thangmuon;
				pms.namtradukien = pms.nammuon;
			}
			else
			{
				pms.ngaytradukien = (pms.ngaymuon + 7) - 28;
				pms.thangtradukien = pms.thangmuon + 1;
				pms.namtradukien = pms.nammuon;
			}
		}
	}
	return -1;
}

void LuuVaoTepTinMuonSach(PHIEUMUONSACH pms, ofstream& fileOut) {
	if (fileOut.fail()) {
		cout << "Cannot open file at PMS.txt" << endl;
		return;
	}
	fileOut << "\n" << pms.madocgia << ", " << pms.masach << ", ";
	fileOut << pms.ngaymuon << "-" << pms.thangmuon << "-" << pms.nammuon << ", ";
	fileOut << pms.ngaytradukien << "-" << pms.thangtradukien << "-" << pms.namtradukien << "\n";
}

void NhapDSPMS(DSPMS& dspms, DSS dss, DSDG dsdg) {
	int n;
	cout << "Nhap so luong phieu muon sach: "; cin >> n;
	for (int i = 0; i < n; i++) {
		int maso;
		cout << "Nhap ma so doc gia can muon: "; cin >> maso;
		int madocgia = CheckMaSoDocGia(dsdg, maso);
		cout << "Nhap ma so ISBN can muon: "; cin >> maso;
		int masosach = CheckMaSoSach(dss, maso);
		if (madocgia != 0 && masosach != 0) {
			ofstream fileOut("PMS.txt", ios::app);
			PHIEUMUONSACH pms; 
			pms.madocgia = madocgia;
			pms.masach = masosach;
			NhapPhieuMuonSach(pms);
			NODE_PMS* p = KhoiTaoNode_pms(pms);
			ThemVaoCuoi(dspms, p);
			LuuVaoTepTinMuonSach(pms, fileOut);
		}
	}
	
}

void menuQuanLyPMS(DSPMS dspms, DSS dss, DSDG dsdg) {
	int ChucNang = 1;
	while (ChucNang >= 1 && ChucNang <= 2) {
		system("cls");
		cout << "---------- QUAN LI PHIEU MUON SACH ----------\n";
		cout << "[1] : Xem danh sach phieu muon sach\n";
		cout << "[2] : Them phieu muon sach\n";
		cout << "[3] : Tro ve Menu\n";
		cout << "Nhap chuc nang: "; cin >> ChucNang;

		KhoiTao(dspms);
		DocDSPMS(dspms);
		KhoiTao(dss);
		DocThongTinNhieuSach(dss);
		KhoiTao(dsdg);
		DocThongTinNhieuDocGia(dsdg);
		switch (ChucNang) {
		case 1: {
			ifstream file;
			file.open("PMS.txt", ios::in);
			if (!file)
			{
				cout << "Khong co sach trong danh sach ! Kiem tra lai\n";
			}
			else {
				XuatDSPMS(dspms);
			}
			file.close();
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			NhapDSPMS(dspms, dss, dsdg);
			break;
		}
		default: {
			break;
		}

		}
	}
}

// ================== //

void XuatPhieuMuonSach(PHIEUMUONSACH pms) {
	cout << "\nMa doc gia muon sach: " << pms.madocgia << endl;
	cout << "Ma ISBN muon sach: " << pms.masach << endl;;
	cout << "Thoi gian muon sach: " << pms.ngaymuon << "-" << pms.thangmuon << "-" << pms.nammuon << endl;
	cout << "Thoi gian tra du kien: " << pms.ngaytradukien << "-" << pms.thangtradukien << "-" << pms.namtradukien << endl;
}

void XuatDSPMS(DSPMS dspms) {
	int i = 0;
	NODE_PMS* p = dspms.pHead;
	while (p != NULL) {
		cout << "======= Phieu muon sach thu " << ++i << " =======";
		XuatPhieuMuonSach(p->pms);
		p = p->pNext;
	}
}
void DocPhieuMuonSach(ifstream& file, PHIEUMUONSACH& p) {
	string temp;
	getline(file, temp);
	file >> p.madocgia;
	file.seekg(1, 1);
	file.seekg(1, 1);
	file >> p.masach;
	file.seekg(1, 1);
	file >> p.ngaymuon;
	file.seekg(1, 1);
	file >> p.thangmuon;
	file.seekg(1, 1);
	file >> p.nammuon;
	file.seekg(1, 1);
	file.seekg(1, 1);
	file >> p.ngaytradukien;
	file.seekg(1, 1);
	file >> p.thangtradukien;
	file.seekg(1, 1);
	file >> p.namtradukien;

	
}

void DocDSPMS(DSPMS& d) {
	ifstream fileIn;
	fileIn.open("PMS.txt", ios::in);
	while (!fileIn.eof()) {
		PHIEUMUONSACH pms;
		DocPhieuMuonSach(fileIn, pms);
		NODE_PMS* p = KhoiTaoNode_pms(pms);

		if (p->pms.madocgia <= 0) {
			break;
		}
		ThemVaoCuoi(d, p);
	}
	fileIn.close();
}

int KiemTraMaDocGiaTraSach(DSPMS d, int maso) {
	NODE_PMS* p = d.pHead;
	while (p != NULL) {
		if (p->pms.madocgia == maso) {
			return maso;
		}
		p = p->pNext;
	}
	return 0;
}
int KiemtraMaSachTra(DSPMS d, int maso) {
	NODE_PMS* p = d.pHead;
	while (p != NULL) {
		if (p->pms.masach == maso) {
			return maso;
		}
		p = p->pNext;
	}
	return 0;
}

NODE_PMS* TimKiemMaDocGiaTraSach(DSPMS d, int maso) {
	NODE_PMS* p = d.pHead;
	while (p != NULL) {
		if (p->pms.madocgia == maso) {
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}


int TinhTien(PHIEUMUONSACH pms, PHIEUTRASACH& pts) {
	int q4 = 0;
	int qi = KiemTraNgayThangNam(pts.ngaytrathucte, pts.thangtrathucte, pts.namtrathucte);
	int q = KiemTraNgayTrongThang(pms.thangtradukien, pms.namtradukien);
	// So sanh ngay tra du kien voi ngay muon va ngay tra thuc te
	int q1 = pms.ngaytradukien + pms.thangtradukien * 100 + pms.namtradukien * 10000;
	int q2 = pts.ngaytrathucte + pts.thangtrathucte * 100 + pts.namtrathucte * 10000;
	int q3 = pms.ngaymuon + pms.thangmuon * 100 + pms.nammuon * 10000;
	int Hieu1 = q2 - q1;
	int Hieu2 = q2 - q3;
	// Nam Tra thuc te = nam tra du kien
	if (Hieu1 > 0 && pts.namtrathucte == pms.namtradukien)
	{
		// thang tra thuc te > thang tra du kien
		if (pts.thangtrathucte > pms.thangtradukien)
		{
			q4 = q - pms.ngaytradukien;
			int ThangTiep = pms.thangtradukien + 1;
			for (int i = 0;; i++)
			{
				if (ThangTiep < pts.thangtrathucte)
				{
					int q = KiemTraNgayTrongThang(ThangTiep, pms.namtradukien);
					q4 = q4 + q;
					ThangTiep++;
				}
				else if (ThangTiep >= pts.thangtrathucte)
				{
					q4 = q4 + pts.ngaytrathucte;
					break;
				}
			}
		}
		// thang tra thuc te == thang tra du kien
		else if (pts.thangtrathucte == pms.thangtradukien)
		{
			q4 = pts.ngaytrathucte - pms.ngaytradukien;
		}
	}
	// Tra dung ngay
	else if (Hieu1 < 0 && Hieu2 > 0)
	{
		q4 = 0;
	}
	// Ngay thang nam tra lon hon du kien Nhung khac nam
	else if (Hieu1 > 0 && (pms.namtradukien != pts.namtrathucte))
	{
		int TongTam = 0;
		for (int i = pms.namtradukien; i < pts.namtrathucte; i++)
		{
			int z = KiemTraNamCoBaoNhieuNgay(pms.namtradukien);
			TongTam = TongTam + z;
		}

		if (pts.thangtrathucte > pms.thangtradukien)
		{
			q4 = TongTam;
			int q1 = KiemTraNgayTrongThang(pms.thangtradukien, pts.namtrathucte);
			q4 = q4 + (q - pms.ngaytradukien);
			int ThangTiep = pms.thangtradukien + 1;
			for (int i = 0;; i++)
			{
				if (ThangTiep < pts.thangtrathucte)
				{
					int q = KiemTraNgayTrongThang(ThangTiep, pts.namtrathucte);
					q4 = q4 + q;
					ThangTiep++;
				}
				else if (ThangTiep >= pts.thangtrathucte)
				{
					q4 = q4 + pts.ngaytrathucte;
					break;
				}
			}
		}
		else  if (pts.thangtrathucte == pms.thangtradukien)
		{
			q4 = TongTam;
			q4 = q4 + (pts.ngaytrathucte - pms.ngaytradukien);
		}
		else if (pts.thangtrathucte < pms.thangtradukien)
		{
			int DemNgay1 = KiemTraNgayTrongThang(pms.thangtradukien, pms.namtradukien);
			q4 = DemNgay1 - pms.ngaytradukien;
			int ThangTiep = pms.thangtradukien + 1;
			for (int i = 0;; i++)
			{
				int CheckNgay = -1;
				int z5 = KiemTraNgayTrongThang(ThangTiep, pms.namtradukien);
				q4 = q4 + z5;

				if (ThangTiep == 12)
				{
					ThangTiep = 1;
					for (int k = 0;; k++)
					{
						int z6 = KiemTraNgayTrongThang(ThangTiep, pts.namtrathucte);
						q4 = q4 + z6;
						if (ThangTiep == pts.thangtrathucte)
						{
							q4 = q4 + pts.ngaytrathucte;
							CheckNgay = 0;
							break;
						}
						ThangTiep++;
					}
				}
				ThangTiep++;
				if (CheckNgay == 0)
				{
					break;
				}
			}
		}

	}
	// Tra thuc te < Ngay muon : Loi
	else if (Hieu2 <= 0)
	{
		q4 = 0;
	}

	pts.tien = (q4 == 0) ? 0 : q4 * 5000;
	system("cls");
	return pts.tien;
}

int KiemTraNgayTrongThang(int Thang, int Nam)
{
	int SoNgayTrongThang = -1;
	switch (Thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		SoNgayTrongThang = 31;
		break;
	}
	case 2:
	{
		if (Nam % 4 == 0)
		{
			SoNgayTrongThang = 29;
			break;
		}
		else {
			SoNgayTrongThang = 28;
			break;
		}
	}
	case 4: case 6: case 9: case 11:
	{
		SoNgayTrongThang = 30;
		break;
	}
	}
	return SoNgayTrongThang;
}

int KiemTraNamCoBaoNhieuNgay(int q)
{
	int SoNgay;
	if ((q % 4 == 0 && q % 100 != 0) || q % 400 == 0)
	{
		SoNgay = 366;
	}
	else
	{
		SoNgay = 365;
	}
	return SoNgay;
}

void LuuVaoTepTinTraSach(PHIEUTRASACH pts, ofstream& fileOut) {
	if (fileOut.fail()) {
		cout << "Cannot open file at PTS.txt" << endl;
		return;
	}
	fileOut << "\n" << pts.mdgts << ", " << pts.mst << ", ";
	fileOut << pts.ngaytrathucte << "-" << pts.thangtrathucte << "-" << pts.namtrathucte << ", ";
	fileOut << pts.tien;
}
void LuuDanhSachMatSach(PHIEUTRASACH pts, ofstream& fileOut) {
	if (fileOut.fail()) {
		cout << "Cannot open file at SACHBIMAT.txt" << endl;
		return;
	}
	fileOut << "\n" << pts.mdgts << ", " << pts.mst << ", ";
	fileOut << pts.ngaytrathucte << "-" << pts.thangtrathucte << "-" << pts.namtrathucte;
}

void DocPhieuTraSach(ifstream& file, PHIEUTRASACH& p) {
	string temp;
	getline(file, temp);

	file >> p.mdgts;
	file.seekg(1, 1); file.seekg(1, 1);
	file >> p.mst;
	file.seekg(1, 1); file.seekg(1, 1);
	file >> p.ngaytrathucte;
	file.seekg(1, 1);
	file >> p.thangtrathucte;
	file.seekg(1, 1);
	file >> p.namtrathucte;
	file.seekg(1, 1); file.seekg(1, 1);
	file >> p.tien;
}

void DocDSPTS(DSPTS& d) {
	ifstream fileIn;
	fileIn.open("PTS.txt", ios::in);
	while (!fileIn.eof()) {
		PHIEUTRASACH pts;
		DocPhieuTraSach(fileIn, pts);
		NODE_PTS* p = KhoiTaoNode_pts(pts);

		if (p->pts.mdgts <= 0) {
			break;
		}
		ThemVaoCuoi(d, p);
	}
	fileIn.close();
}

void XuatPhieuTraSach(PHIEUTRASACH pts) {
	cout << "\nMa doc gia tra sach: " << pts.mdgts << endl;
	cout << "Ma ISBN muon sach: " << pts.mst << endl;;
	cout << "Thoi gian tra du kien: " << pts.ngaytrathucte << "-" << pts.thangtrathucte << "-" << pts.namtrathucte << endl;
	cout << "Tien: " << pts.tien << endl;
}

void XuatDSPTS(DSPTS d) {
	int i = 0;
	NODE_PTS* p = d.pHead;
	while (p != NULL) {
		cout << "======= Phieu tra sach thu " << ++i << " =======";
		XuatPhieuTraSach(p->pts);
		p = p->pNext;
	}
}

void XuatSachBiMat() {
	PHIEUTRASACH pts;
	int i = 0;
	ifstream file;
	file.open("SACHBIMAT.txt");
	while (!file.eof()) {
		string temp;
		getline(file, temp);
		cout << "\n======= Sach bi mat thu " << ++i << " =======";
		cout << "\nMa doc gia lam mat: ";
		file >> pts.mdgts; cout << pts.mdgts; file.seekg(1, 1); file.seekg(1, 1);
		cout << "\nMa ISBN sach bi mat: ";
		file >> pts.mst; cout << pts.mst; file.seekg(1, 1); file.seekg(1, 1);
		cout << "\nNgay bao mat: ";
		file >> pts.ngaytrathucte; file.seekg(1, 1);
		file >> pts.thangtrathucte; file.seekg(1, 1);
		file >> pts.namtrathucte;
		cout << pts.ngaytrathucte << "-" << pts.thangtrathucte << "-" << pts.namtrathucte << endl;
	}
}

void NhapPhieuTraSach(PHIEUTRASACH& pts) {
	int q = KiemTraNgayThangNam(pts.ngaytrathucte, pts.thangtrathucte, pts.namtrathucte);
}

void NhapDSPTS(DSPTS& dspts, DSPMS dspms, DSS dss) {
	int n;
	cout << "Nhap so luong phieu muon tra: "; cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "------THONG TIN PHIEU TRA SACH " << i + 1 << "------\n";
		int maso;
		cout << "Nhap ma so doc gia can tra: "; cin >> maso;
		int madocgia = KiemTraMaDocGiaTraSach(dspms, maso);

		NODE_PMS* node_PMS = TimKiemMaDocGiaTraSach(dspms, maso);

		cout << "Nhap ma so ISBN sach can tra: "; cin >> maso;
		int masosach = KiemtraMaSachTra(dspms, maso);

		if (madocgia != 0 && masosach != 0) {
			ofstream fileOut("PTS.txt", ios::app);
			PHIEUTRASACH pts;
			pts.mdgts = madocgia;
			pts.mst = masosach;

			int chucnang;
			cout << "[1] : Bao mat sach\n";
			cout << "[2] : Nhap ngay tra sach\n";
			cout << "Chon chuc nang : "; cin >> chucnang;
			
			if (chucnang == 2)
			{
				int q2 = TinhTien(node_PMS->pms, pts);
				LuuVaoTepTinTraSach(pts, fileOut);
				NODE_PTS* node_PTS = KhoiTaoNode_pts(pts);
				ThemVaoCuoi(dspts, node_PTS);
			}
			else {
				NODES* node_S = dss.pHead;
				while (node_S != NULL) {
					if (pts.mst == node_S->tts.isbn) {
						int q4 = KiemTraNgayThangNam(pts.ngaytrathucte, pts.thangtrathucte, pts.namtrathucte);
						pts.tien = node_S->tts.giasach * 2;
						LuuVaoTepTinTraSach(pts, fileOut);
						ofstream fileOut("SACHBIMAT.txt", ios::app);
						LuuDanhSachMatSach(pts, fileOut);
						NODE_PTS* node_PTS = KhoiTaoNode_pts(pts);
						ThemVaoCuoi(dspts, node_PTS);
					}
					node_S = node_S->pNext;
				}

			}

		}
		else {
			cout << "Khong ton tai ma doc gia hoac ma sach tra";
			system("pause");
		}
	}
}

void menuQuanLyPTS(DSPTS dspts, DSPMS dspms, DSS dss, DSDG dsdg) {
	int ChucNang = 1;
	while (ChucNang >= 1 && ChucNang <= 2) {
		system("cls");
		cout << "---------- QUAN LI PHIEU TRA SACH ----------\n";
		cout << "[1] : Xem danh sach phieu tra sach\n";
		cout << "[2] : Them phieu tra sach\n";
		cout << "[3] : Tro ve Menu\n";
		cout << "Nhap chuc nang: "; cin >> ChucNang;

		KhoiTao(dspms);
		DocDSPMS(dspms);
		KhoiTao(dspts);
		DocDSPTS(dspts);
		KhoiTao(dss);
		DocThongTinNhieuSach(dss);
		KhoiTao(dsdg);
		DocThongTinNhieuDocGia(dsdg);

		switch (ChucNang) {
		case 1: {
			if (dspts.pHead == NULL)
				cout << "Khong co sach trong danh sach ! Kiem tra lai\n";
			else {
				XuatDSPTS(dspts);
				XuatSachBiMat();
				break;
			}
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			NhapDSPTS(dspts, dspms, dss);
			break;
		}
		default: {
			break;
		}

		}
	}
}