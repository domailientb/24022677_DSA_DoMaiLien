#include <iostream>
using namespace std;

void Merge(int a[], int left, int mid, int right) {
    int t[1000];
    int x = left;
    int y = mid + 1;

    for (int i = left; i <= right; i++) {
        if (x > mid) {
            t[i] = a[y++];
        }
        else if (y > right) {
            t[i] = a[x++];
        }
        else if (a[x] <= a[y]) {
            t[i] = a[x++];
        }
        else {
            t[i] = a[y++];
        }
    }
    for (int i = left; i <= right; i++) {
        a[i] = t[i];
    }
}

void MergeSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;

    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}