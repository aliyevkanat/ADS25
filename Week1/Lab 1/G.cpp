#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e6 + 7;
bool ok[MAXN];
int n;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ok[0] = ok[1] = true;
	for(int i = 2; i * i < MAXN; i++){
		if(!ok[i]){
			for(int j = i * i; j < MAXN; j += i){
				ok[j] = true;
			}
		}
	}
	vector<int> ans;
	for(int i = 0; i < MAXN; i++){
		if(!ok[i]){
			ans.push_back(i);
		}
	}
	cin >> n;
	cout << ans[ans[n - 1] - 1] << '\n';
}