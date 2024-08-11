#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[10][10],cnt;
signed main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=5;k++){
				if(a[i][k]!=a[j][k]){
					cnt++;
					if(a[i][k+1]-a[i][k]==a[j][k+1]-a[j][k]){
						k++;
					}
				}
			}
		}
	}
	if(cnt==0){
		printf("81");
	}else{
		printf("%lld",cnt*10);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
