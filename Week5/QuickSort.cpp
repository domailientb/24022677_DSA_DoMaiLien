#include <iostream>
#include <algorithm>
using namespace std;

int Partition(int a[], int left, int right) {
    int pivot = a[right];
    int x = left;

    for (int i = left; i < right; i++) {
        if (a[i] < pivot) {
            swap(a[i], a[x]);
            x++;
        }
    }
    swap(a[right], a[x]);

    return x;
}

void QuickSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = Partition(a, left, right);

    QuickSort(a, left, pivotIndex - 1);
    QuickSort(a, pivotIndex + 1, right);
}

int main() {
    int n;
    cin >> n;
    int a[1000];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}