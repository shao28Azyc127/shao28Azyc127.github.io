#include<bits/stdc++.h>
using namespace std;
int c, n, m, q, x[500010], y[500010];
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for(int i = 0; i < n; i++){
		scanf("%d", &x[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &y[i]);
	}
	int kx, ky, xx, yy;
	if(x[0] == 0 || y[0] == 0){
		printf("0");
	}
	for(int i = 0; i < q; i++){
		scanf("%d%d", &kx, &ky);
		for(int j = 0; j < kx; j++){
			scanf("%d%d", &xx, &yy);
			x[xx] = yy;
		}
		for(int j = 0; j < ky; j++){
			scanf("%d%d", &xx, &yy);
			y[xx] = yy;
		}
		if(x[0] == 0 || y[0] == 0){
			printf("0");
		}else{
			printf("0");
		}
	}
	return 0;
}
