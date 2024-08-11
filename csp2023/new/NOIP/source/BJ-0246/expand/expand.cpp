#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
int x[500010],y[500010],xx[500010],yy[500010];
int c,n,m,q;
bool vis[5010][5010];
int cc=0;
bool dfs(int l,int r){
	
	if(vis[l][r])return 0;
	vis[l][r]=1;
	//cout << l << " " << r << endl;
	if(l==n+1){
		fr(i,r,m)if(y[i]>=x[n])return 0;
		return 1;
	}
	if(r==m+1){
		fr(i,l,n)if(x[i]<=y[m])return 0;
		return 1;
	}
	if(x[l]>y[r]){
		while(x[l]>y[r]&&l<=n&&r<=m)vis[l][r]=1,l++,r++;
		return dfs(l,r);
	}
	fr(i,1,l-1){
		if(vis[i+1][r+1])continue;
		if(x[i]>y[r]&&dfs(i+1,r+1))return 1;
	}fr(i,1,r-1){
		if(vis[l+1][i+1])continue;
		if(x[l]>y[i]&&dfs(l+1,i+1))return 1;
	}
	return 0;
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> q;
	fr(i,1,n) cin >> xx[i];
	fr(i,1,m)cin >> yy[i];
	fr(i,1,n)x[i]=xx[i];
	fr(i,1,m)y[i]=yy[i];
	if(n<=1&&m<=1)
		cout <<( x[1]!=y[1]);
	else {
		if(x[1]<y[1])swap(x,y);
		if(x[1]==y[1])cout << 0;
		else cout << dfs(1,1);
	}
	while(q--){
		memset(vis,0,sizeof vis);
		int k1,k2;
		cin >> k1 >> k2;
		fr(i,1,n)x[i]=xx[i];
		fr(i,1,m)y[i]=yy[i];
		while(k1--){
			int p,v;
			cin >> p >> v;
			x[p]=v;
		}
		while(k2--){
			int p,v;
			cin >> p >> v;
			y[p]=v;
		}
		 if(n<=1&&m<=1)
			cout <<( x[1]!=y[1]);
		 else{if(x[1]<y[1])swap(x,y);
		if(x[1]==y[1])cout << 0;
		else cout << dfs(1,1);}
	}
	return 0;
}
