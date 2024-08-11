#include<bits/stdc++.h>
using namespace std;

const int MAXN=2000000+10;
char str[MAXN];
int N;
char stk[MAXN];
int idx,ans;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&N);
	scanf("%s",str);
	for(int i=0;i<N;i++){
		idx=0;
		for(int j=i;j<N;j++){
			if(idx && stk[idx]==str[j]){
				idx--;
				if(!idx){
					ans++;
				}
				continue;
			}
			stk[++idx]=str[j];
		}
	}
	printf("%d\n",ans);
	return 0;
}