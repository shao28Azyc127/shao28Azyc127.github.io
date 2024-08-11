#include<bits/stdc++.h>
using namespace std;
const int NR=1e5+5;
int c,t;
int n,m;
int a[NR];
namespace sub34{
	void init(){
		memset(a,0,sizeof(a));
	}
	void solve(){
		init();
		cin>>n>>m;
		int ans=0;
		for(int i=1;i<=m;++i){
			char v;cin>>v;
			int x;cin>>x;
			if(v=='T')a[x]=1;
			if(v=='F')a[x]=2;
			if(v=='U')a[x]=-1;
		}
		for(int i=1;i<=n;++i)
			if(!~a[i])ans++;
		cout<<ans<<endl;
	}
}
namespace sub12{
	struct Q{char op;int x,y;}qst[NR];
	int b[NR],ans=1e9;
	void init(){
		ans=1e9;
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
	}
	void dfs(int x,int num){
		if(num>=ans)return;
		if(x==n+1){
			for(int i=1;i<=n;++i)b[i]=a[i];
			for(int i=1;i<=m;++i){
				int v=qst[i].op;
				int x=qst[i].x,y=qst[i].y;
				if(v=='U')b[x]=3;
				else if(v=='F')b[x]=2;
				else if(v=='T')b[x]=1;
				else if(v=='+')b[x]=b[y];
				else{
					if(b[y]==1)b[x]=2;
					else if(b[y]==2)b[x]=1;
					else if(b[y]==3)b[x]=3;
				}
			}
			bool check=true;
			for(int i=1;i<=n;++i)
				if(a[i]!=b[i]){check=false;break;}
			// if(check){
			// 	for(int i=1;i<=n;++i)
			// 		cout<<a[i]<<" ";
			// 	cout<<endl;
			// }
			if(check)ans=min(ans,num);
			return;
		}
		a[x]=1;
		dfs(x+1,num);
		a[x]=2;
		dfs(x+1,num);
		a[x]=3;
		dfs(x+1,num+1);
		a[x]=0;
	}
	void solve(){
		init();
		cin>>n>>m;
		for(int i=1;i<=m;++i){
			cin>>qst[i].op;
			if(qst[i].op=='U'||qst[i].op=='F'||qst[i].op=='T')
				cin>>qst[i].x;
			else cin>>qst[i].x>>qst[i].y;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
}
namespace sub56{
	struct Q{char op;int x,y;}qst[NR];
	void init(){
		memset(a,0,sizeof(a));
	}
	void solve(){
		init();
		cin>>n>>m;
		int ans=0,cnt=0;
		for(int i=1;i<=m;++i){
			cin>>qst[i].op;
			if(qst[i].op=='U')cin>>qst[i].x;
			else cin>>qst[i].x>>qst[i].y;
		}
		for(int i=1;i<=m;++i){
			cnt=0;
			for(int j=1;j<=m;++j){
				if(qst[j].op=='U')a[qst[j].x]=-1;
				else a[qst[j].x]=a[qst[j].y];
			}
			for(int j=1;j<=n;++j)
				if(!~a[j])cnt++;
			if(ans==cnt)break;
			ans=cnt;
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c==3||c==4)sub34::solve();
		else if(c==5||c==6)sub56::solve();
		else sub12::solve();
	}
	return 0;
}