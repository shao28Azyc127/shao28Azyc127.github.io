#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int INTMAX=2147483647;
int ansmin=INTMAX;
int n,d,lenth;
int v[100005],a[100005],mak[100005],l;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	v[1]=0;
	for(int i=2; i<=n; i++)
	{
		cin>>v[i];
		v[i]+=v[i-1];
	}
	for(int i=1; i<=n; i++)
	{
		if(v[i]%d==0) v[i]/=d;
		else v[i]=v[i]/d+1;
	}
	cout<<endl;
	int mint=INTMAX;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		mint=min(mint,a[i]);
	}
	if(mint==a[1])
	{
		cout<<v[n]*a[1]<<endl;
		return 0;
	}
	mint=a[1];
	int minnum=1;
	int ans=v[1]*mint;
	for(int i=2; i<=n; i++)
	{
		if(mint<a[i]) ans+=(v[i]-v[minnum])*mint;
		if(mint>=a[i])
		{
			mint=a[i];
			minnum=i;
			ans+=(v[i]-v[i-1])*mint;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
 XXX       XXX     KKK    KKK
  XXX     XXX	   KKK   KKK
   XXX   XXX	   KKK  KKK
    XXX XXX		   KKK KKK
      XXX		   KKKKKK
    XXX XXX		   KKK KKK
   XXX   XXX	   KKK  KKK
  XXX     XXX	   KKK   KKK
 XXX       XXX	   KKK    KKK
XXX         XXX    KKK     KKK
 */
