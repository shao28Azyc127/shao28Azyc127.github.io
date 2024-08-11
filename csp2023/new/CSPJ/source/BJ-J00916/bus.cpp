#include<bits/stdc++.h>
using namespace std;

int n,m,k,u[20010],v[20010],a[20010],ans=1e9;

void f(int x,int y,int z){
	if(x==n){
		if(y%k!=0){
			return;
		}
		else{
			if(z%k==0){
				ans=min(ans,z+y);
			}
			else{
				ans=min(ans,k-z%k+z+y);
			}
			return;
		}
	}
	for(int i=1;i<=m;++i){
		if(u[i]==x){
			f(v[i],y+1,max(z,a[i]-y));
		}
	}
}

int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i]>>a[i];
	}
	f(1,0,0);
	cout<<ans;
	
	
	return 0;
}
