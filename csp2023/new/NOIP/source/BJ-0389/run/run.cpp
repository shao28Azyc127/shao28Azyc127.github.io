#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,v;
}a[100005];
bool cmp(node a,node b){
	return a.x<b.x;
}
int t[1500006][20];
int dp[100005];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		int ans=-1;
		int n,m,k,d;
		cin>>n>>m>>k>>d;
		int res=0;
		for(int i=1;i<(1<<n);i++){
			t[i][n]=(t[i-1][n]+1)%2;
			res=0;
			if(t[i-1][n]+1>=2) res=1;
			for(int j=n-1;j>=1;j--){
				t[i][j]=(t[i-1][j]+res)%2;
				if(t[i-1][j]+res>=2) res=1;
				else res=0;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>a[i].x>>a[i].y>>a[i].v;
		}
		for(int i=0;i<(1<<n);i++){
			int kk=0,ress=0;
			for(int j=1;j<=n;j++){
				if(t[i][j]==0) kk=0;
				if(t[i][j]==1){
					ress-=d,kk++;
					if(kk>k) ress=-0x3f3f3f3f;
					for(int mm=1;mm<=m;mm++){
						if(a[mm].x==j&&kk>=a[mm].y) ress+=a[mm].v;
					}
				}
			}
			ans=max(ans,ress);
		}
		cout<<ans<<endl;
	}
}
