#pragma once
#include"QuanLyDocGia.h"
#include "QuanLySach.h"

struct PhieuMuonSach
{
	int ngaymuon, thangmuon, nammuon, ngaytradukien, thangtradukien, namtradukien;
	int ngaytrathucte, thangtrathucte, namtrathucte, madocgia, masach;
};
typedef struct PhieuMuonSach PHIEUMUONSACH;

struct nodePMS {
	PHIEUMUONSACH pms;
	nodePMS* pNext;
};
typedef struct nodePMS NODE_PMS;

struct DanhSachPhieuMuonSach
{
	NODE_PMS* pHead;
	NODE_PMS* pTail;
};
typedef struct DanhSachPhieuMuonSach DSPMS;

void KhoiTao(DSPMS& d);
NODE_PMS* KhoiTaoNode_pms(PHIEUMUONSACH pms);
void ThemVaoCuoi(DSPMS& d, NODE_PMS* p);

int CheckMaSoDocGia(DSDG d, int maso);
int CheckMaSoSach(DSS d, int maso);
void NhapPhieuMuonSach(PHIEUMUONSACH& pms);
int ThoiGianTraDuKien(PHIEUMUONSACH& pms);
void LuuVaoTepTinMuonSach(PHIEUMUONSACH p, ofstream& fileOut);
void XuatPhieuMuonSach(PHIEUMUONSACH pms);
void NhapDSPMS(DSPMS& dspms, DSS d, DSDG DanhSach);
void XuatDSPMS(DSPMS dspms);
void DocPhieuMuonSach(ifstream& file, PHIEUMUONSACH& p);
void DocDSPMS(DSPMS& dspms);
void menuQuanLyPMS(DSPMS dspms, DSS dss, DSDG dsdg);

// ============== //


struct PhieuTraSach
{
	// mdgts: ma doc gia tra sach, mst: ma sach tra.
	int mdgts, mst, ngaytrathucte, thangtrathucte, namtrathucte, tien;
};
typedef struct PhieuTraSach PHIEUTRASACH;

struct nodePTS {
	PHIEUTRASACH pts;
	nodePTS* pNext;
};
typedef struct nodePTS NODE_PTS;

struct DanhSachPhieuTS
{
	nodePTS* pHead;
	nodePTS* pTail;
	
};
typedef struct DanhSachPhieuTS DSPTS;

void KhoiTao(DSPTS& d);
NODE_PTS* KhoiTaoNode_pts(PHIEUTRASACH pms);
void ThemVaoCuoi(DSPTS& d, NODE_PTS* p);
 
int KiemTraMaDocGiaTraSach(DSPMS dspms, int maso);
NODE_PMS* TimKiemMaDocGiaTraSach(DSPMS dspms, int maso);
int KiemtraMaSachTra(DSPMS dspms, int maso);
int KiemTraNgayTrongThang(int Thang, int Nam);
int KiemTraNamCoBaoNhieuNgay(int q);
void LuuVaoTepTinTraSach(PHIEUTRASACH pts, ofstream& fileOut);
void DocPhieuTraSach(ifstream& file, PHIEUTRASACH& p);
void DocDSPTS(DSPTS& dspts);
void XuatDSPTS(DSPTS dspts);
void XuatPhieuTraSach(PHIEUTRASACH pts);
void NhapPhieuTraSach(PHIEUTRASACH& pts);
void NhapDSPTS(DSPTS& dspts, DSPMS dspms, DSS d);
void LuuDanhSachMatSach(PHIEUTRASACH pts, ofstream& fileOut);
void menuQuanLyPTS(DSPTS dspts, DSPMS dspms, DSS dss, DSDG dsdg);