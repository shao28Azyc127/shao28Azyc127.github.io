#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+5;

int c,n,m,q;
int a[N],b[N],ta[N],tb[N];
bool f[N][N];

int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>q;
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int j=1; j<=m; j++) cin>>b[j];
	memset(f,false,sizeof f); f[0][0]=true;
	bool flag=false;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (a[i]>b[j])
				f[i][j]=f[i-1][j-1]|f[i-1][j]|f[i][j-1];
	flag|=f[n][m];
	swap(a,b); swap(n,m);
	memset(f,false,sizeof f); f[0][0]=true;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (a[i]>b[j])
				f[i][j]=f[i-1][j-1]|f[i-1][j]|f[i][j-1];
	flag|=f[n][m];
	cout<<flag;
	memcpy(ta,b,sizeof b); memcpy(tb,a,sizeof a);
	while (q--) {
		memset(f,false,sizeof f); f[0][0]=true;
		swap(n,m); swap(a,b);
		memcpy(a,ta,sizeof a); memcpy(b,tb,sizeof b);
		int kx,ky; cin>>kx>>ky;
		for (int i=1; i<=kx; i++) {
			int p,v; cin>>p>>v;
			a[p]=v;
		}
		for (int i=1; i<=ky; i++) {
			int p,v; cin>>p>>v;
			b[p]=v;
		} flag=false;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				if (a[i]>b[j])
					f[i][j]=f[i-1][j-1]|f[i-1][j]|f[i][j-1];
		flag|=f[n][m];
		memset(f,false,sizeof f); f[0][0]=true;
		swap(a,b); swap(n,m);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				if (a[i]>b[j])
					f[i][j]=f[i-1][j-1]|f[i-1][j]|f[i][j-1];
		flag|=f[n][m];
		cout<<flag;
	} cout<<'\n';
	return 0;
}