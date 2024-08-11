#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int N=1e5+10;
int n;
void ipt(){
	scanf("%lld",&n);
}
void solve(){
	int cnt=0;
	int tmp=n;
	int ans=0;
	while(n>3){
		cnt++;
		if((n-1)%3==0&&ans==0) ans=cnt;
		n-=(n-1)/3+1;
	}
	printf("%lld %lld",cnt+n,ans==0?cnt+n:ans);
}
signed main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ipt();
	solve();
	return 0;
}