#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define fir first
#define sec second
using namespace std;
const int N=1e3+10;
int T,num,n,m,k,d,x[200005],y[200005],v[200005];
int f[N][N];
vector <pair<int,int>> c[N];
void B(){
	int res=0;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>v[i];
		if(y[i]<=k)res+=max(0ll,v[i]-y[i]*d);
	}
	cout<<res<<endl;
}
void solve(){
	cin>>n>>m>>k>>d;k=min(k,n);
	if(num>=17&&num<=18){
		B();return;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i+1;j++)f[i][j]=-1e18;
	for(int i=1;i<=n;i++)c[i].clear();
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>v[i];
		c[x[i]].push_back(mp(y[i],v[i]));
	}f[0][0]=0;
	for(int i=1;i<=n;i++)
		sort(c[i].begin(),c[i].end());
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,k);j++)
			f[i][j]=max(f[i][j],f[i-1][j-1]-d);
		int Max=-1e18;
		for(int j=0;j<=min(i-1,k);j++)
			Max=max(Max,f[i-1][j]);
		f[i][0]=max(f[i][0],Max);
		int pos=0,now=0;
		for(int j=1;j<=min(i,k);j++){
			while(pos<c[i].size()&&c[i][pos].fir<=j)
				now+=c[i][pos].sec,pos++;
			f[i][j]+=now;
		}
	}
	int res=-1e18;
	for(int i=0;i<=n;i++)res=max(res,f[n][i]);
	cout<<res<<endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
	cin>>num>>T;
	while(T--)solve();
    return 0;
}
