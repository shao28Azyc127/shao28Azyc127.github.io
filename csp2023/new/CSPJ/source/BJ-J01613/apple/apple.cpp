#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int ans=0,t=n;
	while(t){
		t-=(t+2)/3;
		ans++;
	}
	cout<<ans<<' ';
	ans=0,t=n;
	while(t){
		ans++;
		if(t%3==1){
			cout<<ans;
			return 0;
		}
		t-=(t+2)/3;
	}
	return 0;
}
