#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int main(){
	int i,sj,lc,jg,sy=0,x=1,j,ans=0,n,d,zs;
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(i=1;i<n;i++){
		cin>>v[i];
	}
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	i=1;
	while(x<n){
		j=i+1;
		zs=1;
		while(a[j]>=a[i]){
			j++;
			zs++;
		}
		lc=0;
		for(int k=i;k<j;k++){
			lc+=v[k];
		}
		lc-=sy;
		sj=ceil(1.0*lc/d);
		jg=sj*a[i];
		sy=(sj*d)-lc;
		ans+=jg;
		i=j;
		x+=zs;
	}
	cout<<ans;
	return 0;
}