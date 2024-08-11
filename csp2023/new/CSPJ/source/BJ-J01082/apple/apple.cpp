#include<bits/stdc++.h>
using namespace std;
int n,sum,t,f,d,y;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(n>0){
		d++;
		sum=n/3;
		if(n%3)sum++;
		if(!f && n%3==1){
			y=d;
			f=1;
		}
		n-=sum;
	}
	cout<<d<<' '<<y;
	return 0;
}