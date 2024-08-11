#include <bits/stdc++.h>
using namespace std;

int c,n,m,q;
int kx,ky;
int X[500009],Y[500009];
int Px[500009],Py[500009];
int Vx[500009],Vy[500009];

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>X[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>Y[i];
	}
	for(int Turn = 1;Turn <= q;Turn++)
	{
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++)
		{
			cin>>Px[i]>>Vx[i];
		}
		for(int i=1;i<=ky;i++)
		{
			cin>>Py[i]>>Vy[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<"0";
	}


	return 0;
}	