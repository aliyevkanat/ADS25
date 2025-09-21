#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	queue<int> qk, qs;
	for(int i = 0; i < n; i++){
		if(s[i] == 'S'){
			qs.push(i);
		}
		else{
			qk.push(i);
		}
	}
	while(!qk.empty() && !qs.empty()){
		int i = qk.front(), j = qs.front();
		qk.pop(); qs.pop();
		if(i < j){
			qk.push(i + n);
		}
		else{
			qs.push(j + n);
		}
	}
	if(qk.empty()){
		cout << "SAKAYANAGI\n";
	}
	else{
		cout << "KATSURAGI\n";
	}
}