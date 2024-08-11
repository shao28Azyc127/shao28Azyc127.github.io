#include <bits/stdc++.h>
using namespace std;
#define N 100005
int sum,b[N],c[N],work1[N],work2[N],n,m,a[N],ans;
char v[N];
void dfs(int deep){
	int flag=0,x,y;
	if(deep==n){
		for(int i=1;i<=n;i++){
			c[i]=b[i];
		}
		for(int i=1;i<=m;i++){
			if(v[i]=='+'){
				x=work1[i],y=work2[i];
				c[x]=c[y];
			}
			else if(v[i]=='-'){
				x=work1[i],y=work2[i];
				if(c[y]==-1){
					c[x]=-2;
				}
				else if(c[y]==-2){
					c[x]=-1;
				}
				else{
					c[x]=-3;
				}
			}
			else{
				x=work1[i];
				c[x]=work2[i];
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]!=b[i]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			ans=min(ans,sum);
		}
		return;
	}
	b[deep+1]=-3;
	sum++;
	dfs(deep+1);
	sum--;
	b[deep+1]=-1;
	dfs(deep+1);
	b[deep+1]=-2;
	dfs(deep+1);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T,flag=0,x,y,vis[N],mark;
	scanf("%d%d",&c,&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			cin>>v[i];
			if(v[i]=='+'||v[i]=='-')  flag=1;
			if(v[i]=='T'){
				scanf("%d",&x);
				work1[i]=x;
				work2[i]=-1;
				a[x]=-1;
			}
			else if(v[i]=='F'){
				scanf("%d",&x);
				work1[i]=x;
				work2[i]=-2;
				a[x]=-2;
			}
			else if(v[i]=='U'){
				scanf("%d",&x);
				work1[i]=x;
				work2[i]=-3;
				a[x]=-3;
			}
			else{
				scanf("%d%d",&x,&y);
				work1[i]=x,work2[i]=y;
			}
		}
		if(flag==0){
			ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==-3)  ans++;
			}
			printf("%d\n",ans);
		}
		else if(n<=10){
			ans=1e9;
			dfs(0);
			printf("%d\n",ans);
		}
		else if(c==5||c==6){
			ans=0;
			while(1){
				mark=0;
				for(int i=1;i<=n;i++){
					if(vis[i])  continue;
					if(a[i]==-3){
						ans++;
						vis[i]=1;
					}
					else if(a[a[i]]==-3){
						mark=1;
						a[i]=-3;
						ans++;
						vis[i]=1;
					}
				}
				if(mark==0)  break;
			}
			printf("%d\n",ans);
		}
		else{
			printf("%d\n",n);
		}
	}
	return 0;
}
