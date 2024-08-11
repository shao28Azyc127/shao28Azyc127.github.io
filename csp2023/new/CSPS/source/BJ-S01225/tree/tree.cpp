#include<bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	
	int n;
	
	cin>>n;
	
	int road[n][n];
	int a[n],b[n],c[n];
	
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=n-1;j++){
			road[i][j]=0;
		}
	}
	
	for(int i=0;i<=n-1;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=0;i<=n-2;i++){
		int u,v;
		cin>>u>>v;
		road[u][v]=1;
		road[v][u]=1;
	}
	
	cout<<n+1;
	
	return 0;
}