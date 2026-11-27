
    void nhapDanhSach() {
        do {
            cout << "Ban muon nhap bao nhieu lich hoc (0 < n < 200)? n = ";
            cin >> so_luong;
            cin.ignore(1000, '\n');
            if (so_luong <= 0 || so_luong >= 200) {
                cout << "So luong sai roi, nhap lai nhe!\n";
            }
        } while (so_luong <= 0 || so_luong >= 200);

        for (int i = 0; i < so_luong; i++) {
            cout << "\n--- Nhap lich hoc thu " << i + 1 << " ---\n";
            mang_lich_hoc[i].nhapThongTin();
        }
    }

    void inDanhSach() {
        if (so_luong == 0) {
            cout << "Danh sach dang trong!\n";
            return;
        }
        cout << "MA LICH\t| TEN MON\t| MA LOP\t| GIANG VIEN\t| THU\t| TIET BD\t| SO TIET\t| PHONG\n";
        cout << "--------------------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < so_luong; i++) {
            mang_lich_hoc[i].inThongTin();
        }
    }

int main() {
    QuanLyDanhSach ql;

    cout << "===============================================\n";
    cout << "    CHUONG TRINH QUAN LY LICH HOC!\n";
    cout << "===============================================\n";
    cout << "Truoc tien, ban can khoi tao danh sach lich hoc.\n";
    
    ql.nhapDanhSach();

    cout << "\n=================================================\n";
    cout << "      DANH SACH LICH HOC BAN VUA NHAP LA:\n";
    cout << "=================================================\n";
    ql.inDanhSach();

    int lua_chon;
    do {
        cout << "\n=================== MENU ===================\n";
        cout << "1. Xem danh sach lich hoc (dang bang)\n";
        cout << "2. Sap xep danh sach (theo Thu va Tiet)\n";
        cout << "3. Tim kiem lich hoc (theo Ma lop/Ten mon)\n";
        cout << "4. Bo sung (Them) 1 lich hoc vao danh sach\n";
        cout << "5. Xoa 1 lich hoc khoi danh sach\n";
        cout << "6. Sua thong tin 1 lich hoc\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "============================================\n";
        cout << "Chon chuc nang (0-6)? ";
        cin >> lua_chon;
        cin.ignore(1000, '\n'); 

        if (lua_chon == 1) {
            ql.inDanhSach();
        } 
        else if (lua_chon == 2) {
            ql.sapXep();
        } 
        else if (lua_chon == 3) {
            ql.timKiem();
        } 
        else if (lua_chon == 4) {
            ql.themLich();
        } 
        else if (lua_chon == 5) {
            ql.xoaLich();
        } 
        else if (lua_chon == 6) {
            ql.suaLich();
        }
        else if (lua_chon == 0) {
            cout << "Cam on ban da su dung chuong trinh. Tam biet!\n";
        } 
        else {
            cout << "Lua chon sai, vui long nhap lai!\n";
        }

    } while (lua_chon != 0);

    return 0;
}

