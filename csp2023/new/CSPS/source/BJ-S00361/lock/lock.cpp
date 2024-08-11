#include<bits/stdc++.h>
using namespace std;
int a[10][10],g[10],x[100];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
	}
	for(int j=0; j<=99999; j++){
		g[1]=j/10000; g[2]=j/1000%10; g[3]=j/100%10; g[4]=j/10%10; g[5]=j%10;
		bool f=1;
		for(int i=1; i<=n; i++){
			int cnt=0;
			for(int k=1; k<=5; k++){
				if(a[i][k]!=g[k]) x[++cnt]=k;
			}
			if(!cnt){
				f=0; break;
			}else if(cnt!=1){
				if(cnt>2){
					f=0; break;
				}else if(x[2]-x[1]!=1){
					f=0; break;
				}else if((g[x[2]]-g[x[1]]+10)%10!=(a[i][x[2]]-a[i][x[1]]+10)%10){
					f=0; break;
				}
			}
		}
		if(f) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
