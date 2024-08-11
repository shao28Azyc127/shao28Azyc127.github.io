#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int m=n;
	int ans1=0;
	int ans2=0;
	bool flag=false;
	while(m){
		if(!flag&&(m-1)%3==0){
			flag=true;
			ans2=ans1;
		} 
		int s=(m-1)/3+1;
		m-=s;
		ans1++;
	}
	cout<<ans1<<" "<<ans2+1;
	return 0;
}