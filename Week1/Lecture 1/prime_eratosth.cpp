#include <iostream>
#include <vector>

using namespace std;

bool isprime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= n; ++i) { // Check divisors from 2 to sqrt(n)
        if (n % i == 0) {
            return false; // Found a divisor, not prime
        }
    }
    return true; // No divisors found, it's prime
}

int main(){
    int n;
    cin >> n;
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isprime(i)) {
            primes.push_back(i);
        }
    }
    return 0;
}