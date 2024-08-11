#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n=0,a=0,m=0;
	cin>>n;
	while(n){
		
		m++;
		if(n%3==1 && a==0){
			a=m;
		}
		n=n-1-(n-1)/3;
	}
	if(a==0){
		a=m;
	}
	cout<<m<<" "<<a;
	return 0;
}