#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	long long cmp=0;
	long long tmp=n;
	while(tmp){
		if(tmp%3==0) tmp=tmp-(tmp/3);
		else tmp=tmp-(tmp/3+1);
		ans++;
	}
	long long x=1;
	while(n){
		if(n%3==1){
			cmp=x;
			break;
		}
		else if(n%3==2) n=n-(n/3+1);
		else n=n-(n/3);
		x++;
	}
	cout<<ans<<" "<<cmp;
	return 0;
}
