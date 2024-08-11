#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[2000005];
stack<int>stk;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin>>n;
	scanf("%s",s+1);
	int op1=1;
	int ans=0;
	if(n<=8000){
		for(int i=1;i<=n;i++){
			while(!stk.empty()) stk.pop();
			for(int k=i;k<=n;k++){
				if((!stk.empty())&&s[k]==stk.top()) stk.pop();
				else stk.push(s[k]);
				if(!stk.size()) ans++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			while(!stk.empty()) stk.pop();
			for(int k=i;k<=min(n,i+100);k++){
				if((!stk.empty())&&s[k]==stk.top()) stk.pop();
				else stk.push(s[k]);
				if(!stk.size()) ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
