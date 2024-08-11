#include<bits/stdc++.h>
using namespace std;
int c,t;
namespace sub1{
	int n,m,a[105],tot,b[105],ans;
	struct query{
		int op,x,y;
	}q[105];
	int trans(int x){
		if(x==1)return 2;
		if(x==2)return 1;
		return 3;
	}
	void dfs(int x){
		if(x>n){
			for(int i=1;i<=n;++i)a[i]=b[i];
			for(int i=1;i<=tot;++i){
				if(q[i].op==1)a[q[i].x]=trans(a[q[i].y]);
				if(q[i].op==2)a[q[i].x]=a[q[i].y];
				if(q[i].op>=3)a[q[i].x]=q[i].op-2;
			}
			for(int i=1;i<=n;++i)
				if(a[i]!=b[i])return;
			int sum=0;
			for(int i=1;i<=n;++i)sum+=(b[i]==3);
			ans=min(ans,sum);
			return;
		}
		b[x]=1;dfs(x+1);b[x]=2;dfs(x+1);b[x]=3;dfs(x+1);
	}
	void solve(){
		cin>>n>>m;tot=0;
		memset(b,0,sizeof b);
		memset(a,0,sizeof a);ans=1e9;
		for(int i=1;i<=m;++i){
			char op;cin>>op;
			if(op=='-'){
				q[++tot].op=1;
				cin>>q[tot].x>>q[tot].y;
			}
			else if(op=='+'){
				q[++tot].op=2;
				cin>>q[tot].x>>q[tot].y;
			}
			else{
				int x;cin>>x;q[++tot].x=x;
				if(op=='T')q[tot].op=3;
				else if(op=='F')q[tot].op=4;
				else q[tot].op=5;
			}
		}
		dfs(1);
		cout<<ans<<'\n';
	}
}
namespace sub2{
	int n,m,a[100005],ans;
	int trans(int x){
		if(x==1)return 2;
		if(x==2)return 1;
		return 3;
	}
	void solve(){
		cin>>n>>m;
		memset(a,0,sizeof a);ans=0;
		for(int i=1;i<=m;++i){
			char op;int x;cin>>op>>x;
			if(op=='T')a[x]=1;
			if(op=='F')a[x]=2;
			if(op=='U')a[x]=3;
		}
		for(int i=1;i<=n;++i)
			if(a[i]==3)++ans;
		cout<<ans<<'\n';
	}
}
namespace sub3{
	int n,m,a[100005],fa[100005],ans;
	int find(int x){return fa[x]==x?x:find(fa[x]);}
	int trans(int x){
		if(x==1)return 2;
		if(x==2)return 1;
		return 3;
	}
	void solve(){
		cin>>n>>m;
		for(int i=1;i<=n;++i)fa[i]=i;
		memset(a,0,sizeof a);ans=0;
		for(int i=1;i<=m;++i){
			char op;int x,y;cin>>op>>x;
			if(op=='U'){a[x]=3;fa[x]=x;}
			if(op=='+'){
				cin>>y;
				a[x]=a[y];
				if(!a[x])fa[x]=find(y);
				else fa[x]=x;
			}
		}
		for(int i=1;i<=n;++i)
			if(!a[i])a[i]=a[find(i)];
		for(int i=1;i<=n;++i)
			if(a[i]==3)++ans;
		cout<<ans<<'\n';
	}
}
namespace sub4{}
namespace sub5{}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	if(c<=2){
		while(t--)sub1::solve();
	}
	if(c>=3&&c<=4){
		while(t--)sub2::solve();
	}
	if(c>=5&&c<=6){
		while(t--)sub3::solve();
	}
	// if(c>=7&&c<=8){
	// 	while(t--)sub4::solve();
	// }
	// if(c>=9&&c<=10){
	// 	while(t--)sub5::solve();
	// }
	return 0;
}//ฟฦสน