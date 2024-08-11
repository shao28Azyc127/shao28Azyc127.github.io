#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
int n,num=0,num2=0,x=0;
cin>>n;
while(n>=0){
	num++;
	if(n%3==1&&n>3){
		num2=num;
		x=1;
	}
	if(n>=3){
		n-=n/3+1;
	}else{
		n-=1;
	}
}
if(x==0){
	num2=num;
}
cout<<num<<" "<<num2;
return 0;
}