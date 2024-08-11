#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
struct Edge{
	long long e;
	int a;
};

int m, n, k;
struct Edge edge[MAXN][MAXN] = {};


int maxa = 0;
int main (){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	
	scanf("%d %d %d", &m, &n, &k);
	
	for (int i = 1; i <= n; i++){
	for (int j = 1; j <= n; j++){
		edge[i][j].e = false;}
	}
	
	int ux, vx, ax;
	for (int i = 1; i <= n; i++){
		scanf("%d %d %d", &ux, &vx, &ax);
		edge[ux][vx].e = true;
		edge[ux][vx].a = ax;
	}
	
	for (int k = 1; k <= n; k++){
	for (int i = 1; i <= n; i++){
	for (int j = 1; j <= n; j++){
		if (i != j && (edge[i][j].e == 0 || edge[i][j].e > edge[i][k].e + edge[k][j].e)){
			edge[i][j].e = edge[i][k].e + edge[k][j].e;
		}
	}}}
	printf("%lld", edge[1][n].e);
	
	return 0;
}