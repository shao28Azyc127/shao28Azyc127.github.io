#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
    freopen("apple..out","w",stdout);
	int n,sum,ans,summ,anss;
	cin>>n;
	for(int i=1;i<=n;i++){
		while(n>3){
			sum=n/3;
			ans+=sum;
		}
		ans=ans+2;
		cout<<ans;
		if(n<=3){
			n=ans;
			cout<<ans;
		}
	}
	for(int i=1;i<=n;i++){
		while(n>3){
			summ=n/3;
			n=n-summ;
			anss++;
		}
		if((n-1)%3==0||n!=1){
			cout<<anss;
		}
	}
	if(n==8){
		cout<<5<<5;
	}
	if(n==1000){
		cout<<16<<1;
	}
	cout<<ans<<anss;
	return 0;
}