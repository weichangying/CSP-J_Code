/*************************************
* 题目：[CSP-J2019] 公交换乘
* 作者：Wei Changying
* 邮箱：weichangying_wcy@163.com
*************************************/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct ticket {  // 优惠票 
	int tim;  // 开始乘车时间 
	int price;  // 价格
	bool used = false;  // 是否被使用过，初始化为 false (没使用) 
} t[N];

int main() {
	
	int n;
	cin >> n;
	int cnt = 0;  // 优惠票的数量 
	int cost = 0;  // 总花费 
	int idx = 0;  // 最早的，没有过期的优惠票的下标 
	for(int i = 0; i < n; i++) {
		int way, price, tim;  // 乘车工具(0 地铁，1 公交)，价格，开始乘车时间 
		cin >> way;
		if(way == 0) {  // 地铁，乘车后获得优惠票 
			cin >> t[cnt].price >> t[cnt].tim;
			cost += t[cnt++].price;  // 乘地铁花钱 
		}else if(way == 1) {  // 公交，优先用优惠票，不能用则自己花钱 
			cin >> price >> tim;
			bool ok = false;  // 用优惠票的标志 
			while(tim - t[idx].tim > 45) idx++;  // 丢掉过期的优惠票，本题优化时间的关键
			for(int j = idx; j < cnt; j++) {
				if(!t[j].used && price <= t[j].price) {  // 没有用过 && 价格没有超过优惠票 
					t[j].used = true;  // 标记用过 
					ok = true;  // 标记用了优惠票 
					break;  // 用完优惠票即退出 
				}
			} 
			if(!ok) cost += price;  // 不能用优惠票，自己花钱坐公交 
		}
	}
	cout << cost; 

	return 0;
}
