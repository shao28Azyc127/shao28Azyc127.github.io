#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n,i=0,na=0;
	cin>>n;
	while(n>=3){
		i++;
		if(n%3==1){
			if(na==0)na=i;
		}
		n-=(n+2)/3;
	}
	i+=n;
	if(na==0)na=i;
	cout<<i<<" "<<na<<endl;
	return 0;
}