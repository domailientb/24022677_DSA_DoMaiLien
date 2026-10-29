#include <iostream>
#include <vector>
#include <list>
using namespace std;

class BangBam {
private:
    int soO;                       
    vector<list<int>> bang;        

    // Dua khoa ve vi tri trong bang
    int tinhViTri(int khoa) {
        return khoa % soO;
    }

public:
    // tạo bảng băm có n ô
    BangBam(int n) {
        soO = n;
        bang.resize(n);
    }

    // thêm kháo vào ds vtri băm
    void themKhoa(int khoa) {
        int viTri = tinhViTri(khoa);

        // nt khóa vào cuối ds
        bang[viTri].push_back(khoa);
    }

    // tìm khóa trog ds tươg ưgs
    bool timKhoa(int khoa) {
        int viTri = tinhViTri(khoa);

        // duyệt ds tại vtri băm
        for (int giaTri : bang[viTri]) {
            if (giaTri == khoa) {
                return true;
            }
        }
        return false;
    }

    // xóa các lần xh khóa
    void xoaKhoa(int khoa) {
        int viTri = tinhViTri(khoa);
        bang[viTri].remove(khoa);
    }

    // in
    void inBang() {
        cout << "\n===== BANG BAM =====\n";
        for (int i = 0; i < soO; i++) {
            cout << "O[" << i << "]";
            for (int khoa : bang[i]) {
                cout << " -> " << khoa;
            }

            cout << " -> NULL\n";
        }
    }
};


int main() {
    BangBam ds(7);

    ds.themKhoa(12);  // 12 % 7 = 5
    ds.themKhoa(19);  // 19 % 7 = 5, va cham
    ds.themKhoa(8);   // 8 % 7 = 1
    ds.themKhoa(26);  // 26 % 7 = 5, cung o 5
    ds.themKhoa(15);  // 15 % 7 = 1, va cham
    ds.themKhoa(31);  // 31 % 7 = 3

    cout << "Bang bam sau khi them:";
    ds.inBang();

    // Kiem tra tim kiem
    cout << "\nTim 26: "
         << (ds.timKhoa(26) ? "Tim thay" : "Khong thay")
         << '\n';

    cout << "Tim 40: "
         << (ds.timKhoa(40) ? "Tim thay" : "Khong thay")
         << '\n';

    // Xoa khoa 19
    ds.xoaKhoa(19);
    cout << "\nBang bam sau khi xoa 19:";
    ds.inBang();

    // Kiem tra lai sau khi xoa
    cout << "\nTim 19: "
         << (ds.timKhoa(19) ? "Tim thay" : "Khong thay")
         << '\n';
    cout << "Tim 26: "
         << (ds.timKhoa(26) ? "Tim thay" : "Khong thay")
         << '\n';

    return 0;
}

