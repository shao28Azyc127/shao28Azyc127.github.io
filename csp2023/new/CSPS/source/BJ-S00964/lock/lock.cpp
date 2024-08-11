#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define FileIO(f) freopen(f".in","r",stdin),freopen(f".out","w",stdout)
int n,t[10][10],t2[10][10],a[10],ans=0;
bool check(){
	int i,j,cnt,fl;
	for(i=1;i<=n;i++)for(j=1;j<=5;j++)t2[i][j]=(t[i][j]-a[j]+10)%10;
	for(i=1;i<=n;i++){
		cnt=fl=0;
		for(j=1;j<=5;j++)if(t2[i][j])cnt++;
		if(!cnt||cnt>=3)return 0;
		if(cnt==2){
			for(j=1;j<=4;j++)if(t2[i][j]){
				if(t2[i][j+1]^t2[i][j])return 0;
				fl=1;break;
			}
			if(!fl)return 0;
		}
	}
	return 1;
}
void dfs(int x){
	if(x>5){ans+=check();return;}
	a[x]=0;dfs(x+1);
	a[x]=1;dfs(x+1);
	a[x]=2;dfs(x+1);
	a[x]=3;dfs(x+1);
	a[x]=4;dfs(x+1);
	a[x]=5;dfs(x+1);
	a[x]=6;dfs(x+1);
	a[x]=7;dfs(x+1);
	a[x]=8;dfs(x+1);
	a[x]=9;dfs(x+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	FileIO("lock");
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)for(j=1;j<=5;j++)cin>>t[i][j];
	dfs(1);
	cout<<ans;
	return 0;
}