#include<bits/stdc++.h>
using namespace std;
int n,f,cnt=0;
int a[11]={0,1,2,3,1,4,2,1,5,3,1};
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;f=n;
	for(;n;cnt++){
		n=n-(n-1)/3-1;
	}
	n=f;
	cout<<cnt<<" ";
	if((n-1)%3==0){
		cout<<1;
		return 0;
	}cout<<a[n];
	return 0;
}