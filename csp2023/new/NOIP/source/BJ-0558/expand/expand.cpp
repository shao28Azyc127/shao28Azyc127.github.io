#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 500005
int c, n, m, q;
int a[MAXN], b[MAXN];
int d[MAXN][2];
void mycopy(){
	for(int i = 1; i <= n; i++)
		d[i][0] = a[i];
	for(int i = 1; i <= m; i++)
		d[i][1] = b[i];
}
namespace Solve1{
	void work(){
		int x, y;
		scanf("%d%d", &x, &y);
		if(x == y) printf("0");
		else printf("1");
		while(q--){
			int kx, ky;
			int xx = x, yy = y;
			scanf("%d%d", &kx, &ky);
			while(kx--){
				int p, v;
				scanf("%d%d", &p, &v);
				xx = v;
			}
			while(ky--){
				int p, v;
				scanf("%d%d", &p, &v);
				yy = v;
			}
			if(xx == yy) printf("0");
			else printf("1");
		}
		return;
	}
}
namespace Solve2{
	void work(){
		if((a[1] - b[1]) * (a[n] - b[m]) <= 0)
			printf("0");
		else
			printf("1");
		while(q--){
			mycopy();
			int kx, ky;
			scanf("%d%d", &kx, &ky);
			while(kx--){
				int p, v;
				scanf("%d%d", &p, &v);
				d[p][0] = v;
			}
			while(ky--){
				int p, v;
				scanf("%d%d", &p, &v);
				d[p][1] = v;
			}
			if((d[1][0] - d[1][1]) * (d[n][0] - d[m][1]) <= 0)
				printf("0");
			else
				printf("1");
		}
		return;
	}
}
/*namespace Solve2{
	bool check(int n, int m, int x, int y){
		if((d[1][0] - d[1][1]) * (d[n][0] - d[m][1]) <= 0) return false;
		if(d[1][0] < d[1][1]){
			swap(x, y);
			swap(n, m);
		}
		int mxx = 0, mxy = 0, mnx = 1000000005, mny = 1000000005;
		for(int i = 1; i <= n; i++){
			mxx = max(mxx, a[i][x]);
			mnx = min(mnx, a[i][x]);
		}
		for(int i = 1; i <= m; i++){
			mxy = max(mxy, a[i][y]);
			mny = min(mny, a[i][y]);
		}
		if(mxx < mny) return true;
		if(mxx > mxy) return false;
		int i = 1, j = 1;
		//while(i <= n + 1 )
	}
	void work(){
		if(check(n, m, 0, 1))
			printf("1");
		else
			printf("0");
		while(q--){
			mycopy();
			int kx, ky;
			scanf("%d%d", &kx, &ky);
			while(kx--){
				int p, v;
				scanf("%d%d", &p, &v);
				d[p][0] = v;
			}
			while(ky--){
				int p, v;
				scanf("%d%d", &p, &v);
				d[p][1] = v;
			}
			if(check(n, m, 0, 1))
				printf("1");
			else
				printf("0");
		}
	}
}*/
int main () {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &c, &n, &m, &q);
	if(c == 1){
		Solve1::work();
		return 0;
	}
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	if(c == 2){
		Solve2::work();
		return 0;
	}
	/*Solve2::work();*/
	return 0;
}