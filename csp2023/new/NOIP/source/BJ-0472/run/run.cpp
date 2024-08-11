#include<bits/stdc++.h>
using namespace std;
const int NR=1e5+5;
const int MR=1e3+5;
#define int long long
int c,t;
int n,m,k,d;
struct node{
	int x,y,v;
}p[NR];
int ans;
namespace sub12{
	void dfs(int day,int num,int udk){
		if(day==n+1){
			ans=max(ans,num);
			return;
		}
		if(udk+1<=k){
			int nnum=num;
			for(int i=1;i<=m;++i)
				if(p[i].x==day&&udk+1>=p[i].y)nnum+=p[i].v;
			dfs(day+1,nnum-d,udk+1);
		}
		dfs(day+1,num,0);
	}
	void init(){
		ans=0;
	}
	void solve(){
		init();
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;++i)
			cin>>p[i].x>>p[i].y>>p[i].v;
		dfs(1,0,0);
		cout<<ans<<endl;
	}
}
namespace sub{
	int f[MR][MR];
	void init(){
		ans=0;
		memset(f,-0x3f3f3f3f,sizeof(f));
	}
	bool cmp(node x,node y){
		return x.x<y.x;
	}
	void solve(){
		init();
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;++i)
			cin>>p[i].x>>p[i].y>>p[i].v;
		sort(p+1,p+m+1,cmp);
		int t=1;
		for(int i=0;i<=n;++i)f[i][0]=0;
		for(int i=1;i<=n;++i){
			while(p[t].x<i)++t;
			for(int j=0;j<=min(k,i-1);++j)
				f[i][0]=max(f[i][0],f[i-1][j]);
			for(int j=1;j<=min(k,i);++j){
				int num=0;
				for(int l=t;l<=m;++l){
					if(p[l].x>i)break;
					if(p[l].x==i&&p[l].y<=j)num+=p[l].v;
				}
				f[i][j]=max(f[i][j],f[i-1][j-1])-d+num;
			}
		}
		for(int i=0;i<=min(n,k);++i)
			ans=max(ans,f[n][i]);
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c==1||c==2)sub12::solve();
		else sub::solve();
	}
	return 0;
}