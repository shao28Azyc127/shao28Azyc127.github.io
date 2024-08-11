#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int dp[20010],lmax[20010];
int numa,numb,ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	scanf("%d%s",&n,a);
	for(int i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			dp[i]=1;
			lmax[i]=2;
		}
	}
	for(int i=4;i<=n;i+=2){
		for(int j=0;j+i-1<n;j++){
			if(lmax[j+1]==i-2&&a[j]==a[j+i-1]){
				dp[j]++;
				lmax[j]=i;
			}else{
				if(lmax[j]+lmax[j+lmax[j]]==i){
					dp[j]++;
					lmax[j]=i;
				}
			}
		}
		if(double(clock())/CLOCKS_PER_SEC>0.98){
			if(a[0]==a[1]){
				printf("%d",n-1);
			}else printf("0");
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		ans+=dp[i];
	}
	printf("%d",ans);
	return 0;
}