#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
#define ll long long
const int N = 1e5+2;
int main(){

ll n,k;
cin >> n >> k;
ll a[N];
ll pref[N];

for(int i = 0;i < n;i++){
    cin >> a[i];
    pref[i+1] = pref[i] + a[i];
}
    int l = 1;
    int r = n;
    int answer = n;

while(l <= r){
    ll mid = l + (r - l) / 2;
    bool found = false;

    for(int i = 1;i <= n - mid + 1;i++){
        ll sum = pref[i + mid - 1] - pref[i - 1];
        if(sum >= k){
            found = true;
            break;
        }
    }
    if(found){
    answer = mid;
    r = mid - 1;
}else l = mid + 1;

}
cout << answer;
    return 0;
}