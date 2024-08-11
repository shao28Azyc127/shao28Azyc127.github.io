#include<bits/stdc++.h>
using namespace std;

#define MAXN 2005

int n,m,A[MAXN],B[MAXN],a[MAXN],b[MAXN];
int f[MAXN][MAXN];

inline void solve(){
	if( a[1] == b[1] ){ printf("0"); return; }
	//如果我的下一个大于我，就移动过去
	//否则将 b 移动到尽可能小的位置。中间产生矛盾则失败
	// for( int i = 1 ; i <= n ; i ++ ) printf("%d ",a[i]); puts("");
	// for( int j = 1 ; j <= m ; j ++ ) printf("%d ",b[j]); puts("");
	memset( f , 0 , sizeof( f ) );
	if( a[1] > b[1] ){
		f[n][m] = a[n] > b[m];
		for( int i = n - 1 ; i >= 1 ; i -- ) if( a[i] > b[m] ) f[i][m] = f[i + 1][m];
		for( int i = m - 1 ; i >= 1 ; i -- ) if( a[n] > b[i] ) f[n][i] = f[n][i + 1];
		for( int i = n - 1 ; i >= 1 ; i -- ){
			for( int j = m - 1 ; j >= 1 ; j -- ){
				if( a[i] > b[j] ) f[i][j] = f[i + 1][j] | f[i][j + 1];
			}
		}
		printf("%d",f[1][1]);
	}
	else{
		f[n][m] = a[n] < b[m];
		for( int i = n - 1 ; i >= 1 ; i -- ) if( a[i] < b[m] ) f[i][m] = f[i + 1][m];
		for( int i = m - 1 ; i >= 1 ; i -- ) if( a[n] < b[i] ) f[n][i] = f[n][i + 1];
		for( int i = n - 1 ; i >= 1 ; i -- ){
			for( int j = m - 1 ; j >= 1 ; j -- ){
				if( a[i] < b[j] ) f[i][j] = f[i + 1][j] | f[i][j + 1];
			}
		}
		printf("%d",f[1][1]);
	}
}

signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int tid,q; scanf("%d%d%d%d",&tid,&n,&m,&q);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&A[i]);
	for( int i = 1 ; i <= m ; i ++ ) scanf("%d",&B[i]);
	for( int i = 1 ; i <= n ; i ++ ) a[i] = A[i];
	for( int i = 1 ; i <= m ; i ++ ) b[i] = B[i];
	solve();
	for( int i = 1 ; i <= q ; i ++ ){
		int kx,ky; scanf("%d%d",&kx,&ky);
		for( int j = 1 ; j <= n ; j ++ ) a[j] = A[j];
		for( int j = 1 ; j <= m ; j ++ ) b[j] = B[j];
		for( int j = 1 ; j <= kx ; j ++ ){ int p,v; scanf("%d%d",&p,&v); a[p] = v; }
		for( int j = 1 ; j <= ky ; j ++ ){ int p,v; scanf("%d%d",&p,&v); b[p] = v; }
		solve();
	}
	puts("");
	return 0;
}