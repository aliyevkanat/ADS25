#include <iostream>
#include <string>
#include <stack>
using namespace std;
string check(string s){
	string st;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '#'){
			if(!st.empty()){
				st.pop_back();
			}
		}
		else{
			st.push_back(s[i]);
		}
	}
	return st;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string a, b;
	cin >> a >> b;
	if(check(a) == check(b)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}