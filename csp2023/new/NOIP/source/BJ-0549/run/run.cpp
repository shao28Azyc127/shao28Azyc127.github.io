#include<bits/stdc++.h>
using namespace std;
int c,t,k,y,n,m,d;
long long f[10005][10005];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) f[i][j]=0;
		for(int i=1;i<=m;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			f[x][y]=z;
		}
		for(int i=1;i<=n;i++){
			long long maxx=-1000000000000000005;
			for(int j=1;j<i;j++){
				for(int kk=1;kk<=j&&kk<=k;kk++){
					f[i][0]=max(f[i][0],f[j][kk]);
				}
			}
			for(int j=1;j<i-1;j++){
				for(int kk=1;kk<=j&&kk<=k;kk++)
					maxx=max(maxx,f[j][kk]+f[i][1]-d);
			}
			f[i][1]=maxx;
			for(int j=2;j<=k&&i-j+1>0;j++){
				f[i][j]+=f[i-1][j-1]-d;
			}
		}
		long long ans=-1000000000000000005;
		for(int i=1;i<=k;i++) ans=max(ans,f[n][0]);
		cout<<ans<<endl;
	}
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3
*/
