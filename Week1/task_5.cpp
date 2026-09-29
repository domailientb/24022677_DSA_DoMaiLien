#include <iostream>

using namespace std;

int main() {
    int n; //(1) O(1)
    cin >> n; //(2) O(1)
    double a[n]; //(3) O(n)
    double sum = 0; //(4) O(1)
    
    for (int i = 0; i < n; i++) { //(5) O(n)
        cin >> a[i]; //(6) O(1)
        sum += a[i]; //(7) O(1)
    }
    
    double trungbinh = sum / n; //(8) O(1)
    
    for (int i = 0; i < n; i++) { //(9) O(n)
        if (a[i] >= trungbinh) { //(10) O(1)
            cout << a[i] << " "; //(11) O(1)
        }
    }
    cout << endl; //(12) O(1)
    return 0;
}

    // P = P(1)+P(2)+P(3)+P(4)+P(5)*(P(6)+P(7))+P(8)+P(9)*(P(10)+P(11))+P(12)
    //   = O(1)+O(1)+O(n)+O(1)+O(n)*(O(1)+O(1))+O(1)+O(n)*(O(1)+O(1))+O(1)
    //   = O(n)
    // Bộ nhớ (Memory): O(n) do phải tạo mảng lưu n số thực để duyệt lại lần 2.
