#include <bits/stdc++.h>
using namespace std;
int n;
char a[10000];
int ans=0;
bool check(int k,int l){
	stack<char> stk;
	for(int i=k;i<=l;i++){
		if(stk.empty()) stk.push(a[i]);
		else if(a[i]==stk.top()) stk.pop();
		else stk.push(a[i]);
	}
	if(stk.empty()) return 1;
	return 0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((i+j+1)%2==0){
				if(check(i,j)) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}