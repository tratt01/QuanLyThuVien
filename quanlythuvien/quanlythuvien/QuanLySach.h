#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct ThongTinSach {
	string tensach, tacgia, nxb, theloai;
	int giasach, soquyensach, namxuatban, isbn;
};
typedef struct ThongTinSach THONGTINSACH;

struct nodeS {
	THONGTINSACH tts;
	nodeS* pNext;
};
typedef struct nodeS NODES;

struct DanhSachSach
{
	NODES* pHead;
	NODES* pTail;;
};
typedef struct DanhSachSach DSS;

void KhoiTao(DSS& d);
NODES* KhoiTaoNode(THONGTINSACH t);
void ThemVaoCuoi(DSS& d, NODES* p);

void LuuVaoTepTin(THONGTINSACH tt, ofstream& fileOut);
void NhapThongTinSach(THONGTINSACH& tt);
void NhapDSS(DSS& d);
void XuatThongTinSach(THONGTINSACH tt);
void XuatDSS(DSS d);
bool KiemTraMaSoSach(DSS d, int q);
NODES* TimKiemMaSoSach(DSS d, int q);
NODES* TimKiemSachTheoTen(DSS d, string q);
void DocThongTinSach(ifstream& file, THONGTINSACH& tt);
void DocThongTinNhieuSach(DSS& d);
void ThongKeSachTheoTheLoai(DSS d);

void menuSach(DSS d);