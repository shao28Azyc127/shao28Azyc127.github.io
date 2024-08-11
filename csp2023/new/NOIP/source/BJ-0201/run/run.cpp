#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1005

int f[MAXN][MAXN],n,m,k,d,cmax[MAXN],trp[MAXN];
vector< pair<int,int> > seg[MAXN];

inline void solve(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	for( int i = 1 ; i <= n ; i ++ ) seg[i].clear();
	for( int i = 1 ; i <= m ; i ++ ){
		int x,y,v; scanf("%lld%lld%lld",&x,&y,&v);
		seg[x].emplace_back( make_pair( y , v ) );
	}
	for( int i = 0 ; i <= n ; i ++ ){
		cmax[i] = -2e18;
		for( int j = 0 ; j <= n ; j ++ ) f[i][j] = -2e18;
	}
	f[0][0] = 0,cmax[0] = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		f[i][0] = cmax[i - 1];
		memset( trp , 0 , sizeof( trp ) );
		for( pair<int,int> segs : seg[i] ){
			int y = segs.first,v = segs.second;
			trp[i - y + 1] += v;
		}
		for( int j = i ; j >= 1 ; j -- ) trp[j] += trp[j + 1];
		for( int j = 1 ; j <= min( i , k ) ; j ++ ) f[i][j] = f[i - 1][j - 1] - d + trp[i - j + 1];
		for( int j = 0 ; j <= min( i , k ) ; j ++ ) cmax[i] = max( cmax[i] , f[i][j] );
	}
	printf("%lld\n",cmax[n]);
}

signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int tid,testcase; scanf("%lld%lld",&tid,&testcase);
	while( testcase -- ) solve();
	return 0;
}