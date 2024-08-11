#include<bits/stdc++.h>
using namespace std;

#define MAXN 8005

int n,mid,rmax,len,r[MAXN];
bool f[MAXN][MAXN];
char s[MAXN];

vector<int> rat[MAXN];

signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%s",&n,s + 1);
	for( int i = 1 ; i <= n ; i ++ ) f[i][i - 1] = 1;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = i - 1 ; j >= 1 ; j -- ){
			if( s[i] == s[j] && f[j + 1][i - 1] ){
				rat[i].emplace_back( j ),f[j][i] = 1;
				for( int k : rat[j - 1] ) rat[i].emplace_back( k ),f[k][i] = 1;
				break;
			}
		}
	}
	int Ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) Ans += (int)rat[i].size();
	printf("%d\n",Ans);
	return 0;
}