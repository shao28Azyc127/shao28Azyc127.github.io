#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct station
{
	int price,dis,num;
};
int cmp(station a,station b)
{
	if(a.price!=b.price) return a.price<b.price;
	return a.num>b.num;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n; cin>>n;
	station a[n];
	int d[n],p[n],s[n];
	for(int i=0;i<n-1;i++) cin>>d[i];
	for(int i=0;i<n;i++) cin>>p[i];
	int ans=0;
	for(int i=0;i<n;i++)
	{
		a[i].price=p[i];
		a[i].num=i;
	}
	s[n-1]=0;
	for(int i=n-2;i>=0;i--)  s[i]=s[i+1]+d[i];
	sort(a,a+n,cmp);
	int visit=n-1;
	for(int i=0;i<n && visit!=0;i++) 
	{
		cout<<a[i].price<<" "<<a[i].num<<endl;
		ans=ans+(s[a[i].num]-s[visit])*a[i].price;
		visit=i;
	}
	cout<<ans<<endl;
	return 0;
}
