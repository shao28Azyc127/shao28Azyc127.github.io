#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,d,maxe=-2147483648;
int x[100001],y[100001],u[100001];
bool run[100001];
void dfs(int s,int e,int co){
	if(s>n){
		for(int i=1;i<=m;i++){
			bool f=1;
			for(int j=x[i]-y[i]+1;j<=x[i];j++)f&=run[j];
			if(f)e+=u[i];
		}
		maxe=max(maxe,e);
		return;
	}
	if(co==k){
		run[s]=0;
		dfs(s+1,e,0);
	}else{
		run[s]=1;
		dfs(s+1,e-d,co+1);
		run[s]=0;
		dfs(s+1,e,0);
	}
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		maxe=-2147483648;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)scanf("%d%d%d",&x[i],&y[i],&u[i]);
		dfs(1,0,0);
		printf("%d\n",maxe);
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
