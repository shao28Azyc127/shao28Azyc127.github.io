#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,kx,ky,p,v;
int x[100];
int y[100];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c==1){
		cin>>x[1]>>y[1];
		x[55]=x[1];
		y[55]=y[1];
		if(x[1]!=y[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		for(int i=1;i<=q;i++){
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++){
				cin>>p>>v;
				x[p]=v;
			}
			for(int j=1;j<=ky;j++){
				cin>>p>>v;
				y[p]=v;
			}
			if(x[1]!=y[1]){
				cout<<1;
			}else{
				cout<<0;
			}
			x[1]=x[55];
			y[1]=y[55];
		}
	}
	if(c==2){
		if(n==1 && m==1){
			cin>>x[1]>>y[1];
			x[55]=x[1];
			y[55]=y[1];
			if(x[1]!=y[1]){
				cout<<1;
			}else{
				cout<<0;
			}
			for(int i=1;i<=q;i++){
				cin>>kx>>ky;
				for(int j=1;j<=kx;j++){
					cin>>p>>v;
					x[p]=v;
				}
				for(int j=1;j<=ky;j++){
					cin>>p>>v;
					y[p]=v;
				}
				if(x[1]!=y[1]){
					cout<<1;
				}else{
					cout<<0;
				}
				x[1]=x[55];
				y[1]=y[55];
			}
			return 0;
		}
		if(n==1 && m==2){
			cin>>x[1]>>y[1]>>y[2];
			x[2]=x[55]=x[56]=x[1];
			y[55]=y[1];
			y[56]=y[2];
		}
		if(n==2 && m==1){
			cin>>x[1]>>x[2]>>y[1];
			y[2]=y[55]=y[56]=y[1];
			x[55]=x[1];
			x[56]=x[2];
		}
		if(n==2 && m==2){
			cin>>x[1]>>x[2]>>y[1]>>y[2];
			y[55]=y[1];
			y[56]=y[2];
			x[55]=x[1];
			x[56]=x[2];
		}
		if(x[1]>y[1]){
			if(x[2]>y[2]){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(x[1]<y[1]){
			if(x[2]<y[2]){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
		for(int i=1;i<=q;i++){
			cin>>kx>>ky;
			for(int j=1;j<=kx;j++){
				cin>>p>>v;
				x[p]=v;
			}
			for(int j=1;j<=ky;j++){
				cin>>p>>v;
				y[p]=v;
			}
			if(x[1]>y[1]){
				if(x[2]>y[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(x[1]<y[1]){
				if(x[2]<y[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
			x[1]=x[55];
			y[1]=y[55];
			x[2]=x[56];
			y[2]=y[56];
		}
	}
	return 0;
}