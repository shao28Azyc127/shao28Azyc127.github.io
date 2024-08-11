#include <bits/stdc++.h>
using namespace std;

int n, d, v[100010], a[100010], k, ans = 0x3f3f3f3f;

void dfs(int r, int c, int f){
	if (f < 0) return;
	if (r == n){
		ans = min(ans, c); 
		return;
	}
   	dfs(r+1, c, f-v[r]/d);
   	for (int i = v[r]/d; i <= k; i++){
   		dfs(r+1, c+i*a[i], f-v[r]/d+i);	
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for (int i = 1; i <= n-1; i++){
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	k = n*d;
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}