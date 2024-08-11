#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>void read(T &x){
	int f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=2020;
int CASE,T;
int n,m,k,d,s1,s2,s3,s4,f[N][N];
vector<int>g[2][N];
signed main(){
	freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
	read(CASE),read(T);
	while(T){
		T--;
		read(n),read(m),read(k),read(d);
		for(int i=1;i<=n;i++) g[0][i].clear(),g[1][i].clear();
		for(int i=1;i<=m;i++){
			read(s1),read(s2),read(s3);
			g[0][s1].push_back(s2);
			g[1][s1].push_back(s3);
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++) f[i][j]=-4e18;
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=min(i,k);j++) f[i][j]=max(f[i][j],f[i-1][j-1]-d);
			for(int j=0;j<=min(i,k);j++) f[i][0]=max(f[i][0],f[i-1][j]);
			for(int j=0;j<g[0][i].size();j++){
				for(int z=g[0][i][j];z<=min(i,k);z++)
					f[i][z]+=g[1][i][j];
			}
		}
		s1=-4e18;
		for(int i=0;i<=k;i++) s1=max(s1,f[n][i]);
		cout<<s1<<"\n";
	}
	return 0;
}
