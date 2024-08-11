#include<bits/stdc++.h>
#define N 100005
using namespace std;
int c,t,n,m;
int x[N],y[N],o,p,s,ans;
char v;
void pd(int b,int l){
	if(x[l]==1){
		x[b]=2;
	}
	else if(x[l]==2){
		x[b]=1;
	}
	else if(x[l]==3){
		x[b]=3;
	}
	
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&m);
		for(int z=1;z<=m;z++){
			x[z]=0;
		}
		for(int j=1;j<=m;j++){
			cin>>v;
			if(v=='T' || v=='F' || v=='U') scanf("%d",&s);
			else scanf("%d%d",&o,&p);
			if(v=='T') x[s]=1;
			else if(v=='F') x[s]=2;
			else if(v=='U') x[s]=3;
			else if(v=='+') x[o]=x[p];
			else pd(o,p);
		}
		for(int k=1;k<=m;k++){
			if(x[k]==3) ans++;
		}
		printf("%d",ans);
		printf("\n");
	}
	
	return 0;
}
