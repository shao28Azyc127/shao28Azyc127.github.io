#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	char ch[2000005];
	for(int i = 1;i <= n;i ++) cin >> ch[i];
	for(int len = 2;len <= n;;len ++){
		for(int l = 1;l + len - 1 <= n;l ++){
			int r = l + len - 1;
			if(len % 2 == 0) ans ++;
		}
	}
	cout << ans;
}