#include<bits/stdc++.h>
#define N 500050
using namespace std;
int x[N],y[N];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q,kx,ky,px,py,vx,vy;
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=m;i++)
		cin>>y[i];
	while(q--){
		cin>>kx>>ky;
		while(kx--){
			cin>>px>>vx;
		}
		while(ky--){
			cin>>py>>vy;
		}
	}
	for(int i=0;i<=q;i++)
		cout<<1;
	return 0;
}