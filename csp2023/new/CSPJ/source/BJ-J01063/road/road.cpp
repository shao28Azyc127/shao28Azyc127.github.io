#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,d,p[100010],b[100010],a[100010];
void dfs(int x,int cst){
	
	a[x]=min(a[x],cst);
	if(x==n){
		return;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,cst+(p[i-1]+d-1)/d*b[x]);
	}
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	memset(a,0x3f3f3f3f,sizeof(a));
	for(int i=1;i<n;i++){
		scanf("%lld",&p[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	dfs(1,0);
	printf("%lld",a[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
