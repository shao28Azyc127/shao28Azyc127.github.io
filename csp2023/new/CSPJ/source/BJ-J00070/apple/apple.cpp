#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n;
	cin>>n;
	int ans1=0, ans2=0;
	while(n){
		ans1++;
		if(n%3==1 && !ans2)
			ans2=ans1;
		if(n%3==0)
			n=n-n/3;
		else
			n=n-n/3-1;
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}