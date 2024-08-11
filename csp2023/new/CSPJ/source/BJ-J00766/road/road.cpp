#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],b[100005],vs[100005],ans=0,stat=1,mstat,yx=0,kkk,sc,temp;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
		vs[i]=vs[i-1]+v[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(stat<n){
		mstat=n;
		for(int i=stat;i<=n;i++){
			if(a[stat]>a[i]){
				mstat=i;
				break;
			}
		}
		b[stat]=vs[mstat-1]-vs[stat-1];
		sc=b[stat];
		if(b[stat]%d!=0){
			b[stat]+=d;
		}
		b[stat]/=d;
		temp=b[stat]-1;
	    kkk=b[stat]*d;
	    yx+=kkk-sc;
		b[stat]*=a[stat];
		if(yx+temp>=a[stat]&&stat!=n){
			ans-=a[stat];
			yx=(yx+temp-a[stat]);
		}
		ans+=b[stat];
		stat=mstat;
	}
	cout<<ans;
	return 0;
}
