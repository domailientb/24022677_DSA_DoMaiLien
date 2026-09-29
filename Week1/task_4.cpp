#include <iostream>
#include <cmath>

using namespace std;

// Hàm tìm UCLN bằng thuật toán Euclid
int timUCLN(int x, int y) {
    x = abs(x); //(1) O(1)
    y = abs(y); //(2) O(1)
    while (y != 0) { //(3) Số bước giảm theo cấp số nhân -> O(log(min(|a|, |b|)))
        int r = x % y; //(4) O(1)
        x = y; //(5) O(1)
        y = r; //(6) O(1)
    }
    return x; //(7) O(1)
}

void rutGonPhanSo(int &a, int &b) {
    int ucln = timUCLN(a, b); //(8) Tốn thời gian bằng hàm tìm UCLN -> O(log(min(|a|, |b|)))
    a /= ucln; //(9) O(1)
    b /= ucln; //(10) O(1)
}

int main() {
    int a, b; //(11) O(1)
    cin >> a >> b; //(12) O(1)
    
    rutGonPhanSo(a, b); //(13) Gọi hàm rút gọn -> O(log(min(|a|, |b|)))
    
    cout << a << "/" << b << endl; //(14) O(1)
    return 0;
}

    // P = P(11)+P(12)+P(13)+P(14)
    //   = O(1)+O(1)+O(log(min(|a|, |b|)))+O(1)
    //   = O(log(min(|a|, |b|)))
    // Bộ nhớ (Memory): O(1) không tốn thêm mảng lưu trữ.
