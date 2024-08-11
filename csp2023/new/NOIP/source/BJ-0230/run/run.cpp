#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,M=1e5+5;
struct node{
	int l,r,v;
}a[M];
int t[N];
int n,m,k,d;
int cal(int x){
	int i,j;
	for(i=x-1;i>=1;--i){
		if(t[i]==0)break;
	}
	++i;
	for(j=x+1;j<=n;++j){
		if(t[j]==0)break;
	}
	--j;
	//cout<<"sec:"<<i<<' '<<j<<'\n';
	if(j-i+1>k)return -1e7;
	int res=0;
	for(int p=1;p<=m;++p){
		if(a[p].l>=i&&a[p].r<=j)res+=a[p].v;
	}
	return res;
}
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	srand(19260817);
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;++i){
			int x,y,v;cin>>x>>y>>v;
			if(y>k){--i,--m;continue;}
			a[i]={x-y+1,x,v};
		}
		int res=0,ans=0;
		for(int i=1;i<=n;++i)t[i]=0;
		int times=1000;
		int lst=-1;
		while(times--){
			int x=rand()%n+1;
			if(x==lst)x=rand()%n+1;
			lst=x;
			int res1=ans,p=cal(x);
			if(p==-1e7)continue;
			if(t[x]==1)res1+=d-p;
			else res1-=d-p;
			t[x]^=1;
			res=max(res,res1);
			ans=res1;
		}
		cout<<res<<'\n';
	}
	return 0;
}
// I love noip
/*
PAY ATTENTION:
1. freopen
2. read every word carefully
3. solve the problem step by step
4. testing strategy
5. __int128 no sqrt
6. N and M
7. int, long long and __int128

Trust yourself, 1= is too easy for you.
*/
