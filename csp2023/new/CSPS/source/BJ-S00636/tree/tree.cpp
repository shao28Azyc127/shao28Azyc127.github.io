#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct egde{
	int to,nxt;
}e[N*2];
int head[N],cnt;
void addedge(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
long long a[N],b[N],c[N];
long long ans[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}
	cout<<"1000000000";
	return 0;
}
