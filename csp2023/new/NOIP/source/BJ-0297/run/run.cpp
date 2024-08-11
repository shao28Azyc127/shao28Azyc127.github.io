#include<bits/stdc++.h>
using namespace std;

int c,T,n,m,k,d;
const int M=1e5;

const int N=1e3;
long long f[N+5][N+5];
long long maxi[N+5];

struct node{
	long long x,y,v;
}aim[M+5];


int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld",&aim[i].x,&aim[i].y,&aim[i].v);
		}
		if(c==17 || c==18){
			long long ans=0;
			for(int i=1;i<=m;i++){
				if(aim[i].y<=k && aim[i].y*d<aim[i].v){
					ans+=aim[i].v-aim[i].y*d;
				}
			}
			cout<<ans<<endl;
		}
		else{
			memset(f,0,sizeof(f));
			memset(maxi,0,sizeof(maxi));
			long long ans=0;
			for(int i=1;i<=m;i++){
				for(int j=aim[i].y;j<=k;j++){
					f[aim[i].x][j]=aim[i].v;
				}
			}
			for(int i=1;i<=n;i++){
				f[i][0]=maxi[i-1];
				maxi[i]=f[i][0];
				for(int j=1;j<=k;j++){
					f[i][j]+=f[i-1][j-1]-d;
					maxi[i]=max(maxi[i],f[i][j]);
				}
				ans=max(ans,maxi[i]);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
