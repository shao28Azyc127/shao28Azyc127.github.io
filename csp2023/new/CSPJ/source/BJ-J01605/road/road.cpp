#include<bits/stdc++.h>
using namespace std;
const int maxn=100000000+5;
long long n,d,ans=0,younum=0;
int v[maxn]={},a[maxn]={};
int main()
{
	

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;//5 4
	for(long long i=1;i<=n-1;i++){
		cin>>v[i];//5 4 10 10 10 10 10 9 8 9 6 5 
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];//9 8 9 6 5 
	}
	long long mq=0;
	for(long long i=1;i<=n-1;i++){
		if(a[i+1]>=a[i]) a[i+1]=a[i];
		younum-=v[i-1];
		mq=(v[i]-younum)/d;
		while(mq*d+younum<v[i]) mq+=1;
		ans+=mq*a[i];
		
		younum+=mq*d;
	
	}
	cout<<ans;
	return 0;
}
