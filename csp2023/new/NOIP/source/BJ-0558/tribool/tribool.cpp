#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 100005
int n, m;
int c, t;
int a[MAXN][2];
namespace Solve1{
	void init(){
		for(int i = 1; i <= n; i++){
			a[i][0] = i;
			a[i][1] = 0;
		}
	}
	int fa[MAXN * 2];
	int val[MAXN * 2];
	void init2(){
		for(int i = 0; i <= n * 2; i++){
			fa[i] = i;
			val[i] = 1;
		}
	}
	int find(int x){
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	void combine(int x, int y){
		int fx = find(x), fy = find(y);
		if(fx == fy) return;
		fa[fx] = fy;
		return;
	}
	void work(){
		init();
		while(m--){
			char v;
			scanf(" %c", &v);
			if(v == '+'){
				int i, j;
				scanf("%d%d", &i, &j);
				a[i][0] = a[j][0];
				a[i][1] = a[j][1];
			}
			if(v == '-'){
				int i, j;
				scanf("%d%d", &i, &j);
				a[i][0] = -a[j][0];
				a[i][1] = a[j][1];
			}
			if(v == 'T'){
				int i;
				scanf("%d", &i);
				a[i][0] = 1;
				a[i][1] = 1;
			}
			if(v == 'F'){
				int i;
				scanf("%d", &i);
				a[i][0] = -1;
				a[i][1] = 1;
			}
			if(v == 'U'){
				int i;
				scanf("%d", &i);
				a[i][0] = 0;
				a[i][1] = 1;
			}
		}
		init2();
		for(int i = 1; i <= n; i++){
			if(a[i][1]){
				val[i + n] = a[i][0];
				val[-i + n] = -a[i][0];
			}
			else{
				combine(i + n, a[i][0] + n);
				combine(-i + n, -a[i][0] + n);
			}
		}
		for(int i = 1; i <= n; i++){
			int fx = find(i + n), fy = find(-i + n);
			if(!a[i][1]){
				if(fx == fy)
					val[fx] = 0;
			}
			else{
				val[fx] = a[i][0];
				val[fy] = -a[i][0];
			}
		}
		int ans = 0;
		for(int i = n + 1; i <= 2 * n; i++){
			int f = find(i);
			if(val[f] == 0){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}
int main () {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%d", &n, &m);
		Solve1::work();
	}
	return 0;
}