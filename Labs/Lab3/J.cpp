#include <iostream>
#include <cmath>

using namespace std;
#define LL long long

LL h;
double arr[10005];
int n;

bool steals(double x) {
    LL hours = 0;
    for(int i = 0; i<n; i++) {
        hours += ceil(arr[i]/x);

        if(hours > h) {
            return false;
        }

    }

    return true;

}

int main() {
   
    double x, max_speed = 0, min_speed;
    cin >> n >> h;

    for(int i = 0; i<n; i++) {
        cin >> x;
        max_speed = max(max_speed, x);
        arr[i] = x;
    }

    LL l = 0, r = max_speed, mid;

    while(l <= r) {
        mid = (l+r)/2;

        if(steals(mid)) {
            r = mid - 1;
            min_speed = mid;
        }

        else {
            l = mid + 1;
        }
        
             
    }

   
    cout << min_speed << endl;

     



}