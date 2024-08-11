#include<bits/stdc++.h>
using namespace std;
long long n,d,v[100005],a[100005],z[100005];
void caseA()
{
	long long ans=z[n-1];
	ans=z[n-1]/d;
	if(z[n-1]%d>0)ans++;
	cout<<ans*a[1];
	}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++)cin>>v[i],z[i]=z[i-1]+v[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	caseA();
return 0;	
}
