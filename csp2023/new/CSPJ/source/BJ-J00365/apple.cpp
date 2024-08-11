#include<iostream>
#include <cstdio>
using namespace std;
long long n,ans=0,ans1;
bool f=false;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(n>=4){
		if(n%3==1&&f==false){
			ans1=ans+1;
			f=true;
		}
		if(n%3==0){
			n-=n/3;
		}
		else{
			n-=n/3;
			n-=1;
		}
		ans++;
	}
	if(ans1==0){
		ans1=ans+n;
	}
	cout<<ans+n<<" "<<ans1<<endl;
	return 0;
}
