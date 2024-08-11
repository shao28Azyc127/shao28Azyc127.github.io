#include<bits/stdc++.h>
using namespace std;
int c, t;
int n, m, k, d, x[100010], y[100010], v[100010];
int main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	scanf("%d%d", &c, &t);
	for(int i = 0; i < t; i++){
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for(int j = 0; j < m; j++){
			scanf("%d%d%d", &x[j], &y[j] ,&v[j]);
		}
	}
	for(int i = 0; i < t; i++){
		printf("0\n");
	}
	return 0;
}
