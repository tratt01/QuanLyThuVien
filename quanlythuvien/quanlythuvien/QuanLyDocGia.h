#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct thongtindocgia {
	string hoten, gioitinh, email, diachi;
	int ngaysinh, thangsinh, namsinh, madocgia, cmnd, ngaymuon, thangmuon, nammuon, ngayhet, thanghet, namhet;
};
typedef struct thongtindocgia THONGTINDOCGIA;

void NhapThongTinDocGia(THONGTINDOCGIA& t);
int KiemTraNgayThangNam(int& CheckNgay, int& CheckThang, int& CheckNam);

struct node {
	THONGTINDOCGIA ttdg;
	node* pNext;
};
typedef struct node NODE;

struct danhsachdocgia {
	NODE* pHead;
	NODE* pTail;
};
typedef struct danhsachdocgia DSDG;

void KhoiTao(DSDG& d);
NODE* KhoiTaoNode(THONGTINDOCGIA t);
void ThemVaoCuoi(DSDG& d, NODE* p);

void NhapDSDG(DSDG& d);
void XuatThongTinDocGia(THONGTINDOCGIA t);
void XuatDSDG(DSDG d);
void DocThongTinMotDocGia(ifstream& fileIn, THONGTINDOCGIA& t);
void DocThongTinNhieuDocGia(DSDG& d);
void LuuVaoTiepTin(THONGTINDOCGIA t, ofstream& fileOut);
int NhapMaSo();
int NhapCmnd();
string NhapHoTen();
bool KiemTraMaSo(DSDG d, int q);
NODE* TimKiemBangCmnd(DSDG d);
NODE* TimKiemBangHoTen(DSDG d);
void XoaThongTinDocGia(DSDG& d, int maso);
void menuDocGia(DSDG d);

