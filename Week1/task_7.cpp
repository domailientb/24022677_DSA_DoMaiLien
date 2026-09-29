#include <iostream>
using namespace std;

// a) Hàm tính tổng các phần tử trong mảng 2 chiều
long long tinhTong2Chieu(int a[][100], int n, int m) {
    long long s = 0; //(1) O(1)
    for (int i = 0; i < n; i++) { //(2) O(n)
        for (int j = 0; j < m; j++) { //(3) O(m)
            s += a[i][j]; //(4) O(1)
        }
    }
    return s; //(5) O(1)
}

// b) Hàm xóa dòng thứ i trong mảng 2 chiều (quy ước chỉ số từ 0)
void xoaDong(int a[][100], int &n, int m, int dong_can_xoa) {
    // Dịch các dòng phía dưới lên trên 1 vị trí
    for (int i = dong_can_xoa; i < n - 1; i++) { //(6) O(n)
        for (int j = 0; j < m; j++) { //(7) O(m)
            a[i][j] = a[i + 1][j]; //(8) O(1)
        }
    }
    n--; //(9) O(1)
}

int main() {
    int n, m; //(10) O(1)
    cin >> n >> m; //(11) O(1)
    int a[100][100]; //(12) khai báo mảng kích thước N*M -> O(n*m)
    for (int i = 0; i < n; i++) { //(13) O(n)
        for (int j = 0; j < m; j++) { //(14) O(m)
            cin >> a[i][j]; //(15) O(1)
        }
    }

    // Test a: Tính tổng
    long long tong = tinhTong2Chieu(a, n, m); //(16) gọi hàm tính tổng -> O(n*m)
    cout << tong << endl; //(17) O(1)

    // Test b: Xóa dòng thứ i
    int dong_xoa; //(18) O(1)
    cin >> dong_xoa; //(19) O(1)
    xoaDong(a, n, m, dong_xoa); //(20) Gọi hàm xóa (Xét trường hợp xấu nhất dong_xoa = 0) -> O(n*m)

    // In lại mảng sau khi xóa dòng
    for (int i = 0; i < n; i++) { //(21) O(n)
        for (int j = 0; j < m; j++) { //(22) O(m)
            cout << a[i][j] << " "; //(23) O(1)
        }
        cout << endl; //(24) O(1)
    }
    return 0;
}

    // P_hàm_tổng = P(1) + P(2) * P(3) * P(4) + P(5)
    //            = O(1) + O(n) * O(m) * O(1) + O(1)
    //            = O(n*m)
    //
    // Hàm tính tổng:
    //   - Trường hợp tốt nhất: O(n*m)
    //   - Trường hợp trung bình: O(n*m)
    //   - Trường hợp xấu nhất: O(n*m)
    //
    // P_hàm_xóa = P(6) * P(7) * P(8) + P(9)
    //           = O(n) * O(m) * O(1) + O(1)
    //           = O(n*m)
    //
    // Hàm xóa dòng:
    //   - Trường hợp tốt nhất: O(m) (xóa dòng cuối)
    //   - Trường hợp trung bình: O(n*m)
    //   - Trường hợp xấu nhất: O(n*m) (xóa dòng đầu)
    //
    // P_chương_trình = P(10)+P(11)+P(12)+[P(13)*P(14)*P(15)]+P(16)+P(17)+P(18)+P(19)+P(20)+[P(21)*P(22)*(P(23)+P(24))]
    //                = O(1)+O(1)+O(n*m)+[O(n)*O(m)*O(1)]+O(n*m)+O(1)+O(1)+O(1)+O(1)+O(n*m)+[O(n)*O(m)*(O(1)+O(1))]
    //                = O(n*m)
    //
    // Bộ nhớ: O(N*M) dựa trên số lượng phần tử được sử dụng để lưu trữ ma trận đầu vào.