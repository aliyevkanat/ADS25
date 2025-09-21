#include <iostream>
#include <deque>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--){
        int n;
    cin >> n;
    deque<int> deq;
    for(int i = n;i > 0;i--){
        deq.push_front(i);
        int k = i % deq.size();
        
    while(k > 0){
            k-=1;
            deq.push_front(deq.back());
            deq.pop_back();
        
            
        }
    }
    for(int i = 0;i < deq.size();i++){
        cout << deq[i] << " "; 
    }
    cout << endl;
    }
    
}
