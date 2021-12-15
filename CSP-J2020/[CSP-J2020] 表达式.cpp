// [CSP-J2020] 表达式 
// Wei Changying
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int w[N];  // 操作数的初始值 
char op[N];  // 存储操作符，下标范围：n+1~n+m 
stack<int> st;  // 存储后缀表达式，帮助建树 
int head[N], to[N], nex[N], idx;
bool change[N];

void add(int u, int v) {
	to[++idx] = v;
	nex[idx] = head[u];
	head[u] = idx;
}

int dfs1(int u) {  // 求原答案 
	if(!op[u]) return w[u];  // 叶子结点(操作数)
	if(op[u] == '!') w[u] = !dfs1(to[head[u]]);  // 对孩子取反  
	else {
		int a = to[head[u]], b = to[nex[head[u]]];  // 俩孩子结点 
		if(op[u] == '&') w[u] = dfs1(a) & dfs1(b);
		if(op[u] == '|') w[u] = dfs1(a) | dfs1(b);
	}
	return w[u];
}

void dfs2(int u) {
	change[u] = true;
	if(!op[u]) return;  // 叶子结点(操作数) 
	if(op[u] == '!') dfs2(to[head[u]]);  // ! 运算，改变孩子即可改变答案 
	else {
		int a = to[head[u]], b = to[nex[head[u]]];  // 俩孩子结点 
		if(op[u] == '&') {  // & 运算，其中一个是 1，另一个会影响答案 
			if(w[a]) dfs2(b);
			if(w[b]) dfs2(a);
		}
		if(op[u] == '|') {  // | 运算，其中一个是 0，另一个会影响答案
			if(!w[a]) dfs2(b);
			if(!w[b]) dfs2(a);
		}
	} 
}

int main() {

	string s;
	getline(cin, s);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	// 建后缀表达式树，操作数结点编号 1~n，操作符结点编号 n+1~n+m
	int m = n; 
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == ' ') continue;
		else if(s[i] == 'x') {
			int x = 0, j = i + 1;
			while(j < s.size() && isdigit(s[j])) x = x * 10 + (s[j++] - '0');
			st.push(x);  // 操作数入栈 
			i = j;  // 跳过空格 
		}else if(s[i] == '!') {
			op[++m] = s[i];  // 存储操作符
			add(m, st.top());  // m 是 st.top() 的父结点
			st.pop();
			st.push(m);  // 操作符编号入栈 
		}else {  // & 或 | 
			op[++m] = s[i];
			add(m, st.top());  // m 是 st.top() 的父结点
			st.pop();
			add(m, st.top());  // m 是 st.top() 的父结点
			st.pop();
			st.push(m);  // 操作符编号入栈
		}
	}
	
	int ans = dfs1(m);  // 求原答案
	dfs2(m);  // 每个变量改变会不会引起答案改变 
	
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		if(change[x]) cout << (!ans) << endl;  // x 取反能让答案改变
		else cout << ans << endl;
	}
	
	return 0;
}
