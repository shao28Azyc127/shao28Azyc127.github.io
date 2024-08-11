#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n,t,sum=0,sum2=0;
	cin>>n;
	t=n;
	while(n!=0){
		n=n-(n+2)/3;
		sum++;
	}
	while(t%3!=1){
		t=t-(t+2)/3;
		sum2++;
	}
	cout<<sum<<" "<<sum2+1<<endl;
	return 0;
}