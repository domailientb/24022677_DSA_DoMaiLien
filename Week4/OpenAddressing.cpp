#include <iostream>
#include <vector>
using namespace std;

enum TrangThai {
    TRONG,      
    DA_XOA,     
    CO_DU_LIEU  
};

class BangBam {
private:
    int kichThuoc;
    vector<int> duLieu;
    vector<TrangThai> trangThai;

    // tíh vtri ban đầu of khóa
    int bam(int khoa) {
        return khoa % kichThuoc;
    }

public:
    // khởi tạo bảng băm vs n ô
    BangBam(int n) {
        kichThuoc = n;
        duLieu.resize(n, 0);
        trangThai.resize(n, TRONG);
    }

    // thêm 1 khóa vào bảg băm
    void them(int khoa) {
        int viTri = bam(khoa);

        // duyệt lần lượt các ô tiếp theo nếu bị trùg
        for (int buoc = 0; buoc < kichThuoc; buoc++) {
            int o = (viTri + buoc) % kichThuoc;

            // nếu đã có khóa thì 0 thêm 
            if (trangThai[o] == CO_DU_LIEU
                && duLieu[o] == khoa) {
                cout << khoa << " da ton tai!\n";
                return;
            }

            // ô trốg or đã xóa thì có thể chèn
            if (trangThai[o] != CO_DU_LIEU) {
                duLieu[o] = khoa;
                trangThai[o] = CO_DU_LIEU;
                return;
            }
        }

        cout << "Bang bam da day, khong the them "
             << khoa << "!\n";
    }

    // tìm kiếm 1 khóa
    bool tim(int khoa) {
        int viTri = bam(khoa);

        for (int buoc = 0; buoc < kichThuoc; buoc++) {
            int o = (viTri + buoc) % kichThuoc;

            // ô trốg -> chx đc chèn
            if (trangThai[o] == TRONG) {
                return false;
            }

            // so sáh nếu ô đag có dl 
            if (trangThai[o] == CO_DU_LIEU
                && duLieu[o] == khoa) {
                return true;
            }
        }

        return false;
    }

    // xóa 1 khóa khỏi bảng băm 
    void xoa(int khoa) {
        int viTri = bam(khoa);

        for (int buoc = 0; buoc < kichThuoc; buoc++) {
            int o = (viTri + buoc) % kichThuoc;

            if (trangThai[o] == TRONG) {
                cout << "Khong tim thay " << khoa << "!\n";
                return;
            }

            if (trangThai[o] == CO_DU_LIEU
                && duLieu[o] == khoa) {
                // đáh dấu đã xóa
                trangThai[o] = DA_XOA;
                cout << "Da xoa " << khoa << "!\n";
                return;
            }
        }

        cout << "Khong tim thay " << khoa << "!\n";
    }

    // in bảg băm
    void hienThi() {
        cout << "\n--- BANG BAM ---\n";

        for (int i = 0; i < kichThuoc; i++) {
            cout << "O[" << i << "] = ";

            if (trangThai[i] == CO_DU_LIEU) {
                cout << duLieu[i];
            }
            else if (trangThai[i] == DA_XOA) {
                cout << "[Da xoa]";
            }
            else {
                cout << "[Trong]";
            }

            cout << '\n';
        }
    }
};


int main() {
    BangBam bang(11);

    // thêm các khóa vào bảg băm
    bang.them(25);   // 25 % 11 = 3
    bang.them(36);   // 36 % 11 = 3, bị va chạm
    bang.them(18);   // 18 % 11 = 7
    bang.them(47);   // 47 % 11 = 3, tiếp tục dò tìm
    bang.them(29);   // 29 % 11 = 7, bị va chạm
    bang.them(52);   // 52 % 11 = 8

    cout << "\nBang bam sau khi them:";
    bang.hienThi();

    // Tim kiem khoa
    cout << "\nTim 47: "
         << (bang.tim(47) ? "Tim thay" : "Khong thay")
         << '\n';

    // Xoa mot khoa
    bang.xoa(36);

    cout << "Tim 47 sau khi xoa 36: "
         << (bang.tim(47) ? "Tim thay" : "Khong thay")
         << '\n';

    // Xoa tiep mot khoa khac
    bang.xoa(25);

    cout << "Tim 36: "
         << (bang.tim(36) ? "Tim thay" : "Khong thay")
         << '\n';

    cout << "\nBang bam hien tai:";
    bang.hienThi();

    return 0;
}
