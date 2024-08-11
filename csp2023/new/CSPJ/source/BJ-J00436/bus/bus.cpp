#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,a;
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++) cin>>u>>v>>a;
	cout>>(u+a)/2;
	fclose(stdin);
	fclose(stdout);
}