#include<bits/stdc++.h>
using namespace std;
int n,d;
long long now,sv[100010],v[100010],a[100010],ans;
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;++i) cin>>v[i],sv[i+1]=sv[i]+v[i];
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1,j;i<=n&&now<sv[n];++i){
		for(j=i+1;j<=n&&now<sv[n];++j)
			if(a[j]<a[i]) break;
		j=min(j,n);
		if(sv[j]>now){
			int x=(sv[j]-now)/d+(((sv[j]-now)%d)?1:0);
			ans+=x*a[i],now+=x*d;
		}
		//cout<<now<<" "<<ans<<"\n";
		i=j-1;
	}
	cout<<ans;
	return 0;
}