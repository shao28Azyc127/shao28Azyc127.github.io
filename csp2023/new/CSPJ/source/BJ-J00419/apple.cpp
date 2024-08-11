#include<bits/stdc++.h>
using namespace std;
int n,cnt1=0,cnt2=0,x;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	x=n;
	while(x>0){
		cnt1++;
		x-=(x-1)/3+1;
	}
	x=n;
	while(++cnt2){
		if(x%3==1) break;
		x-=(x-1)/3+1;
	}
	cout<<cnt1<<" "<<cnt2;
	return 0;
}
