#include<bits/stdc++.h>
using namespace std;
int n, cnt, ans;
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin>>n;
	while(n){
		++cnt;
		int temp = n;
		if(!ans && n%3==1) ans = cnt;
		if(n%3==0){
			n -= n / 3;
		}else{
			n -= n / 3;
			--n;
		}
	}
	cout<<cnt<<' '<<ans<<endl;
	return 0;
}
