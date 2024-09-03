#include "bits/stdc++.h"
const int DIM = 500000;
int v[DIM + 5];
void Merge(int v[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];
    for (int i = 1; i <= n1; i++) {
        L[i] = v[l + i - 1];
    }
    for (int j = 1; j <= n2; j++) {
        R[j] = v[mid + j];
    }
    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;

    int i = 1, j = 1;
    int k = l;
    while (k <= r) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    delete[] L;
    delete[] R;
}
void MergeSort(int v[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        MergeSort(v, l, mid);
        MergeSort(v, mid + 1, r);
        Merge(v, l, mid, r);
    }
}
void Solve() {
    int n;
    std :: cin >> n;
    for (int i = 1; i <= n; i++) {
        std :: cin >> v[i];
    }
    MergeSort(v, 1, n);
    for (int i = 1; i <= n; i++) {
        std :: cout << v[i] << ' ';
    }
    std :: cout << std :: endl;
}
signed main(){
    std :: ios_base :: sync_with_stdio(false);
    std :: cin.tie(0);
    Solve();
    return 0;
}
