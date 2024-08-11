#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;

int typ,__;
int n,m,ans=1e9;
int a[N],tmp[N];
struct Node {int op,x,y;} q[N];

int getId(char c) {
	if (c=='T') return 1;
	else if (c=='F') return 2;
	else if (c=='U') return 3;
	else if (c=='+') return 0;
	else return -1;
}

void dfs(int k) {
	if (k==n+1) {
		for (int i=1; i<=n; i++) tmp[i]=a[i];
		for (int i=1; i<=m; i++) {
			if (q[i].op==1) tmp[q[i].x]=1;
			else if (q[i].op==2) tmp[q[i].x]=2;
			else if (q[i].op==3) tmp[q[i].x]=0;
			else if (q[i].op==0) tmp[q[i].x]=tmp[q[i].y];
			else tmp[q[i].x]=(3-tmp[q[i].y])%3;
		}
		for (int i=1; i<=n; i++)
			if (tmp[i]!=a[i]) return;
		//for (int i=1; i<=n; i++) cout<<a[i]<<" \n"[i==n];
		int cnt=0;
		for (int i=1; i<=n; i++) cnt+=(!a[i]);
		ans=min(ans,cnt);
		return;
	}
	for (int i=0; i<3; i++) {
		a[k]=i; dfs(k+1);
	}
}

void solve() {
	memset(a,-1,sizeof a);
	for (int i=1; i<=m; i++)
		if (q[i].op<1) {
			if (a[q[i].y]<0) a[q[i].x]=-1;
			else if (q[i].op==0) a[q[i].x]=a[q[i].y];
			else a[q[i].x]=(3-a[q[i].y])%3;
		} else a[q[i].x]=q[i].op%3;
	if (typ<=4) {
		int cnt=0;
		for (int i=1; i<=n; i++) cnt+=(!a[i]);
		cout<<cnt<<'\n'; return;
	}
	for (int kk=1; kk<=n; kk++)
		for (int i=1; i<=m; i++)
			if (q[i].op<1) {
				if (a[q[i].y]<0) a[q[i].x]=-1;
				else if (q[i].op==0) a[q[i].x]=a[q[i].y];
				else a[q[i].x]=(3-a[q[i].y])%3;
			} else a[q[i].x]=q[i].op%3;
	if (typ<=6) {
		int cnt=0;
		for (int i=1; i<=n; i++) cnt+=(!a[i]);
		cout<<cnt<<'\n'; return;
	}
}

int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>typ>>__;
	while (__--) {
		cin>>n>>m; ans=1e9;
		for (int i=1; i<=m; i++) {
			char s[3]; cin>>s;
			q[i].op=getId(s[0]);
			if (q[i].op<1) cin>>q[i].x>>q[i].y;
			else cin>>q[i].x;
		}
		if (typ<=2) {
			dfs(1);
			cout<<ans<<'\n';
		} else {
			solve();
		}
	}
	return 0;
}