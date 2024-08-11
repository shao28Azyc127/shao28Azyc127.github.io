#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
	long long n,t,bs=0,ans=-1;
	cin>>n;
	t=n;
	while(1){
		bs++;
		if(t<=3){
			bs+=t-1;
			break;
		}
		t-=(t-1)/3+1;
		if((n-1)%3==0&&ans==-1){
			ans=bs;}
	}
	if(ans==-1) ans=bs;
	cout<<bs<<' '<<ans;
	return 0;
}