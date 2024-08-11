#include<stdio.h>
typedef long long ll;
const int maxn=2000001;
char s[maxn];
int f[maxn],g[maxn][26];
int main(){
	freopen("game.in","r",stdin),freopen("game.out","w",stdout);
	int n;ll res=0;
	scanf("%d %s",&n,s+1);
	for(int i=1;i<=n;++i)s[i]-='a';
	for(int i=0;i<26;++i)g[0][i]=-1;
	for(int i=1,j;i<=n;++i){
		if(~g[i-1][s[i]]){
			f[i]=f[j=g[i-1][s[i]]]+1;
			for(int k=0;k<26;++k)g[i][k]=g[j][k];
		}else{
			for(int k=0;k<26;++k)g[i][k]=-1;
		}
		g[i][s[i]]=i-1;
		res+=f[i];
	}
	printf("%lld",res);
	return 0;
}
//I love lch(?