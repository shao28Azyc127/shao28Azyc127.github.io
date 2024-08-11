#include<iostream>
using namespace std;
int n,ans1,ans2;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	bool flag=0;
	while(n){
		ans1++;
		if(flag==0&&n%3==1){
			ans2=ans1;
			flag=1;
			}
		if(n%3==1){
			n=n-(n+2)/3;
		}
		else if(n%3==2){
			n=n-(n+1)/3;
		}
		else{
			n=n-n/3;
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}
