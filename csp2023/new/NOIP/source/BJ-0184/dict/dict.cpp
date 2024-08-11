#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, m, w, ttm[N], ymh[N];
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	bool flag;
	scanf("%d%d", &n, &m);
	memset(ymh, 0x3f, sizeof(ymh));
	for(int i = 1, j; i <= n; i++){
		w = getchar();
		while(w<'a'||w>'z') w=getchar();
		ttm[i] = max(ttm[i], w), ymh[i] = min(ymh[i], w);
		for(j = 2; j <= m; j++)
			w = getchar(), ttm[i] = max(ttm[i], w), ymh[i] = min(ymh[i], w);
	}
	for(int i = 1, j; i <= n; i++){
		flag = 1;
		for(j = 1; j <= n; j++) if(j^i)
			if(ymh[i] >= ttm[j]){ flag = 0; break; }
		if(flag) putchar('1');
		else putchar('0');
	}
	putchar('\n');
	return 0;
}
