#include <bits/stdc++.h>
using namespace std;
char x[2000001];
int n;
long long ans;
bool a[8001][8001];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		scanf("%c",&x[i]);
	}
	for(int i=n-1;i>0;i--){
		if(x[i]==x[i+1]){
			a[i][i+1]=1;
			ans++;
		}
		for(int j=i+3;j<=n;j+=2){
			if(x[i]==x[j]&&a[i+1][j-1]){
				a[i][j]=1;
				ans++;
				continue;
			}
			for(int k=i+1;k<j;k+=2){
				if(a[i][k]&&a[k+1][j]){
					a[i][j]=1;
					ans++;
					break;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}