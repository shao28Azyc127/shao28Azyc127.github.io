#include<bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i=(a);i<(b);i++)
const int N=100011;
int w[N],a[N],n,d;
unsigned long long ans=0;
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>d;
	_for(i,1,n)cin>>w[i];
	_for(i,1,n+1)cin>>a[i];
	int t=1,tem=0,temp;
	while(t<n){
		for(int i=t;i<=n;i++){
			//if(i==n){ans+=(tem/d+1)*a[t];cout<<ans<<endl;return 0;}
			if(a[i]<a[t]){temp=i;break;}
			tem+=w[i];
		}
		if(tem%d==0){ans+=(tem/d)*a[t];}
		else ans+=(((tem/d)+1)*a[t]);
		tem=(tem%d)-d;
		//cout<<ans<<" ";
		t=temp;
		temp=n;
	}
	cout<<ans<<endl;
	return 0;
}

