#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n ,ans=0,tmp;
	bool flag=false;
	cin >> n ;
	while(n!=0){
		if(n%3==1&&flag==false){
			tmp=ans+1;
			flag=true;
		}
		if(n%3==0){
			ans++;
			n-=(n/3);
		}
		else{
			ans++;
			n-=((n/3)+1);
		}
	}
	cout << ans<<" "<<tmp;
	return 0;
}
