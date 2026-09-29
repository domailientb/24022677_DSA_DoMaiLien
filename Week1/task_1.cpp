#include <iostream>
using namespace std;
int main() {
    int n; //(1) O(1)
    cin >> n; //(2) O(1)
    int a[n]; //(3) O(n)
    long long sum = 0; //(4) O(1)
    
    for (int i = 0; i < n; i++) { //(5) O(n)
        cin >> a[i];  //(6) O(1)
        sum += a[i]; //(7) O(1)
    }
    
    cout << sum << endl; //(8) O(1)
    return 0;
}

    // P = P(1)+P(2)+P(3)+P(4)+P(5)*(P(6)+P(7))+P(8)
    // = O(1)+O(1)+O(n)+O(1)+O(n)*(O(1)+O(1))+O(1)
    // = O(n)
    // Bộ nhớ: O(n) do sử dụng mảng tĩnh kích thước n phần tử để lưu trữ dãy số
