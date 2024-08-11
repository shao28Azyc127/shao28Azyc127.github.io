#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n;
	cin>>n;
	long long j=0,k=1,flag=0;
	while(n){
		if(flag==0 && n%3==1){
			flag=1;
			k=j+1;
		} 
		n-=n/3+(n%3>0);
		j++;
	}
	cout<<j<<" "<<k;
	return 0;
}
