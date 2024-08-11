#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int c,t,n,m,k,d;
long long ans=0;
struct Node{
	long long x,y,v;
}p[100005];
bool cmp(Node X,Node Y){
	if(X.y==Y.y) return X.x<Y.x;
	return X.y<Y.y;
}
void dfs(int i,int l,long long w){
	if(l>k) return;
	ans=max(ans,w);
	for(int j=i+1;j<=m;j++){
		if(p[j].x-p[j].y>p[i].x){
			dfs(j,p[j].y,w+p[j].v-p[j].y*d);
		}
		else if(p[j].x-p[j].y<=p[i].x&&p[j].v-(p[j].x-p[i].x)*d>0){
			dfs(j,p[j].x-p[i].x+l,w+p[j].v-(p[j].x-p[i].x)*d);
		}
	}

}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		//memset(dp,0,sizeof(dp));
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].v);
		}
		sort(p+1,p+m+1,cmp);
		dfs(0,0,0);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}