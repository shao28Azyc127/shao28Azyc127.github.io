#include <bits/stdc++.h>
using namespace std;
const int maxn = 8010;
string s;
int t[maxn][maxn], cnt, n;
struct  node{
	int l, r;
}a[maxn];
bool cmp(node w, node v){
	return w.l < v.r;
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	cin >> s;
	for(int i = 0 ; i < n ; i++){
		t[i][i] = true;
		t[i][i - 1] = (s[i] == s[i - 1] ? 1 : 0);
	}
	for(int i = 2 ; i < n - 1 ; i ++){
		for(int j = 1 ; j < n - i ; j++){
			int k = j + i;
			if(s[j] == s[k]){
				t[j][k] = t[j + 1][k - 1];
				cnt++;
				a[cnt].l = j;
				a[cnt].r = k;
			}
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	int tmp = 1;
	long long ans = 0;
	for(int i = 1  ; i <= cnt ; i++){
		int rr = i + 1;
		while(a[rr].l < a[rr].r)rr++;
		if(a[rr].l == a[i].r){
			tmp++;
		}else{
			ans += max(1, tmp * (tmp - 1) / 2);
			tmp = 1;
		}
	}
	cout << ans;
	return 0;
}
