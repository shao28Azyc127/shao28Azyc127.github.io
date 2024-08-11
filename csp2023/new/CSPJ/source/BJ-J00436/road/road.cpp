#include<bits/stdc++.h>
using namespace std;
int n,d,u[100010],a[100010];
int ans=100010;
int dfs(int now,int price,int nowdis){
	if(now==n-1) return price;
	for(int i=now+1;i<n;i++){
		int dis=u[i]-u[now]-nowdis;
		int count=ceil(float(dis)/float(d));
		ans=min(ans,dfs(i,price+count*a[now],d*count-dis));
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++) cin>>u[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<n;i++) u[i]+=u[i-1];
	dfs(1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}