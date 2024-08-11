#include<bits/stdc++.h>
using namespace std;
int n,d,v[100010],pre[100010],a[100010],minx=0x3f3f3f3f,zong[100010],f[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
		pre[i]=pre[i-1]+v[i];
		if(pre[i]%d==0)
			zong[i]=pre[i]/d;
		else
			zong[i]=pre[i]/d+1;
		minx=min(minx,v[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(minx==v[1]){
		cout<<zong[n-1]*a[1];
		return 0;
	}
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=zong[i];j<=zong[n-1];j++){
			for(int k=zong[i-1];k<=j;k++){
				f[i][j]=min(f[i][j],f[i-1][k]+(j-k)*a[i]);
			}
		}
	}
	cout<<f[n][zong[n-1]];
	return 0;
}
