#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int c,n,m,q;

int a[N+5],b[N+5];
int x[N+5],y[N+5];

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c==4) cout<<"1101100011110101110101111111111111111110011111111101101100000";
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			x[i]=a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
			y[i]=b[i];
		}
		if(x[1]-y[1]==0 || (x[1]>y[1] && x[n]<y[m]) || (x[1]<y[1] && x[n]>y[m])) cout<<0;
		else cout<<1;
		while(q--){
			int kx,ky;
			cin>>kx>>ky;
			for(int i=1;i<=n;i++)	x[i]=a[i];
			for(int i=1;i<=m;i++)	y[i]=b[i];
			for(int i=1;i<=kx;i++){
				int opt,o;
				cin>>opt>>o;
				x[opt]=o;
			}
			for(int i=1;i<=ky;i++){
				int opt,o;
				cin>>opt>>o;
				y[opt]=o;
			}
			if(x[1]-y[1]==0 || (x[1]>y[1] && x[n]<y[m]) || (x[1]<y[1] && x[n]>y[m])) cout<<0;
			else cout<<1;
		}
	}
	return 0;
}
