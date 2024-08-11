#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	int x[n];
	for(int i=0;i<=n-1;i++){
		cin>>x[i];
	}
	int y[m];
	for(int i=0;i<=m-1;i++){
		cin>>y[i];
	}
	if(c==1){
		if(x[0]!=y[0]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		int xx[n],yy[m];
		for(int i=0;i<=n-1;i++){
			xx[i]=x[i];
		}
		for(int i=0;i<=m-1;i++){
			yy[i]=y[i];
		}
		for(int i=0;i<=q-1;i++){
			int kx,ky;
			cin>>kx>>ky;
			for(int j=0;j<=kx-1;j++){
				int px,vx;
				cin>>px>>vx;
				xx[px-1]=vx;
			}
			for(int j=0;j<=ky-1;j++){
				int py,vy;
				cin>>py>>vy;
				yy[py-1]=vy;
			}
			if(xx[0]!=yy[0]){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
	}
	return 0;
}