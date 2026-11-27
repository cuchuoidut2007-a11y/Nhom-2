#include <iostream>
#include <string>

using namespace std;

    void sapXep() {
        for (int i = 0; i < so_luong - 1; i++) {
            for (int j = i + 1; j < so_luong; j++) {
                if (mang_lich_hoc[i].layThu() > mang_lich_hoc[j].layThu() ||
                   (mang_lich_hoc[i].layThu() == mang_lich_hoc[j].layThu() && 
                    mang_lich_hoc[i].layTietBatDau() > mang_lich_hoc[j].layTietBatDau())) 
                {
                    LichHoc tam = mang_lich_hoc[i];
                    mang_lich_hoc[i] = mang_lich_hoc[j];
                    mang_lich_hoc[j] = tam;
                }
            }
        }
        cout << "\n=> Da sap xep xong! Ban hay chon in danh sach de xem.\n";
    }

    void timKiem() {
        int chon;
        cout << "\n1. Tim theo Ma lop\n2. Tim theo Ten mon\nChon cach tim (1 hoac 2): ";
        cin >> chon;
        cin.ignore(1000, '\n');

        string tu_khoa;
        cout << "Nhap tu khoa can tim: ";
        getline(cin, tu_khoa);

        bool thay = false;
        cout << "\n--- KET QUA TIM KIEM ---\n";
        for (int i = 0; i < so_luong; i++) {
            if ((chon == 1 && mang_lich_hoc[i].layMaLop() == tu_khoa) || 
                (chon == 2 && mang_lich_hoc[i].layTenMon() == tu_khoa)) {
                mang_lich_hoc[i].inThongTin();
                thay = true;
            }
        }
        
        if (thay == false) {
            cout << "=> Khong tim thay lich hoc nao.\n";
        }
    }
