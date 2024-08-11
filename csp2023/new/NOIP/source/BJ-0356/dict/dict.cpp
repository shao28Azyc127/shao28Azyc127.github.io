#include <bits/stdc++.h>
using namespace std;
int n, m, mi[3005][3005], ma[3005][3005];
string s[3005], ti[3005], ta[3005], pre[3005], suf[3005];
signed main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n == 1){
		cout << 1;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		ti[i] = s[i];
		ta[i] = s[i];
	}
	
	for(int i = 1;i <= n;i++){
		mi[i][m] = m;
		for(int j = m - 1;j >= 1;j--){
			if(s[i][j - 1] < s[i][mi[i][j + 1] - 1]){
				mi[i][j] = j;
			}
			else{
				mi[i][j] = mi[i][j + 1];
			}
		}
		for(int j = 1;j < m;j++){
			if(s[i][j - 1] > s[i][mi[i][j + 1] - 1]){
				swap(ti[i][j - 1], ti[i][mi[i][j + 1] - 1]);
				break;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		ma[i][m] = m;
		for(int j = m - 1;j >= 1;j--){
			if(s[i][j - 1] > s[i][ma[i][j + 1] - 1]){
				ma[i][j] = j;
			}
			else{
				ma[i][j] = ma[i][j + 1];
			}
		}
		for(int j = 1;j < m;j++){
			if(s[i][j - 1] < s[i][ma[i][j + 1] - 1]){
				swap(ta[i][j - 1], ta[i][ma[i][j + 1] - 1]);
				break;
			}
		}
	}
	
	pre[1] = ta[1];
	for(int i = 2;i <= n;i++){
		pre[i] = min(pre[i - 1], ta[i]);
	}
	suf[n] = ta[n];
	for(int i = n - 1;i >= 1;i--){
		suf[i] = min(suf[i + 1], ta[i]);
	}
	if(ti[1] < suf[2]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	for(int i = 2;i <= n - 1;i++){
		if(ti[i] < min(pre[i - 1], suf[i + 1])){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	if(ti[n] < pre[n - 1]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
