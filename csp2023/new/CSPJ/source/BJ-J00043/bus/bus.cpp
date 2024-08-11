#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v[20001],a[20001],nxt[20001],h[10001],ans[10001],head,tail,q[40000];
bool x[10001],y[10001];
bool c(int i,int j){
	return ans[i]<ans[j];
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v[i],&a[i]);
		nxt[i]=h[u];
		h[u]=1;
	}
	if(k!=1){
		printf("-1");
	}
	else{
		for(int i=2;i<=n;i++)
			ans[i]=-1;
		for(int i=1;i!=n;){
			for(int j=h[i];j!=0;j=nxt[j]){
				if(x[v[j]]==0&&ans[i]>=a[j]&&ans[v[j]]==-1||ans[v[j]]>ans[i]+1){
					if(y[v[j]]==0){
						q[tail++]=v[j];
						y[v[j]]=1;
					}
					ans[v[j]]=ans[i]+1;
				}
			}
			if(head==tail){
				break;
			}
			sort(q+head,q+tail,c);
			i=q[head];
			x[i]=1;
			head++;
		}
		printf("%d",ans[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}