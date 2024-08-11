#include<iostream>
using namespace std;
int v[100005],a[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>a[i];
	}
	cout<<n/d*a[1];
	return 0;
}
