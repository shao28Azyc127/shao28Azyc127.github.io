#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=1010,M=100010;
LL f[N][N];
int h[N],ne[M],w[M],v[M],idx;
inline void add(int a,int b,int c){
	ne[++idx]=h[a],w[idx]=b,v[idx]=c,h[a]=idx;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,m,k,d;
		idx=0;
		memset(h,0,sizeof h);
		memset(f,0,sizeof f);
		scanf("%d%d%d%d",&n,&m,&k,&d);
		while(m--){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<=min(i,k);j++){
				f[i][0]=max(f[i][0],f[i-1][j]);
				if(j>0)
					f[i][j]=f[i-1][j-1]-d;
				for(int t=h[i];t;t=ne[t])
					if(w[t]<=j)
						f[i][j]+=v[t];
			}
		LL ans=0;
		for(int i=0;i<=k;i++)
			ans=max(ans,f[n][i]);
		printf("%lld\n",ans);
	}
	return 0;
}