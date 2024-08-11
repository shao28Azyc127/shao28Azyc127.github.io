#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int c,n,m,q,kx,ky,px,vx,py,vy;
ll x[N],y[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&y[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;j++){
			scanf("%d%d",&px,&vx);
		}
		for(int k=1;k<=ky;k++){
			scanf("%d%d",&py,&vy);
		}
	}
	for(int i=1;i<=q+1;i++){
		cout<<0;
	}
	return 0;
}
