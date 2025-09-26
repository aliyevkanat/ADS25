#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < q; i++) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        auto low1 = lower_bound(arr.begin(), arr.end(), l1);
        auto up1 = upper_bound(arr.begin(), arr.end(), r1);
        int cnt1 = up1 - low1;
        
        auto low2 = lower_bound(arr.begin(), arr.end(), l2);
        auto up2 = upper_bound(arr.begin(), arr.end(), r2);
        int cnt2 = up2 - low2;
        
        long long l_max = max(l1, l2);
        long long r_min = min(r1, r2);
        int cnt_int = 0;
        
        if (l_max <= r_min) {
            auto low_int = lower_bound(arr.begin(), arr.end(), l_max);
            auto up_int = upper_bound(arr.begin(), arr.end(), r_min);
            cnt_int = up_int - low_int;
        }
        
        cout << cnt1 + cnt2 - cnt_int << endl;
    }
    
    return 0;
}