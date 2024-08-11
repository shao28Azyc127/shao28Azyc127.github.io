#include<bits/stdc++.h>
using namespace std;
int n,tmp,cnt,ans;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	tmp=n;
	while(tmp!=0){
		if(ans==0 && tmp%3==1){
			ans=cnt+1;
		}
		int sum=tmp/3;
		if(tmp%3!=0){
			sum++;
		}
		tmp-=sum;
		cnt++;
	}
	cout<<cnt<<" "<<ans;
	return 0;
}
