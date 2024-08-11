#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,top;
ll ans;
char s[2000001],st[2000001];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<=n;i++)scanf("%c",&s[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			top=1;
			for(int k=i;k<=j;k++){
				if(st[top-1]==s[k]){
					top--;
				}else{
					st[top]=s[k];
					top++;
				}
			}
			if(top==1)ans++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
