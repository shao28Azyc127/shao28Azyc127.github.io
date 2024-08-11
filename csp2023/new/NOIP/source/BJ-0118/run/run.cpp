#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=100010;
ll n,m,k,d;
struct node{
    ll x,y,v;
    bool operator<(const node b)const{
        return x<b.x||(x==b.x&&y<b.y);
    }
}a[N];
ll dp[1010][1010];
void solve1(){
    cin>>n>>m>>k>>d;
    for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].v;
    sort(a+1,a+1+m);
    for(int i=0;i<=n;i++){
        for(int j=1;j<=k;j++)dp[i][j]=-10000000000000000;
        dp[i][0]=0;
    }
    a[m+1].x=n+1;
    int ct=0;
    for(int i=1;i<=n;i++){
        ll re=0;
        for(int j=1;j<=k;j++){
            while(a[ct+1].x==i&&a[ct+1].y==j){
                ct++;re+=a[ct].v;
            }
            dp[i][j]=dp[i-1][j-1]-d+re;
            dp[i][0]=max(dp[i][0],dp[i-1][j]);
        }
        dp[i][0]=max(dp[i][0],dp[i-1][0]);
        while(a[ct+1].x==i)ct++;
    }
    //cout<<ct<<'\n';
    //for(int i=1;i<=n;i++){
	//	for(int j=0;j<=k;j++){
	//		cout<<dp[i][j]<<' ';
	//	}cout<<'\n';
	//}
    ll maxans=-10000000000000000;
    for(int i=0;i<=k;i++)maxans=max(maxans,dp[n][i]);
    cout<<maxans<<'\n';
}
void solve2(){
	cin>>n>>m>>k>>d;
    for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].v;
    ll ans=0;
    for(int i=1;i<=m;i++){
		if(a[i].v>a[i].y*d&&a[i].y<=k)ans+=a[i].v-a[i].y*d;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
    int c,T;cin>>c>>T;
    if(c<=9){
        while(T--)solve1();
        return 0;
    }
    if(c==17||c==18){
		while(T--)solve2();
		return 0;
	}
	while(T--)solve2();
    return 0;
}
