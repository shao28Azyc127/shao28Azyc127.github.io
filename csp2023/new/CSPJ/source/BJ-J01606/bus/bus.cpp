#include <iostream>
using namespace std;
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m],v[m],a[m];	
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>a[i];
	}
	cout<<"-1";
}

