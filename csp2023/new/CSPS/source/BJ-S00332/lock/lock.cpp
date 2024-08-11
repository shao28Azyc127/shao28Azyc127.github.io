#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define REPG(i,h,x) for(int i=h[x];~i;i=edge[i].next)
#define CLR(a,x) memset(a,x,sizeof(a))
const int INF=0x3f3f3f3f;

int n,a[10],tgt[10][10],cnt,ans,pos[10];
bool is[10];
void dfs(int dep){
	// printf("%d\n",dep);
	if(dep==6){
		bool flag=true;
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=1;j<=5;j++){
				if(a[j]!=tgt[i][j]) pos[++cnt]=j;
			}
			if(cnt==0){flag=false;break;}
			else if(cnt==1) continue;
			else if(cnt==2){
				if(pos[2]-pos[1]!=1){flag=false;break;}
				if((a[pos[2]]-a[pos[1]]+10)%10!=(tgt[i][pos[2]]-tgt[i][pos[1]]+10)%10){flag=false;break;}
			}else{flag=false;break;}
		}
		if(flag) ans++;
		return;
	}
	for(int i=0;i<=9;i++){
		a[dep]=i;
		dfs(dep+1);
		a[dep]=0;
	}
}
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%d",&tgt[i][j]);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}