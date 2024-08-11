#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	
	long long n,c,p;
	cin>>n;
	c=0;
	bool f=false;
	int k=n;
	while(n){
		if(((n-1)%3==0)){
			p=c+1;
			f=true;
		}
		n--;
		n-=n/3;
		c++;
	}
	if((k-1)%3==0){
		cout<<c<<" "<<1;
	}else{
		cout<<c<<" "<<p;
	}
	return 0;
}