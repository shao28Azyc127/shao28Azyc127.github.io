#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt=0;
	long long ans;
	bool flag=1;
	while(n){
		if((n+2)%3==0&&flag){
			ans=cnt+1;
			flag=0;
		}
		if(n%3==0){
			n-=n/3;
		}else{
			n-=n/3+1;
		}
		cnt++;
	}
	cout<<cnt<<" "<<ans;
	return 0;
}
