#include <iostream>
using namespace std;
void sapXepTangDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {       //(1)  O(n)
        for (int j = 0; j < n - i - 1; j++) { //(2) O(n)
            if (a[j] > a[j + 1]) {          //(3)  O(1)
                int temp = a[j];            //(4)  O(1)
                a[j] = a[j + 1];            //(5)  O(1)
                a[j + 1] = temp;            //(6)  O(1)
            }
        }
    }
}

int main() {
    int n;           //(7)  O(1)
    cin >> n;        //(8)  O(1)
    int a[n];        //(9)  O(n)
    for (int i = 0; i < n; i++) { //(10) O(n)
        cin >> a[i];              //(11) O(1)
    }
    
    sapXepTangDan(a, n); //(12) gọi hàm sắp xếp lồng nhau O(n^2)
    
    for (int i = 0; i < n; i++) { //(13) O(n)
        cout << a[i] << " ";      //(14) O(1)
    }
    cout << endl; //(15) O(1)
    return 0;
}

    // P = P(7)+P(8)+P(9)+P(10)*P(11)+P(12)+P(13)*P(14)+P(15)
    //   = O(1)+O(1)+O(n)+O(n)*O(1)+O(n^2)+O(n)*O(1)+O(1)
    //   = O(n^2)
    // Bộ nhớ: O(n) do sử dụng mảng tĩnh kích thước n phần tử
