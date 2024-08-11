#include<bits/stdc++.h>
using namespace std;

struct qqq{
	long long a,b,c;
	int id;
	long long t;
}p[100005];

int n;
int u,v;
vector<int> mp[100005];

bool f1=1,f2=1;

long long ans;

bool check(long long a,long long b,long long c,long long x,long long y){
	if(c>0){
		if((x+y)*(y-x+1)/2>=1e18){
			return 1;
		}
		return (((y-x+1)*b+(x+y)*(y-x+1)/2*c)>=a);
	}
	if(c==0){
		return (((y-x+1)*b)>=a);
	}
	long long l=x,r=y,mid;
	while(l<=r){
		mid=(l+r)/2;
		if((mid-x+1)*b<=(__int128)(x+mid)*(mid-x+1)/2*(-c)){
			r=mid-1;
		}
		else{
			if((mid+1-x+1)*b<=(__int128)(x+mid+1)*(mid+1-x+1)/2*(-c)){
				break;
			}
			l=mid+1;
		}
	}
	if((x-x+1)*b<=(__int128)(x+x)*(x-x+1)/2*(-c)){
		mid=x-1;
	}
	return (((mid-x+1)*b+(x+mid)*(mid-x+1)/2*c)+(y-mid)>=a);
}

long long findx(long long a,long long b,long long c,long long x){
	long long l=x,r=1e9,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(a,b,c,x,mid)==1){
			if(check(a,b,c,x,mid-1)==0){
				break;
			}
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return mid;
}

bool flag[25];
long long dp[1048576];

long long dfs(int x,int pp,int l){
	if(l==n){
		dp[pp]=0;
		return 0;
	}
	if(dp[pp]!=1e18){
		return dp[pp];
	}
	flag[x]=1;
	for(int i=1;i<=n;++i){
		if(flag[i]==0){
			continue;
		}
		for(int j=0;j<(int)(mp[i].size());++j){
			if(flag[mp[i][j]]==1){
				continue;
			}
			dp[pp]=min(max(dfs(mp[i][j],pp|(1<<(mp[i][j]-1)),l+1),findx(p[mp[i][j]].a,p[mp[i][j]].b,p[mp[i][j]].c,l+1)),dp[pp]);
		}
	}
	//cout<<l<<' '<<pp<<' '<<dp[pp]<<'\n';
	flag[x]=0;
	return dp[pp];
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
		if(p[i].c!=0){
			f1=0;
		}
	}
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
		if(u!=i || v!=i+1){
			f2=0;
		}
	}
	if(f2==1){
		ans=1e18;
		for(int i=1;i<=n;++i){
			ans=min(ans,findx(p[i].a,p[i].b,p[i].c,i));
		}
		printf("%lld",ans);
		return 0;
	}
	if(n<=20){
		for(int i=0;i<1048576;++i){
			dp[i]=1e18;
		}
		ans=dfs(1,1,1);
		printf("%lld",ans);
	}
	return 0;
}
/*
4
12 1 -1
10 3 0
7 10 -2
2 4 -1
1 2
2 3
3 4
*/
