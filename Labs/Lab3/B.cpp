#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool canDivide(ll mid, vector<int>& a, int k) {
    int blocks = 1;
    ll current_sum = 0;

    for(int i = 0; i < a.size(); i++) {
        int x = a[i];
        
        if(x > mid) return false;  
        
        if(current_sum + x > mid) {
            blocks++;
            current_sum = x;
            if(blocks > k) return false;
        } else {
            current_sum += x;
        }
    }
    return true;
}

ll binarySearch(vector<int> &a, int k, ll l, ll r) {
    ll answer = r;

    while(l <= r) {
        ll mid = l + (r - l) / 2;

        if(canDivide(mid, a, k)) {
            answer = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    ll l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        r += a[i];
        if(a[i] > l) l = a[i];
    }
    
    ll answer = binarySearch(a, k, l, r);
    cout << answer << endl;

    return 0;
}