#include <bits/stdc++.h>
#derfine N 100010;
using namespace std;

int v[N],a[N];
long long cnt;

int main()
{
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int j=1;j<=d;j++)
		cin>>a[d];
	int wps=1,m;
	double k;
	if(wps<=n)
	{
		for(int x=wps+1;i<=n;i++)
		{
			m=+=v[i-1];
			if(a[i]<=a[wps])
			{
				wps=i;
				break;
			}

		}
		cout<<wps<<" "<<m;
	}
	return 0;
}
