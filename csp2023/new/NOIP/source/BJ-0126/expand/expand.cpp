#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
int n,m,q,t;
int a[500010],b[500010];
int aa[500010],bb[500010];
void dfs(int x,int y,int k){
	if(x==n+1||y==m+1) return;
	if(x==n&&y==m){
		t=1;return;
	}
	if(k==1&&a[x+1]>b[y]) dfs(x+1,y,k);
	if(k==1&&a[x]>b[y+1]) dfs(x,y+1,k);
	if(k==1&&a[x+1]>b[y+1]) dfs(x+1,y+1,k);
	if(k==0&&a[x+1]<b[y]) dfs(x+1,y,k);
	if(k==0&&a[x]<b[y+1]) dfs(x,y+1,k);
	if(k==0&&a[x+1]<b[y+1]) dfs(x+1,y+1,k);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int T;cin>>T>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i],aa[i]=a[i];
	for(int i=1;i<=m;i++) cin>>b[i],bb[i]=b[i];
	if(a[1]<b[1]) dfs(1,1,0);
	if(a[1]>b[1]) dfs(1,1,1);
	cout<<t;
	for(int i=1;i<=q;i++){
		int m1,m2;cin>>m1>>m2;
		for(int j=1;j<=m1;j++){
			int x,y;cin>>x>>y;a[x]=y;
		}
		for(int j=1;j<=m2;j++){
			int x,y;cin>>x>>y;b[x]=y;
		}
		t=0;
		if(a[1]<b[1]) dfs(1,1,0);
		if(a[1]>b[1]) dfs(1,1,1);
		cout<<t;
		for(int j=1;j<=n;j++) a[j]=aa[j];
		for(int j=1;j<=m;j++) b[j]=bb[j];
	}
	return 0;
}
