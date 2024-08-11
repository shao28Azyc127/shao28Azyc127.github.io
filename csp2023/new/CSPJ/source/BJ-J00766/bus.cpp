#include<bits/stdc++.h>
using namespace std;
struct node{
	int b,c,d;
}a[20005];
int n,m,k,minn=1e9;
void dfs(int w,int t){
	if(w==n&&t%k==0){
		minn=min(t,minn);
		return; 
	}
	if(w==n) return;
	for(int i=1;i<=m;i++){
		if(t>=a[i].d&&w==a[i].b){
			dfs(a[i].c,t+1);
		}
	}
	if(t==k){
		cout<<minn;
	}
}
int main(){
       freopen("bus.in","r",stdin);
      freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].b>>a[i].c>>a[i].d;
	}
	dfs(1,k);
	return 0;
}
