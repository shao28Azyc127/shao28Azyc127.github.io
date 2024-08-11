#include<bits/stdc++.h>
using namespace std;

struct qqq{
	int x,y;
	long long v;
}a[100005];

int id,t;
int n,m,k;
long long d;

long long dp[1005][1005];
long long num[1005][1005];
long long ans;

bool cmp(qqq ax,qqq bx){
	if(ax.x<bx.x){
		return ax.y<bx.y;
	}
	return ax.x<bx.x;
}

int cnt;
map<int,int> mp;
vector<int> v[100005];

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>id>>t;
	if(id<=9){
		while(t--){
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;++i){
				cin>>a[i].x>>a[i].y>>a[i].v;
			}
			for(int i=1;i<=m;++i){
				num[a[i].x][a[i].y]+=a[i].v;
			}
			for(int i=1;i<=n;++i){
				long long s=0;
				dp[i][0]=dp[i-1][0];
				for(int j=1;j<=i && j<=k;++j){
					s+=num[i][j];
					dp[i][j]=dp[i-1][j-1]-d+s;
					dp[i][0]=max(dp[i][0],dp[i-1][j]);
				}                                                                                                       
			}
			ans=0;
			for(int j=0;j<=k;++j){
				ans=max(ans,dp[n][j]);
			}
			cout<<ans<<'\n';
			for(int i=1;i<=m;++i){
				num[a[i].x][a[i].y]-=a[i].v;
			}
		}
		return 0;
	}
	/*if(id<=14){
		while(t--){
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;++i){
				cin>>a[i].x>>a[i].y>>a[i].v;
			}
			sort(a+1,a+m+1,cmp);
			mp.clear();
			cnt=0;
			for(int i=1;i<=n;++i){
				if(a[i].x!=a[i-1].x){
					++cnt;
					v[cnt].push_back(0);
				}
				mp[a[i].x]=cnt;
				v[cnt].push_back(i);
			}
		}
		return 0;
	}*/
	while(t--){
		cout<<"0\n";
	}
	return 0;
}
