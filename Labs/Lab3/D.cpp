#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
int arr[MAXN];

int find_ge(int n, long long x) {
    int l = 0, r = n - 1, res = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int find_le(int n, long long x) {
    int l = 0, r = n - 1, res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= x) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    for (int i = 0; i < q; i++) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        int s1 = find_ge(n, l1);
        int e1 = find_le(n, r1);
        int cnt1 = (e1 >= s1) ? (e1 - s1 + 1) : 0;
        
        int s2 = find_ge(n, l2);
        int e2 = find_le(n, r2);
        int cnt2 = (e2 >= s2) ? (e2 - s2 + 1) : 0;
        
        long long ls = max(l1, l2);
        long long rs = min(r1, r2);
        int cnt_int = 0;
        
        if (ls <= rs) {
            int si = find_ge(n, ls);
            int ei = find_le(n, rs);
            cnt_int = (ei >= si) ? (ei - si + 1) : 0;
        }
        
        cout << cnt1 + cnt2 - cnt_int << "\n";
    }
    
    return 0;
}