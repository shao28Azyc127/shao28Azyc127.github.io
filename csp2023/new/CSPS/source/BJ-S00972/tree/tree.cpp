#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
bool mp[100010][100010],plted[100010];
long long a[100010],b[100010],c[100010];
bool lmax(long long x,long long y){
	return x>y?x:y;
}
long long dfs(int nday){
	bool fend=1;
	for(int i = 1;i <= n;i++){
		if(a[i]>0){fend=0;break;}
	}
	if(fend)return nday;
	for(int i = 1;i <= n;i++){
		if(plted[i]){
        	for(int j = 1;j <= n;i++){
				if(mp[i][j]&&(!plted[j])){
					plted[j]=1;
					for(int k = 1;k <= n;k++){
						if(plted[k]){
							a[k]-=lmax(b[k]+c[k]*nday,1l);
						}
					}
					dfs(nday+1);
					plted[j]=0;
					for(int k = 1;k <= n;k++){
						if(plted[k]){
							a[k]+=lmax(b[k]+c[k]*nday,1l);
						}
					}
				}
			}
		}
	}
	return nday;
}
signed main(){
	ios::sync_with_stdio(false);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int u,v;
    for(int i = 1;i < n;i++){
		cin>>u>>v;
		mp[u][v]=mp[v][u]=1;
	}
	plted[1]=1;
	a[1]-=lmax(b[1]+c[1],1);
	cout<<dfs(2);
    return 0;
}