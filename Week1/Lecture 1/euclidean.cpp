#include <iostream>
using namespace std;


//suppose a > b
int gcd2(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd2(b, a % b);
}

//a = 28 , b = 32
//gcd(32,28)
//gcd(28,4)
//gcd(4,0) = 4 <-- return 4

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd2(a, b) << endl;
    return 0;
}