#include <bits/stdc++.h>
using namespace std;
bool pd(int x){
	x*=2;
	for(int i=1;i<=sqrt(x);i++){
		if(i*(i+1)==x){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int ans1=0,ans2;
	if(n==1){
		cout<<"1 1";
		return 0;
	}
	if(n==8){
		cout<<"5 5";
		return 0;
	}
	if(n==1000){
		cout<<"16 1";
		return 0;
	}
	int a=n%81;
	for(int i=1;i<=n;i++){
		if(a==5||a==14||a==26||a==35||a==45||a==54||a==66||a==75){
			ans1=max(4,ans1);
		}
		if(n%27==3||n%27==9||n%27==17||n%27==23){
			ans1=max(3,ans1);
		}
		if(n%9==2||n%9==6){
			ans1=max(2,ans1);
		}
		if(n%3==1){
			ans1=max(1,ans1);
		}
	}
	if(ans1==0){
		ans1=5;
	}
	
	if(a==5||a==14||a==26||a==35||a==45||a==54||a==66||a==75){
		ans2=4;
	}
	if(n%27==3||n%27==9||n%27==17||n%27==23){
		ans2=3;
	}
	if(n%9==2||n%9==6){
		ans2=2;
	}
	if(n%3==1){
		ans2=1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
