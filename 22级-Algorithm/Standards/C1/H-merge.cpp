#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N], b[N];

long long merge(int l, int mid, int r) {
    for (int i = l; i <= r; i++) {
        b[i] = a[i];
    }
    int i = l, j = mid + 1, k = l;
    long long cnt = 0;
    while (i <= mid && j <= r) {
        if (b[i] <= b[j]) {
            a[k++] = b[i++];
        } else {
            // b[j] < b[i] => b[j] < b[i], b[i + 1], ... b[mid]
            // so the number is (mid - i + 1)
            a[k++] = b[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid)
        a[k++] = b[i++];
    while (j <= r)
        a[k++] = b[j++];
    return cnt;
}

long long mergeSort(int l, int r) {
    if (l >= r)
        return 0;

    long long cnt = 0;
    int mid = (l + r) / 2;
    cnt += mergeSort(l, mid);
    cnt += mergeSort(mid + 1, r);
    cnt += merge(l, mid, r);
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long ans = mergeSort(0, n - 1);
        cout << ans << '\n';
    }
    return 0;
}