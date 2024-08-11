#include<bits/stdc++.h>
using namespace std;
int c,n,m,oa[500005],ob[500005],a[500005],b[500005],q,kx,ky,px,py,vx,vy,f[2005][2005];
bool check1(){
	if(a[1]==b[1]||a[n]==b[m])return false;
	memset(f,0,sizeof(f));
	if(a[1]>b[1]){
		int r=1;
		while(a[1]>b[r+1]&&r<m)r++;
		f[1][1]=r;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(f[i-1][j]){
					for(int k=j;k<=f[i-1][j]+1;k++){
						if(a[i]<=b[k])continue;
						int r=k;
						while(a[i]>b[r+1]&&r<m)r++;
						f[i][k]=r;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(f[n][i]==m)return true;
		}
		return false;
	}else{
		int r=1;
		while(a[1]<b[r+1]&&r<m)r++;
		f[1][1]=r;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(f[i-1][j]){
					for(int k=j;k<=f[i-1][j]+1;k++){
						if(a[i]>=b[k])continue;
						int r=k;
						while(a[i]<b[r+1]&&r<m)r++;
						f[i][k]=r;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(f[n][i]==m)return true;
		}
		return false;
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> c >> n >> m >> q;
	if(c==1){
		for(int i=1;i<=n;i++)cin >> oa[i];
		for(int i=1;i<=m;i++)cin >> ob[i];
		for(int i=1;i<=n;i++)a[i]=oa[i];
		for(int i=1;i<=m;i++)b[i]=ob[i];
		if(a[1]!=b[1])cout << 1;
		else cout << 0;
		for(int i=1;i<=q;i++){
			for(int i=1;i<=n;i++)a[i]=oa[i];
			for(int i=1;i<=m;i++)b[i]=ob[i];
			cin >> kx >> ky;
			for(int j=1;j<=kx;j++){
				cin >> px >> vx;
				a[px]=vx;
			}
			for(int j=1;j<=ky;j++){
				cin >> py >> vy;
				b[py]=vy;
			}
			if(a[1]!=b[1])cout << 1;
			else cout << 0;
		}
		cout << endl;
	}else if(c==2){
		for(int i=1;i<=n;i++)cin >> oa[i];
		for(int i=1;i<=m;i++)cin >> ob[i];
		for(int i=1;i<=n;i++)a[i]=oa[i];
		for(int i=1;i<=m;i++)b[i]=ob[i];
		if(a[1]>b[1]&&a[2]>b[2]||a[1]<b[1]&&a[2]<b[2])cout << 1;
		else cout << 0;
		for(int i=1;i<=q;i++){
			for(int i=1;i<=n;i++)a[i]=oa[i];
			for(int i=1;i<=m;i++)b[i]=ob[i];
			cin >> kx >> ky;
			for(int j=1;j<=kx;j++){
				cin >> px >> vx;
				a[px]=vx;
			}
			for(int j=1;j<=ky;j++){
				cin >> py >> vy;
				b[py]=vy;
			}
			if(a[1]>b[1]&&a[2]>b[2]||a[1]<b[1]&&a[2]<b[2])cout << 1;
			else cout << 0;
		}
		cout << endl;
	}else if(c==3||c==4||c==5){
		for(int i=1;i<=n;i++)cin >> oa[i];
		for(int i=1;i<=m;i++)cin >> ob[i];
		for(int i=1;i<=n;i++)a[i]=oa[i];
		for(int i=1;i<=m;i++)b[i]=ob[i];
		if(check1())cout << 1;
		else cout << 0;
		for(int i=1;i<=q;i++){
			for(int i=1;i<=n;i++)a[i]=oa[i];
			for(int i=1;i<=m;i++)b[i]=ob[i];
			cin >> kx >> ky;
			for(int j=1;j<=kx;j++){
				cin >> px >> vx;
				a[px]=vx;
			}
			for(int j=1;j<=ky;j++){
				cin >> py >> vy;
				b[py]=vy;
			}
			if(check1())cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
	return 0;
}