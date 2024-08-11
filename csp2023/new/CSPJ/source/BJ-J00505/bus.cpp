#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,a;
} c[100005];
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k,maxn=-1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {cin>>c[i].u>>c[i].v>>c[i].a;
		maxn=max(maxn,c[i].a);
		}
	if(maxn==0){
		cout<<k;
	}else{
		cout<<-1;
	}
	return 0;
}

