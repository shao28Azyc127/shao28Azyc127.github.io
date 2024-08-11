#include <bits/stdc++.h>
#define for0(i,n) for(i=0;i<(n);i++)
#define for1(i,n) for(i=1;i<=(n);i++)
#define forlr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;
const int N=2000005,M=30;
typedef long long ll;
ll ans;
int n,dp[N],t[N][M];
char s[N];
int g(int p){
	return s[p]-'a';
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%s",&n,s+1);
	int i,j,x;
	forlr(i,2,n){
		if(s[i]==s[i-1]) x=i-2;
		else x=t[i-1][g(i)]-1;
		if(x>=0){
			for0(j,26) t[i][j]=t[x][j];
			t[i][g(x)]=x;
			dp[i]=dp[x]+1;
		}
		ans+=dp[i];
		//printf("%d %d %d\n",i,x,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
