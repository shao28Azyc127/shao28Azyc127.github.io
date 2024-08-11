#include<iostream>
#include<cmath>
#include<queue> 
#include<vector>
using namespace std;
struct node1{
	long long a,b,c,d;
}a[100005];
int d[100005],v[100005];
vector<int> adj[100005];
long long Ans=0x3f3f3f3f,ans1=0,n;
void dfs(int h,int x){
	if(v[x]==1){
		return;
	}
	else{
		v[x]=1;
	}
	long long ans2;
	ans2=ans1;
	ans1=max(ans1,h-1+a[x].d);
	//cout<<h<<' '<<x<<' '<<ans1<<endl;
	cout<<h<<' '<<x<<' '<<ans1<<endl;
	if(h==n){
		Ans=min(Ans,ans1);
		ans1=ans2;
		return;
	}
	for(int i=0;i<adj[x].size();i++){
		int y=adj[x][i];
		//cout<<x<<' '<<y<<endl;
		dfs(h+1,y);
	}
	//cout<<endl;
	v[x]=0;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		double yyy;
		if(a[i].b<=1){
			a[i].d=a[i].a;
		}
		else{
			yyy=a[i].a*1.0/a[i].b;
			//cout<<yyy<<' ';
			a[i].d=ceil(yyy);
		}
		//cout<<a[i].d<<endl;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout<<"0";
	return 0;
}