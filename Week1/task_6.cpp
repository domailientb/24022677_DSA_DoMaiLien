#include <iostream>
using namespace std;

// a) Hàm xóa phần tử ở vị trí k
void xoaPhanTu(int a[], int &n, int k) {
    for (int i = k; i < n - 1; i++) { //(1) O(n)
        a[i] = a[i + 1];              //(2) O(1)
    }
    n--; //(3) O(1)
}

// b) Hàm chèn phần tử y vào vị trí m
void chenPhanTu(int a[], int &n, int y, int m) {
    for (int i = n; i > m; i--) { //(4) O(n)
        a[i] = a[i - 1];          //(5) O(1)
    }
    a[m] = y; //(6) O(1)
    n++;      //(7) O(1)
}

int main() {
    int n; //(8) O(1)
    cin >> n; //(9) O(1)
    int a[n + 1]; //(10) O(n)

    for (int i = 0; i < n; i++) { //(11) O(n)
        cin >> a[i]; //(12) O(1)
    }

    int k; //(13) O(1)
    cin >> k; //(14) O(1)
    xoaPhanTu(a, n, k); //(15) O(n)

    int y, m; //(16) O(1)
    cin >> y >> m; //(17) O(1)
    chenPhanTu(a, n, y, m); //(18) O(n)

    for (int i = 0; i < n; i++) { //(19) O(n)
        cout << a[i] << " "; //(20) O(1)
    }
    cout << endl; //(21) O(1)
    return 0;
}

    // P = P(8)+P(9)+P(10)+P(11)*P(12)+P(13)+P(14)+P(15)+P(16)+P(17)+P(18)+P(19)*P(20)+P(21)
    //   = O(1)+O(1)+O(n)+O(n)*O(1)+O(1)+O(1)+O(n)+O(1)+O(1)+O(n)+O(n)*O(1)+O(1)
    //   = O(n)
    // // Xóa phần tử:
    //   - Trường hợp tốt nhất: O(1) (xóa phần tử cuối)
    //   - Trường hợp trung bình: O(n)
    //   - Trường hợp xấu nhất: O(n) (xóa phần tử đầu)
    //
    // Chèn phần tử:
    //   - Trường hợp tốt nhất: O(1) (chèn vào cuối)
    //   - Trường hợp trung bình: O(n)
    //   - Trường hợp xấu nhất: O(n) (chèn vào đầu)
    //
    // Bộ nhớ: O(n) dùng mảng kích thước n+1 phần tử.