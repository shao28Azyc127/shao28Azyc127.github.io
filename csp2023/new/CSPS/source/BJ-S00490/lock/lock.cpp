#include<bits/stdc++.h>
using namespace std;
set<int> s[11];
set<int> s1[11];
int l[10] = {0, 1, 1, 1, 1};
int l1[10] = {0, 1, 1, 1, 1, 1};
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n, ans = 0, a, b, c, d, e;
	cin >> n;
	for (int i = 1; i <= 5; i++){
	}
	for (int h = 1; h <= n; h++){
		cin >> a >> b >> c >> d >> e;
		int lis[10] = {0, a, b, c, d, e};
		for (int i = 1; i <= 5; i++){
			if (h == 1){
				for (int j = 0; j <= 9; j++){
					s[i].insert(j);
				}
			}
			else {
				if (!s[i].count(lis[i])) l1[i] = 0;
				else s[i].erase(lis[i]);
			}
			s[i].erase(lis[i]);
		}
		for (int i = 1; i <= 4; i++){
			if (h == 1){
				for (int j = 0; j <= 9; j++){
					int k = lis[i+1] - lis[i] + j;
					if (k < 0) k += 10;
					if (k > 9) k %= 10;
					if (j == lis[i] && k == lis[i+1]) continue;
					int m = j * 10 + k;
					s1[i].insert(m);
				}
			}
			else{
				if (!s1[i].count(lis[i] * 10 + lis[i+1])) l[i] = 0;
				else s1[i].erase(lis[i] * 10 + lis[i+1]);
			}
		}
	}
	for (int i = 1; i <= 5; i++){
		ans += s[i].size() * l1[i];
	}
	for (int i = 1; i <= 4; i++){
		ans += s1[i].size() * l[i];
	}
	cout << ans;
	return 0;
}