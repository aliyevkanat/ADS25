#include <iostream>
#include <vector>
using namespace std;

bool isprime(int n){
    if(n <= 1){
        return false;
    }
    for (int i = 2;i * i <= n;i++){
        if(n % i == 0){
            return false;
        }
    }
}

int main(){

    int n;
    vector<int> primes;
    cin >> n;
    for(int i = 2;i * i <= n;i++){
        primes.push_back(i);
    }


    return 0;
}