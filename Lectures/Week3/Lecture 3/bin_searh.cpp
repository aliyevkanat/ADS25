"""#include <iostream>
using namespace std;

int binary_search(vector<int> & a,int x){
   //int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;  // Avoids overflow
        if (a[mid] == x) return mid;
        if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1; // not found
}

int main() {
    //vector<int>a = {3, 5, 8, 13, 18, 19, 21, 27, 32};
    int x = 13;
   //int idx = binary_search(a, x);
    
    if (idx != -1) {
    cout << "Found at index " << idx << "\n";
    } else {
    cout << "Not found\n";
    }
    return 0;
}"""