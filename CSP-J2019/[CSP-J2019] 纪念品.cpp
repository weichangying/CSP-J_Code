/*************************************************************************************** 
* 题目：[CSP-J2019] 纪念品
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com

* 思路：
	1）对于任意交易间隔天数大于 1 的都可以转化成交易间隔天数为 1，也即：今天买，明天卖
	例如：第 1 天买，第 4 天卖，就可以理解成：1 买，2 卖，2 买，3 卖，3 买，4 卖 
	2）对于每一天来说，收益越大越好，因为在后面的交易中，钱越多，就能买更多的纪念品，创
	造收益的可能性
	3）所以，这道题是 T - 1 天的完全背包问题。对于每一天而言，背包容量是手里有的钱 m，体
	积是每个纪念品当天的价格 w(i, j)，而价值是后一天和当天的价格差：w(i+1, j) - w(i, j) 
*****************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 1e4 + 10;
int w[N][N];  //  w[i][j]: 第 i 天第 j 种纪念品的价格
int dp[M];  // dp[k]: 背包容量限制为 k 的最大价值 

int main() {
	
	int T, n, m;  // 天数，纪念品数量，一开始的金币数
	cin >> T >> n >> m;
	for(int i = 1; i <= T; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> w[i][j];  // 第 i 天第 j 种纪念品的价格 
		}
	} 
	
	for(int i = 1; i < T; i++) {  //  T - 1 天的完全背包问题
		memset(dp, 0, sizeof dp);
		// 容量：m，体积：w(i, j)，价值：w(i+1, j) - w(i, j) 
		for(int j = 1; j <= n; j++) {
			for(int k = w[i][j]; k <= m; k++) {
				dp[k] = max(dp[k], dp[k-w[i][j]] + (w[i+1][j] - w[i][j]));
			}
		}
		m += dp[m];  // 更新手里有的金币数 
	}
	cout << m;

	return 0;
}
