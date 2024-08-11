/*
不得不说考前看到这题叫 tribool 还以为会非常有水平。
多少有点尴尬。
这场怎么比 CSP2023-S 还要送啊。
考前立的及格线好像是 200，现在来看如果不上 300 可能还是会退役。
题很没水平。但我更没水平。差点忘了缩点。
好吧我是脑瘫，不难发现其实是个基环树，于是我甚至不用缩点。
*/
#include<stdio.h>
const int maxn=100010;
int f[maxn],g[maxn],q[maxn],s[maxn],v1[maxn],v2[maxn];
void dfs(int u){
	if(v1[u]){
		int v=f[u],c=g[u];
		for(;v!=u;v=f[v])c^=g[v];
		s[u]=!c,v2[u]=1;
		return;
	}
	if(v2[u])return;
	v1[u]=1;
	dfs(f[u]);
	s[u]=s[f[u]]*(g[u]?-1:1);
	v1[u]=0,v2[u]=1;
}
void work(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+3;++i)f[i]=i,g[i]=0,v1[i]=v2[i]=0;
	for(;m--;){
		char c;int i,j;
		scanf(" %c%d",&c,&i);
		if(c=='+'||c=='-')scanf("%d",&j),f[i]=f[j],g[i]=g[j]^(c=='-');
		else j=(c=='T'?n+3:(c=='F'?n+2:n+1)),f[i]=j,g[i]=0;
	}
	s[n+1]=0,s[n+2]=-1,s[n+3]=1,v2[n+1]=v2[n+2]=v2[n+3]=1;;
	for(int i=1;i<=n;++i)if(!v2[i])dfs(i);
	int cnt=0;
	for(int i=1;i<=n;++i)cnt+=(s[i]==0);
	printf("%d\n",cnt);
}
int main(){
	freopen("tribool.in","r",stdin),freopen("tribool.out","w",stdout);
	int t;
	for(scanf("%*d%d",&t);t--;work());
	return 0;
}