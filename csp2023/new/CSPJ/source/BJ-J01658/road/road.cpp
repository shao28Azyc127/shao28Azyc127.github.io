#include<iostream>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
ll a[100005],v[100005],n,d,ans;
double car;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	ll num=100005,dis=0;
	for(int i=1;i<n;i++) cin>>v[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]<num)
		{
			//cout<<"i:"<<i<<" dis:"<<dis<<" num:"<<num<<" car:"<<car<<endl;
			if(car < dis*1.0/d)
			{
				int cur=ceil(dis*1.0/d-car);
				car=cur-dis*1.0/d+car;
				ans+=cur*num;
			}
			else car-=dis*1.0/d;
			/*ans+=max(int(ceil(dis*1.0/d-car)*num),0);
			car=max(int(ceil(dis*1.0/d-car)*num-(dis*1.0/d-car)*num),0);*/
			dis=0;
			num=a[i];
		}
		dis+=v[i];
		//cout<<"i:"<<i<<" ans:"<<ans<<endl;
	}
	cout<<ans+ceil(dis*1.0/d-car)*num;
	return 0;
}