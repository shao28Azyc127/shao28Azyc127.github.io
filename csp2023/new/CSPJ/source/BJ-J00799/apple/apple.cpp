#include<iostream>
using namespace std;
int num(int x){
	if(x<=3)	return x;
	return num(x-(1+(x-1)/3))+1;
}
int lst(int x){
	if(x%3==1)	return 1;
	return lst(x-(1+(x-1)/3))+1;
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	cout<<num(n)<<' '<<lst(n);
	return 0;
}