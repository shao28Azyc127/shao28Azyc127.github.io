#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+7;
const int maxm=5e5+7;
int x[maxn],y[maxm];

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,m,n,q;
	cin >> c >> m >> n >> q;
	cout << m << n << endl;
	for(int i=1;i<=n;i++)
		cin >> x[i];
	for(int i=1;i<=m;i++)
		cin >> y[i];
	if(c==1)
	{
		cout << bool(x[1]!=y[1]);
		while(q--)
		{
			int tmpx[maxn],tmpy[maxn];
			for(int i=1;i<=n;i++)tmpx[i]=x[i],tmpy[i]=y[i];
			int kx,ky;
			cin >> kx >> ky;
			for(int i=1;i<=kx;i++)
			{
				int p,v;
				cin >> p >> v;
				tmpx[p]=v;
			}
			for(int i=1;i<=ky;i++)
			{
				int p,v;
				cin >> p >> v;
				tmpy[p]=v;
			}
			cout << bool(tmpx[1]!=tmpy[1]);
		}
	}
	if(c==2)
	{
		if(m<n )cout << bool(x[1]>max(y[1],y[2])||x[1]<min(y[1],y[2]));
		if(m>n )cout << bool(y[1]>max(x[1],x[2])||y[1]<min(x[1],x[2]));
		if(m==n)cout << bool((x[1]-y[1])*(x[2]-y[2])>0);
		while(q--)
		{
			int tmpx[maxn],tmpy[maxn];
			for(int i=1;i<=n;i++)tmpx[i]=x[i],tmpy[i]=y[i];
			int kx,ky;
			cin >> kx >> ky;
			for(int i=1;i<=kx;i++)
			{
				int p,v;
				cin >> p >> v;
				tmpx[p]=v;
			}
			for(int i=1;i<=ky;i++)
			{
				int p,v;
				cin >> p >> v;
				tmpy[p]=v;
			}
			if(m<n )cout << bool(tmpx[1]>max(tmpy[1],tmpy[2])||tmpx[1]<min(tmpy[1],tmpy[2]));
			if(m>n )cout << bool(tmpy[1]>max(tmpx[1],tmpx[2])||tmpy[1]<min(tmpx[1],tmpx[2]));
			if(m==n)cout << bool((tmpx[1]-tmpy[1])*(tmpx[2]-tmpy[2])>0);
		}
	}
return 0;
}
