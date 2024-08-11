#include<bits/stdc++.h>
using namespace std;
struct node{long long x,y,v;}b[100005];
long long n,a[100005],c,t,m,k,d,g[100005],ans;
set<pair<long long,long long>>s;
mt19937 rd((unsigned long long)new char);
void dfs(int x,int y){
	if(y>k)return;
	if(x>n){
		long long sum=0;
		for(int i=1;i<=m;++i){
			int flag=1;
			for(int j=b[i].x-b[i].y+1;j<=b[i].x;++j)
				if(!g[j]){flag=0;break;}
			if(flag)sum+=b[i].v;
		}
		for(int i=1;i<=n;++i)cerr<<g[i],sum-=g[i]*d;
		ans=max(ans,sum);
		return;
	}
	g[x]=1;dfs(x+1,y+1);
	g[x]=0;dfs(x+1,0);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	if(c>=17&&c<=18){
		while(t--){
			long long ans=0;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;++i)cin>>b[i].x>>b[i].y>>b[i].v;
			sort(b+1,b+m+1,[&](node x,node y){return x.v-(x.y*d)>y.v-(y.y*d);});
			for(int i=1;i<=m;++i){
				if(b[i].v-(b[i].y*d)<=0){break;}
				if(b[i].y-b[i].x+1>k)continue;
				ans+=b[i].v-(b[i].y*d);
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--){
		cin>>n>>m>>k>>d;s.clear();ans=0;
		for(int i=1;i<=m;++i)cin>>b[i].x>>b[i].y>>b[i].v;
		dfs(1,0);cout<<ans<<'\n';

	}
	return 0;
}//ÓñÖ¸