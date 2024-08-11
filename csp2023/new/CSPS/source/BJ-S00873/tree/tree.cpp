#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,x,y;
int a[100010],b[100010],c[100010];
long long dp[100010];
int first[200010],nxt[200010],to[200010],cnt;
void add(int u,int v){
	nxt[++cnt]=first[u];
	first[u]=cnt;
	to[cnt]=v;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	cout<<n;
	return 0;
}
