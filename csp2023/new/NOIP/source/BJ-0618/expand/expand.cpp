#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
long long X[500010],Y[500010];
map<int,map<int,bool> > dp;
struct changed{
	int id;
	long long last;
};
void check(){
	if(X[1]-Y[1]==0||X[n]-Y[m]==0){
		printf("0");
		return ;
	}
	if((X[1]-Y[1]>0)^(X[n]-Y[m]>0)){
		printf("0");
		return ;
	}
	bool fl=(X[1]>Y[1]);
	dp[1][1]=1;
	for(int i = 2;i <= n;i++){
		dp[i][1]= (!(fl^(X[i]>Y[1])))&&(dp[i-1][1]);
	}
	for(int j = 2;j <= n;j++){
		dp[1][j]= (!(fl^(X[1]>Y[j])))&&(dp[1][j-1]);
	}
	for(int i = 2;i <= n;i++){
	    for(int j = 2;j <= m;j++){
			bool tmp=(!(fl^(X[i]>Y[j])));
			dp[i][j]=((tmp) && (dp[i][j-1])) || ((tmp) && (dp[i-1][j])) || ((tmp) && (dp[i-1][j-1]));
	    }
	}
	printf("%d",dp[n][m]);
	return ;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&X[i]);
	}
	for(int i = 1;i <= m;i++){
		scanf("%lld",&Y[i]);
	}
	check();
	stack<changed> cx,cy;
	while(q--){
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		int p;
		long long v;
		while(kx--){
		    scanf("%d%lld",&p,&v);
		    cx.push({p,X[p]});
		    X[p]=v;
		}
		while(ky--){
		    scanf("%d%lld",&p,&v);
		    cy.push({p,Y[p]});
		    Y[p]=v;
		}
		check();
		while(!cx.empty()){
			changed tmpx=cx.top();
			X[tmpx.id]=tmpx.last;
			cx.pop();
		}
		while(!cy.empty()){
			changed tmpy=cy.top();
			Y[tmpy.id]=tmpy.last;
			cy.pop();
		}
	}
	return 0;
}