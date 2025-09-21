#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;

    for(int i = 0;i < s.size();i++){
    char c = s[i];
        if(st.empty() || st.top() != c){
            st.push(c);
        } else {
            st.pop();
        }
    }
    
    if(st.empty()){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}