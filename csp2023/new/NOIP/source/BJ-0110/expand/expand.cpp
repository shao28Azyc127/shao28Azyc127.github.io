#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int c,n,m,q;
int a[N],b[N];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin >> c >> n >> m >> q;
	for(int i = 1;i <= n;++i) cin >> a[i];
	for(int i = 1;i <= m;++i) cin >> b[i];
	if(n == 1 && m == 1)
	{
		if(a[1] == b[1]) cout << 0;
		else cout << 1;
	}
	else cout << 0;
	for(int i = 1;i <= q;++i) 
	{
		int k1,k2;
		cin >> k1 >> k2;
		for(int j = 1;j <= k1;++j)
		{
			int p,x;
			cin >> p >> x;
			a[p] = x;
		}
		for(int j = 1;j <= k2;++j)
		{
			int p,x;
			cin >> p >> x;
			b[p] = x;
		}
		if(n == 1 && m == 1)
		{
			if(a[1] == b[1]) cout << 0;
			else cout << 1;
		}
		else cout << 0;
	}
	return 0;
}
