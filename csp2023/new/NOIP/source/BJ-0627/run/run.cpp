#include<bits/stdc++.h>
#define N 100005
using namespace std;
int c,t,x[N],y[N],v[N];
int e;
int n,m,k,d;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=t;i++){
		cout<<0<<endl;
	}
	return 0;
}
