#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,a[10][6],pas[6],Ans;

inline int diff( int ori , int nnw ){ return nnw > ori ? nnw - ori : 10 - ori + nnw; }

inline bool chk(){
	for( int i = 1 ; i <= n ; i ++ ){
		bool flag = 0;
		for( int j = 1 ; j <= 5 ; j ++ ) if( a[i][j] != pas[j] ){ flag = 1; break; }
		if( !flag ) return 0;
		bool can1 = 0,can2 = 0;
		for( int j = 1 ; j <= 5 ; j ++ ){
			if( a[i][j] == pas[j] ) continue;
			flag = 0;
			for( int k = 1 ; k <= 5 ; k ++ ){
				if( k == j ) continue;
				if( a[i][k] != pas[k] ){ flag = 1; break; }
			}
			if( flag ) continue;
			can1 = 1; break;
		}
		if( !can1 ){
			for( int j = 1 ; j <= 4 ; j ++ ){
				int k = j + 1;
				int d1 = diff( pas[j] , a[i][j] ),d2 = diff( pas[k] , a[i][k] );
				if( d1 != d2 || d1 == 0 ) continue;
				flag = 0;
				for( int l = 1 ; l <= 5 ; l ++ ){
					if( l == j || l == k ) continue;
					if( a[i][l] != pas[l] ){ flag = 1; break; }
				}
				if( flag ) continue;
				can2 = 1; break;
			}
		}
		if( !can1 && !can2 ) return 0;
	} return 1;
}

void dfs( int x ){
	if( x == 6 ){ Ans += chk(); return; }
	for( int i = 0 ; i <= 9 ; i ++ ){
		pas[x] = i;
		dfs( x + 1 );
	}
}

signed main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%lld",&n);
	for( int i = 1 ;  i <= n ; i ++ )
		for( int j = 1 ; j <= 5 ; j ++ ) scanf("%lld",&a[i][j]);
	dfs( 1 );
	printf("%lld\n",Ans);
	return 0;
}