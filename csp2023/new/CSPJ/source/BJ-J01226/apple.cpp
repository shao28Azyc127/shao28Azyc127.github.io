#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int ans1=0;
	while(n>0){
		ans1++;
		if(!ans2&&n%3==1)ans2=ans1;
		n=n-(n-1)/3-1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
