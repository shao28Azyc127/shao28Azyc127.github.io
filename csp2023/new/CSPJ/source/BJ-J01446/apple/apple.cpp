#include <bits/stdc++.h>
using namespace std;
int n, ans1, ans2;
bool t;
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin>>n;
	while(n){
		ans1++;
		if(n%3==1&&!t){
			ans2=ans1;
			t=1;
		}
		if(n%3!=0){
			n-=n/3+1;
		}
		else{
			n-=n/3;
		}
	}
	cout<<ans1<<" "<<ans2;
    return 0;
}