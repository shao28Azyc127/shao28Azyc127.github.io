#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int a[2000005];
long long ans;
int stk[2000005],len;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;++i){
		a[i]=s[i-1]-'a'+1;
	}
	if(n<=8000){
		for(int i=1;i<=n;++i){
			len=0;
			stk[0]=0;
			for(int j=i;j<=n;++j){
				if(stk[len]==a[j]){
					--len;
				}
				else{
					++len;
					stk[len]=a[j];
				}
				if(len==0){
					++ans;
				}
			}
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
