#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a ; i<=b ; i++)
using namespace std;
int n,cnt;
bool flag;
int k[100005];
int a;
stack<int> stk;
bool pipei(int l,int r){
	stk.push(k[l]);
	f(i,l+1,r){
		if(stk.top() == k[i] && !stk.empty()) stk.pop();
		else stk.push(k[i]);
	}
	return stk.empty();
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	f(i,1,n) cin>>k[i];
	for(int i = 1 ; i<=n ; i++){
		for(int j = 1 ; j<=n ; j++){
			if(pipei(i,j)) cnt++;
			while(!stk.empty()) stk.pop();
		}
	}
	cout<<cnt;
	return 0;
}
