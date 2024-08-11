#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ansn=0,cnt=0;
    cin>>n;
    if(n%3==1)ansn=1;
    while(n>0){
		n-=(n+2)/3;
		cnt++;
		if(ansn==0 && n%3==1)ansn=cnt+1;
	}
	cout<<cnt<<" "<<ansn;
    return 0;
}