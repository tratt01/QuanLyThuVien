#include "QuanLyDocGia.h"
#include "QuanLySach.h"
#include "QuanLyPhieuTraMuon.h"
void menu(DSDG dsdg, DSS dss, DSPMS dspms, DSPTS dspts) {
	system("cls");

	int luachon = 1;

	while (luachon >= 1 || luachon <= 4) {
		system("cls");
		cout << "------------------------- BANG CHUC NAM THU VIEN -------------------------\n ";
		cout << "[1] : Quan li doc gia\n ";
		cout << "[2] : Quan li sach \n ";
		cout << "[3] : Lap phieu muon sach\n ";
		cout << "[4] : Lap phieu tra sach \n ";
		cout << "[5] : Thoat khoi chuong trinh\n";
		cout << "Nhap lua chon: "; cin >> luachon;

		switch (luachon) {
		case 1: {
			menuDocGia(dsdg);
			break;
		}
		case 2: {
			menuSach(dss);
			break;
		}
		case 3: {
			menuQuanLyPMS(dspms, dss, dsdg);
			break;
		}
		case 4: {
			menuQuanLyPTS(dspts, dspms, dss, dsdg);
			break;
		}
		default: {
			exit(0);
		}
		}
	}
}

int main() {
	DSDG dsdg;
	DSS dss;
	DSPMS dspms;
	DSPTS dspts;
	KhoiTao(dsdg);
	KhoiTao(dss);
	KhoiTao(dspms);
	KhoiTao(dspts);
	//menuQuanLyPTS(dspts, dspms, dss, dsdg);
	menu(dsdg, dss, dspms, dspts);
}