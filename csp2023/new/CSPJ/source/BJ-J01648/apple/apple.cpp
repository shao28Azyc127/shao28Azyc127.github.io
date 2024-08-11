#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,c=0;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(n!=0){
		if(n%3==0){
			n=n-n/3;
			c++;
		}
		else if(n%3==1){
			n=n-n/3-1;
			c++;
			if(ans==0){
				ans=c;
			}
		}
		else if(n%3==2){
			n=n-n/3-1;
			c++;
		}
	}
	cout<<c<<" "<<ans;
	return 0;
}
