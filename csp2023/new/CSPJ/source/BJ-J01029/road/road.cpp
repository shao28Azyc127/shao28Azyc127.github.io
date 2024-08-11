#include<iostream>
#include<cmath>
using namespace std;
int n,d,v[10001],a,mina,i=0;
long long int dis=0,cost=0,lef=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++)
		cin>>v[i];
    cin>>mina;
	for(int i=1;i<n;i++)
	{
		cin>>a;
		dis+=v[i];
		if(a<mina)
		{
		    int vi=dis-lef;
		    int l=ceil((float)vi/d);
			cost+=l*mina;
			lef=l*d-vi;
			dis=0;
			mina=a;
		}
	}
	int vi=dis-lef;
    int l=ceil((float)vi/d);
    cost+=l*mina;
	cout<<cost;
	return 0;
}
