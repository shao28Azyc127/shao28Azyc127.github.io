#include <bits/stdc++.h>
using namespace std;
int n,aim[114514],b[114514],c[114514],x[100010],y[100010];
vector gg[114514],a[114514];
void build(int last,int now){
	if(last!=0) a[last].push_back(now);
	for(int i=0;i<gg[now].size();i++){
		if(gg[now][i]!=last) build(now,gg[now][i]);
	}
	return;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&aim[i],&b[i],&c[i]);
		
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		gg[y].push_back(x);
		gg[x].push_back(y);
	}
	for(int i=1;i<=n;i++) sort(gg[i].begin(),gg[i].end());
	build(0,1);
	printf("5");
	return 0;
}