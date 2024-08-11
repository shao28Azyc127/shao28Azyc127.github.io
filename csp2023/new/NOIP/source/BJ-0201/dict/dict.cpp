#include<bits/stdc++.h>
using namespace std;

#define MAXN 3005

int n,m;
char w[MAXN][MAXN],minn[MAXN][MAXN],maxx[MAXN][MAXN];

int buc[28],mini,cmini;

//A > B -> 1,A < B -> -1,A = B -> 0
inline int cmp( char *A , char *B ){
	for( int i = 1 ; i <= m ; i ++ ){
		if( A[i] < B[i] ) return -1;
		if( A[i] > B[i] ) return 1;
	} return 0;
}

signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%s",w[i] + 1);
	if( n == 1 ){ puts("1"); return 0; }
	for( int i = 1 ; i <= n ; i ++ ){
		memset( buc , 0 , sizeof( buc ) );
		for( int j = 1 ; j <= m ; j ++ ) buc[w[i][j] - 'a'] ++;
		int lent = 0;
		for( int k = 0 ; k < 26 ; k ++ )
			for( int t = 1 ; t <= buc[k] ; t ++ ) minn[i][++lent] = k + 'a';
		lent = 0;
		for( int k = 25 ; k >= 0 ; k -- )
			for( int t = 1 ; t <= buc[k] ; t ++ ) maxx[i][++lent] = k + 'a';
	}
	mini = 1;
	for( int i = 2 ; i <= n ; i ++ ){
		int tmp = cmp( maxx[mini] , maxx[i] );
		if( tmp >= 0 ) cmini = mini,mini = i;
		else{
			tmp = cmp( maxx[cmini] , maxx[i] );
			if( !cmini || tmp >= 0 ) cmini = i;
		}
	}
	// printf("%d %d\n",mini,cmini);
	for( int i = 1 ; i <= n ; i ++ ){
		if( i != mini ){
			int tmp = cmp( minn[i] , maxx[mini] );
			if( tmp >= 0 ) printf("0");
			else printf("1");
		} else {
			int tmp = cmp( minn[i] , maxx[cmini] );
			if( tmp >= 0 ) printf("0");
			else printf("1");
		}
	} puts("");
	return 0;
}