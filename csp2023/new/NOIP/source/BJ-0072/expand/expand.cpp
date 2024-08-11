#include<bits/stdc++.h>
using namespace std;
const int INF=2e9;
int X[500005],Y[500005];
int x[500005],y[500005];
int dp[2005][2005];
int n,m;
void chk(){
	if(x[1]==y[1]){
		printf("0");
		return;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j]=0;
	int op=0;
	dp[1][1]=1;
	if(x[1]>y[1]) op=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!dp[i][j]) continue;
			if(!op){
				if(j+1<=m&&y[j+1]>x[i]) dp[i][j+1]=1;
				if(i+1<=n&&y[j]>x[i+1]) dp[i+1][j]=1;
				if(i+1<=n&&j+1<=m&&y[j+1]>x[i+1]) dp[i+1][j+1]=1;
			}
			else{
				if(j+1<=m&&y[j+1]<x[i]) dp[i][j+1]=1;
				if(i+1<=n&&y[j]<x[i+1]) dp[i+1][j]=1;
				if(i+1<=n&&j+1<=m&&y[j+1]<x[i+1]) dp[i+1][j+1]=1;
			}
		}
	} 
	if(dp[n][m]) printf("1");
	else printf("0");
}
void chk1(){
	if(x[1]==y[1]){
		printf("0");
		return;
	}
	if(x[1]<y[1]){
		int mnx=INF,mny=INF;
		for(int i=1;i<=n;i++) mnx=min(mnx,x[i]);
		for(int i=1;i<=m;i++) mny=min(mny,y[i]);
		if(mnx<mny){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	else{
		int mnx=INF,mny=INF;
		for(int i=1;i<=m;i++) mnx=min(mnx,y[i]);
		for(int i=1;i<=n;i++) mny=min(mny,x[i]);
		if(mnx<mny){
			printf("1");
		}
		else{
			printf("0");
		}
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,q,kx,ky,p,v;
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		scanf("%d",&X[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&Y[i]);
	}
	if(c<=7){
		for(int j=1;j<=n;j++) x[j]=X[j];
		for(int j=1;j<=m;j++) y[j]=Y[j];
		chk();
		for(int i=1;i<=q;i++){
			for(int j=1;j<=n;j++) x[j]=X[j];
			for(int j=1;j<=m;j++) y[j]=Y[j];
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++){
				scanf("%d%d",&p,&v);
				x[p]=v;
			}
			for(int i=1;i<=ky;i++){
				scanf("%d%d",&p,&v);
				y[p]=v;
			}
			chk();
		}
		puts("");
	}
	else{
		for(int j=1;j<=n;j++) x[j]=X[j];
		for(int j=1;j<=m;j++) y[j]=Y[j];
		chk1();
		for(int i=1;i<=q;i++){
			for(int j=1;j<=n;j++) x[j]=X[j];
			for(int j=1;j<=m;j++) y[j]=Y[j];
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++){
				scanf("%d%d",&p,&v);
				x[p]=v;
			}
			for(int i=1;i<=ky;i++){
				scanf("%d%d",&p,&v);
				y[p]=v;
			}
			chk1();
		}
		puts("");
	}
	return 0;
}