// [CSP-J2020] 直播获奖
// Wei Changying
#include <bits/stdc++.h>
using namespace std;

const int N = 610;
int cnt[N];  // 每个分数出现的次数 

int main() {

	int n, w;  // 人数，获奖百分百 w% 
	cin >> n >> w;
	for(int i = 1; i <= n; i++) {
		int score;  // 第 i 个人的分数 
		cin >> score;
		cnt[score]++;  // 该分数出现次数加 1 
		int p = max(1, i * w / 100);  // 获奖人数 
		int num = 0;  // 目前的获奖人数 
		for(int j = 600; j >= 0; j--) {  // 从高到低枚举每个分数 
			if(cnt[j]) {
				num += cnt[j];  // 目前的获奖人数 
				if(num >= p) {  // 获奖人数足够 
					cout << j << " ";  // 分数线 
					break;
				}
			}
		}
	}
	
	return 0;
}
