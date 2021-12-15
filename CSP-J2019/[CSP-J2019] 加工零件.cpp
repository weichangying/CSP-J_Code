/*************************************
* 题目：[CSP-J2019] 加工零件
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com

* 思路：
	需要 1 号为 a 号生产第 L 个阶段提供原材料 <==> 是否存在 1 到 a 的长度为 L 的路径 
	如果存在 1 到 a 的长度为 L 的路径，则 L + 2, L + 4, L + 8...也是 1 到 a 的路径(L + 2：回到上一个点又回来)
	存在 L 的路径 ==> 是否存在 <= L，并且和 L 奇偶性相同的路径 
	所以，分别求 1->a 长度为奇数的最短路、1->a 长度为偶数的最短路 
	可以进行拆点来进行求解：a奇、a偶 
	在走的过程中，偶 --> 奇，奇 --> 偶 
*************************************/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m, q;
int odd[N], even[N];  // 奇数最短路，偶数最短路 
int head[N], to[M], nex[M], idx;

void add(int u, int v) {  // 增加一条 u->v 的边 
	to[++idx] = v;
	nex[idx] = head[u];
	head[u] = idx;
}

void BFS(int s) {
	memset(odd , 0x7f, sizeof  odd);  // 初始化为无穷大 
	memset(even, 0x7f, sizeof even);  // 初始化为无穷大
	queue<int> q;
	q.push(s);  // 起点入队 
	even[1] = 0;  // 到 1 的偶数最短路是 0（注意不要忘记初始化） 
	while(!q.empty()) {
		int u = q.front();  // 队首 
		q.pop();  // 队首出队 
		for(int i = head[u]; i; i = nex[i]) {  // u 的相邻点 
			int v = to[i];
			if(odd[u] + 1 < even[v]) {  // 到 u 是奇数，加 1 是偶数  
				even[v] = odd[u] + 1;
				q.push(v);
			}
			if(even[u] + 1 < odd[v]) {  // 到 u 是偶数，加 1 是奇数
				odd[v] = even[u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	
	cin >> n >> m >> q;
	while(m--) {
		int u, v;  // u -- v
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	BFS(1);
	while(q--) {
		int a, L;  // 编号为 a 的工人，第 L 阶段的零件
		cin >> a >> L;
		// L 是偶数，1 到 a 有偶数路径且不超过 L
		// L 是奇数，1 到 a 有奇数路径且不超过 L
		if(L % 2 == 1 && odd[a] <= L || L % 2 == 0 && even[a] <= L) {
			cout << "Yes\n";
		}else {
			cout << "No\n";
		}
	}

	return 0;
}
