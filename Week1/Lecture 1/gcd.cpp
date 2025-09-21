//gcd(12.18) = 6
//min(a,b) -> 1
//a  % i = 0
//b % i = 0
//y -> return

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; --i) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1;
}

int main(){


    return 0;
}