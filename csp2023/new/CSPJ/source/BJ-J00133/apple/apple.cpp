#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,cnt=0,ans=1,flag=0;
	cin>>n;
	while(n>0){
		cnt++;
		if(!flag && n%3==1){
			ans=cnt;
			flag=1;
		}
		n-=n/3+(n%3==0?0:1);
	}
	cout<<cnt<<" "<<ans;  
	return 0;
}