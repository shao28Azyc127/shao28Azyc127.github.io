#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int  i=1;i<=n;i++)

long long n;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	long long temp=n;
	long long ans=0;
	while(temp>=1){
		ans++;
		temp=temp-((temp+2)/3);
	}
	cout << ans<<" ";
	ans=0;
	while(1){
		ans++;
		if((n-1)%3==0){
			cout << ans << endl;
			break;
		}else{
			n=n-((n+2)/3);
		}
	}
	return 0;
}
