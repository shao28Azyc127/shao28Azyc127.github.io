#include <bits/stdc++.h>
using namespace std;
int n, a[15][15], num[15], ans;
int id(int x){
	return x<0 ? x+10 : x;
}
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int t, f, cnt;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 5; j++)
			scanf("%d", &a[i][j]);
	for(int sta = 0; sta <= 99999; sta++){
		t = sta;
		for(int i = 5; i; i--) num[i] = t%10, t /= 10;
		for(int i = 1; i <= n; i++){
			f = cnt = 0;
			for(int j = 1; j <= 5; j++)
				if(num[j] ^ a[i][j]){
					if(!f) f = j, cnt++;
					else
						if(f < j-1 || id(a[i][f]-num[f])^id(a[i][j]-num[j]) || cnt==2){ f = 6; break; }
						else f = j, cnt++;
				}
			if(!f || f==6) break;
		}
		if(f && f < 6) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
//c0y4@3z0
