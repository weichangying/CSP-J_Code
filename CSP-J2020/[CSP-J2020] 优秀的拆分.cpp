// [CSP-J2020] 优秀的拆分
// Wei Changying
#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void solve(int n) {  // 分解成二进制 
	int e = 0;
	while(n) {
		if(n & 1) ans.push_back(1 << e);  // 2^e  
		n >>= 1;
		e++;
	}
}

int main() {
	
	int n;
	cin >> n;
	if(n & 1) cout << "-1";  // 奇数，没有优秀的拆分
	else {
		solve(n);  // 分解成二进制 
		for(int i = ans.size() - 1; i >= 0; i--) {  // 降序输出 
			cout << ans[i] << " ";
		}
	} 

	return 0;
}
