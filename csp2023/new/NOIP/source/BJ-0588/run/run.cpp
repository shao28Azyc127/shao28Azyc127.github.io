#include<bits/stdc++.h>
#define N 100050
using namespace std;
long long f[N][N];
long long x[N],y[N],v[N];
long long c,t,n,m,k,d,ans;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				f[i][j]=0;
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			cin>>x[i]>>y[i]>>v[i];
		cout<<0<<endl;
		}
	}
	return 0;
}