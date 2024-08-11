#include <bits/stdc++.h>
using namespace std;
struct abc{
	int a,b,c;
	int is,high;
}abcc[10010];
int edge[800][800],days;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>abcc[i].a>>abcc[i].b>>abcc[i].c;
	}
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		edge[u][v]=edge[v][u]=1;
		abcc[i].high=-99980;
	}
	int x=1;
	abcc[1].is=1,abcc[1].high=0;

	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(edge[i][j]==1 && abcc[i].is!=1 && abcc[j].is==1){
				abcc[i].is=1;
				abcc[i].high=0;
			}
		}
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++){

		for(int j=1;j<=n;j++){
			if(abcc[i].is==1 && abcc[i].high==abcc[i].a){
				cnt++;
			}
		}
		if(cnt>=n){
			break;
		}else{
			x+=1;//tianshu
			abcc[i].high+=max(abcc[i].b+x*abcc[i].c,1);
		}
	}
		
	cout<<x;
	return 0;
}
