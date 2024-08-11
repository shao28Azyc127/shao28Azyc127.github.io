#include<bits/stdc++.h>
using namespace std;

int n,d;
const int maxn=1e5+10;
int v[maxn],a[maxn];
int sumv[maxn];
int ans=INT_MAX;

void dfs(int cur,double lef,int cost){
	if(cur==n){
		ans=min(ans,cost);
		return;
	}
	for(int i=cur+1;i<=n;i++){
		int length=sumv[i-1]-sumv[cur-1];
		int need=ceil((length-lef*d)/(d*1.0));
		dfs(i,(lef*d+need*d-length)/(d*1.0),cost+need*a[cur]);
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++)cin>>v[i],sumv[i]=sumv[i-1]+v[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
