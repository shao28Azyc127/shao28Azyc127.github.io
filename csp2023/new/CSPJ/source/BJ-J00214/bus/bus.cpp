#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int mxt=0;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		mxt=max(mxt,c);
	}
	if(mxt%k==0) cout<<mxt+k;
	else cout<<mxt/k*k+k+k;
	return 0;
}
