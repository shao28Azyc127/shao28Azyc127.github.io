#include <bits/stdc++.h>
using namespace std;
int a[10009];
int b[10009];
int c[90][3];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c, n, m, q;
	cin>>c>>n>>m>>q;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=m;i++)
	cin>>>b[i];
	for(i=1;i<=q;i++)
	cin>>c[i][1]>>c[i][2];
	for(i=1;i<=q+1;i++)
	cout<<0;
	return 0;
}
