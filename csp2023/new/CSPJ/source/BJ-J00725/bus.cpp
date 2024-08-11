#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
int n,m,k;
struct node{
	int v,nt;
} e[N<<1];
int h[N],tot;
void add(int u,int v){
	e[++tot].v=v;
	e[tot].nt=h[u];
	h[u]=tot;
}
bool flag[N];
void dfs(int u,int tmp){
	if(tmp==k){
		printf("%d\n",k);
		return;
	}
	for(int i=h[u];i;i=e[i].nt){
		int v=e[i].v;
		if(flag[v]){
			printf("%d\n",k);
			return;
		}
		flag[v]=true;
		dfs(v,tmp++);
		flag[v]=false;
	}
}
int main(){
	int fl=0;
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v);
		if(w!=0) fl=1;
	}
	if(!fl){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				 flag[j]=false;
			}
			flag[i]=true;
			dfs(i,0);
		}
	}
	printf("-1\n");
    return 0;
}