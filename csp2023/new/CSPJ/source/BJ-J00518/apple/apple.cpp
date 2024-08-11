#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,ans1=0,ans2=0;
	cin>>n;
	bool h=0;
	while(n>0){
		ans1++;
		if(n%3==1&&!h){
			ans2=ans1;
			h=1;
		}
		n-=((n-1)/3+1);
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}