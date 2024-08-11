#include<bits/stdc++.h>
using namespace std;

int n,m,mx,u,g[20100][20100];

int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> m >> u;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		g[x][y]=z;
		mx=max(mx,z);
	}
	cout << (mx/u+1)*u;
	
	
	return 0;
}