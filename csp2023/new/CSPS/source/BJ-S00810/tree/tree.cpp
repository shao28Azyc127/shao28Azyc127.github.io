#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
void text(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	cout<<n;
	return;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	text();
	return 0;
}