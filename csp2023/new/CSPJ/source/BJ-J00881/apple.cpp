#include<bits/stdc++.h>
using namespace std;
int f(int n){
	if(n<=3){
		return n;
	}
	return f(n-int(ceil(n/3.0)))+1;
}
int solve(int n){
	if(n%3==1){
		return 1;
	}
	return solve(n-int(ceil(n/3.0)))+1;
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	cout<<f(n)<<' ';
	if(n%3==1){
		cout<<1;
	}else{
		cout<<solve(n);
	}
	return 0;
}
