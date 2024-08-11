#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int c,n,m,q,a[500005],b[500005];
int oria[500005],orib[500005];
int dpx[2005][2005],dpn[2005][2005];
void init(){
	for(int i=1;i<=n;i++){
	for(int j=0;j<=m;j++){
		dpx[i][j]=0;
		dpn[i][j]=0;
	}}
	for(int i=1;i<=n;i++) a[i]=oria[i];
	for(int i=1;i<=m;i++) b[i]=orib[i];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i],oria[i]=a[i];
	for(int i=1;i<=m;i++) cin>>b[i],orib[i]=b[i];
	//mx
	dpx[1][1]=(a[1]>b[1]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]<=b[j]) {
				dpx[i][j]=0;
				continue;
			}
			dpx[i][j]|=dpx[i][j-1];
			dpx[i][j]|=dpx[i-1][j]|dpx[i-1][j-1];
		}
	}
	dpn[1][1]=(a[1]<b[1]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]>=b[j]) {
				dpn[i][j]=0;
				continue;
			}
			dpn[i][j]|=dpn[i][j-1];
			dpn[i][j]|=dpn[i-1][j]|dpn[i-1][j-1];
		}
	}
//	cout<<dpx[n%2][m]<<" "<<dpn[n%2][m]<<endl;
	cout<<(dpx[n][m]|dpn[n][m]);
	for(int i=1;i<=q;i++){
		init();
		int kx,ky;
		cin>>kx>>ky;
		for(int j=1;j<=kx;j++){
			int vi,vx;
			cin>>vi>>vx;
			a[vi]=vx;
		}
		for(int j=1;j<=ky;j++){
			int vi,vy;
			cin>>vi>>vy;
			b[vi]=vy;
		}
		dpx[1][1]=(a[1]>b[1]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]<=b[j]) {
					dpx[i][j]=0;
					continue;
				}
				dpx[i][j]|=dpx[i][j-1];
				dpx[i][j]|=dpx[i-1][j]|dpx[i-1][j-1];
			}
		}
		dpn[1][1]=(a[1]<b[1]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]>=b[j]) {
					dpn[i][j]=0;
					continue;
				}
				dpn[i][j]|=dpn[i][j-1];
				dpn[i][j]|=dpn[i-1][j]|dpn[i-1][j-1];
			}
		}
		cout<<(dpx[n][m]|dpn[n][m]);
	}
	return 0;
}
