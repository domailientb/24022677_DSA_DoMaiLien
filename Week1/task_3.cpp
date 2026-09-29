#include <iostream>

using namespace std;

int main() {
    int n; //(1) O(1)
    cin >> n; //(2) O(1)
    
    long long giaithua = 1; //(3) O(1)
    for (int i = 1; i <= n; i++) { //(4) Chạy n lần -> O(n)
        giaithua *= i; //(5) O(1)
    }
    
    cout << giaithua << endl; //(6) O(1)
    return 0;
}

    // P = P(1)+P(2)+P(3)+P(4)*P(5)+P(6)
    //   = O(1)+O(1)+O(1)+O(n)*O(1)+O(1)
    //   = O(n)
    // Bộ nhớ (Memory): O(1) chỉ dùng vài biến đơn lẻ, không dùng mảng.
