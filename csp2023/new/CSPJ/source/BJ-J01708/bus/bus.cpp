// why rdfz has just 2 cpu too
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=0;
int n,m,k;
struct edge{int x,y,z,cnt;};
vector<edge>e;
vector<int>v[10005],f[10005];
namespace case0{
	bool vis[15][2000005];
	int mn[105];
	void dfs(int now,int t){
		if(vis[now][t])return;
		if(now==n){
			if(t>mn[t%k])return;
			mn[t%k]=t;
		}
		vis[now][t]=1;
		for(auto _:v[now]){edge&i=e[_];
			if(i.z<=t)dfs(i.y,t+1);
		}
	}
	void run(){
		memset(mn,0x3f,sizeof(mn));
		for(int i=0;i<=mn[0];i+=k)dfs(1,i);
		cout<<mn[0]<<endl;
	}
}
namespace case1{
	int dp[10005][105];
	void dfs(int now){
		for(auto _:v[now]){edge &i=e[_];
			if(!i.cnt)continue;
			i.cnt--;
			bool nw=0;
			for(int j=0;j<k;j++){
				if(dp[now][(j+k-1)%k]+1<dp[i.y][j]){
					dp[i.y][j]=dp[now][(j+k-1)%k]+1;
					nw=1;
				}
			}
			if(!nw)continue;
			dfs(i.y);
		}
	}
	void run(){
		memset(dp,0x3f,sizeof(dp));
		dp[1][0]=0;
		dfs(1);
		cout<<(dp[n][0]==0x3f3f3f3f?-1:dp[n][0])<<endl;
	}
}
namespace case2{
	//k=1
	bool vis[10005];
	int dis1[10005],dis2[10005],ans=0;
	queue<int>q;
	void bfs1(){
		q.push(1);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(auto _:v[now]){edge i=e[_];
				if(vis[i.y])continue;
				dis1[i.y]=dis1[now]+1;
				vis[i.y]=1;
			}
		}
	}
	void bfs2(){
		q.push(n);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(auto _:f[now]){edge i=e[_];
				if(vis[i.y])continue;
				dis2[i.y]=dis2[now]+1;
				vis[i.y]=1;
				ans=min(ans,max(dis1[i.y],i.z)+dis2[i.y]);
			}
		}
	}
	void run(){
		bfs1();
		memset(vis,0,sizeof(vis));
		bfs2();
		cout<<ans<<endl;
	}
}
namespace case3{
	//ui<vi
	int dp[10005][105];
	void run(){
		memset(dp,0x3f,sizeof(dp));
		dp[1][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<k;j++){
				if(dp[i][j]==0x3f3f3f3f)continue;
			}
		}
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	int mx=0;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;mx=max(mx,z);
		e.push_back({x,y,z,k*2});
		v[x].push_back(e.size()-1);
		e.push_back({y,x,z,k*2});
		f[y].push_back(e.size()-1);
	}
	if(n<=10)case0::run();
	else if(!mx)case1::run();
	else if(k==1)case2::run();
	;
	return 0;
}
/*
a=0:
	1->n k*___
	tarjan and ???
	you can go many loops and get time
	loops<=n^2/4 + n
	so big :(
	dp?
	t1 t2 t3 are not dp
	but how dp
	can not tarjan
	2h left
	dp i j means 
	now at point i
	time%k==j
	the min time
	and brute force dp
	m*k?
	fk wrong.
	dp goes on loop, 6
	wait, maybe right
	ok now i think it is right
	i just think it!
	next one
a>0:
	1->n k*___
	1h left
	/ll
	i don't know what my code means
	but i think it is right
	t4 2hd4me
	wu wu wu
	how????
	how???????
	how n<=10 m<=15 (done)
	how k=1 (done but very very very wrong)
	how ui<vi
	last 45min
	last 30min
	now 50~65 pts
wu wu wu wu wu wu wu wu
AK FAILED!!!!!!!!!!!!!!11!!!!!!!!!!!!!!!!!!!
AK FAILED!!!!!!!!!!!!!!11!!!!!!!!!!!!!!!!!!!
AK FAILED!!!!!!!!!!!!!!11!!!!!!!!!!!!!!!!!!!
luogu: ACaCaca_(uid=320423)
if you found me plz tell everyone this joker.
//freopen
#define int long long
freoepn froepen feropen
#include
signed main(){
I AM A JOKER.
*/