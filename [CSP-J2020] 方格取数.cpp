#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e3 + 10;
LL a[N][N];
LL d[N];  // 每一列：上 --> 下
LL u[N];  // 每一列：下 --> 上
LL dp[N][N];  // dp[i][j] 到 (i, j) 整数之和的最大值

int main(){

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	memset(dp, -0x3f, sizeof(dp));
	dp[1][0] = 0;  // 保证从左上角开始 
	for(int j = 1; j <= m; j++) {  // 从左到右，一列一列算
		// 对于点 (i, j)，三种情况：max(从左走来，从上走来，从下走来)
		for(int i = 1; i <= n; i++) {  // 左 --> 右
			d[i] = u[i] = dp[i][j-1] + a[i][j];
		}
		for(int i = 2; i <= n; i++) {  // 上 --> 下
			d[i] = max(d[i], d[i-1] + a[i][j]);
		}
		for(int i = n-1; i >= 1; i--) {  // 下 --> 上
			u[i] = max(u[i], u[i+1] + a[i][j]);
		}
		for(int i = 1; i <= n; i++) {  // max(从左走来，从上走来，从下走来)
			dp[i][j] = max(u[i], d[i]);
		}
	}
	cout << dp[n][m];

	return 0;
}
