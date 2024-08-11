#include <iostream>
#include <cmath>
using namespace std;
const int N=1e5+5;
int n,d,now;
int f[N];
struct node{
	int cost,dis;
}a[N];
/*int find(int place,int cost)
{
	if(place>=a[n].dis)
	{
		return cost;
	}
	for(int i=place;i<=n;i++)
	{
	}
}*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y;
	cin>>n>>d;
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		a[i].dis=a[i-1].dis+x;
	}
	for(int i=1;i<=n;i++) cin>>a[i].cost;
	//find(0,0);
	f[1]=0;
	for(int i=2;i<=n;i++)
	{
		f[i]=1e9;
		for(int j=1;j<i;j++)
		{
			
			if(y>=(a[i].dis-a[j].dis))
			{
				y=y-(a[i].dis-a[j].dis);
				f[i]=min(f[i],f[j]);
				//cout<<"A";
				continue;
			}
			f[i]=min(f[i],(a[i].dis-a[j].dis+d-1-y)/d*a[j].cost+f[j]);
			y=(a[i].dis-a[j].dis+d-1)/d*d-a[i].dis-a[j].dis;
			//cout<<f[i]<<" "<<y<<" ";
		}
	}
	cout<<f[n]<<endl;
	return 0;
}
