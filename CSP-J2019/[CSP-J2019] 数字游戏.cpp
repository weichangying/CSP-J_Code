/*************************************
* 题目：[CSP-J2019] 数字游戏
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int ans = 0;  // 注意要初始化为 0 
	char c;
	for(int i = 0; i < 8; i++) {
		cin >> c;
		if(c == '1') ans++;  // 注意是字符 1，而不是数字 1 
	}
	cout << ans;

	return 0;
}
