#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N];
int n;
int ans=0;
int st(int x,int d){
	int h=0;
	while(h<a[x]){
		h+=max(b[x]+d*c[x],1);
		d++;
	}
	//cout<<d-1<<endl;
	return d-1;
}
void dfs(int x,int d){
	if(x>n) return;
	ans=max(ans,st(x,d));
	dfs(x+1,d+1);
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
