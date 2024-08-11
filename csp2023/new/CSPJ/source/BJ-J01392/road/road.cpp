#include<bits/stdc++.h>
using namespace std;

const long long N=1e5;

long long n,d;
long long v[N+5];
long long a[N+5];
long long far[N+5];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		scanf("%lld",&v[i]);
		far[i+1]=far[i]+v[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long frt=1,now=0;
	long long ans=0;
	for(int i=2;i<=n;i++){
		if(i==n){
			if(now<far[i]){
				ans+=a[frt]*((far[i]-now+d-1)/d);
				now=now+d*((far[i]-now+d-1)/d);
			}
		}
		else if(a[i]<a[frt]){
			if(now<far[i]){
				ans+=a[frt]*((far[i]-now+d-1)/d);
				now=now+d*((far[i]-now+d-1)/d);
			}
			frt=i;
		}
	}
	cout<<ans;
	return 0;
}
