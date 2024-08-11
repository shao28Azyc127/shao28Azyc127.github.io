#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long a,cnt=0,n=0,flag=0;
	cin>>a;
	while(a!=0){
		a--;
		cnt++;
		if(a%3==0&&flag==0){
			flag=1;
			n=cnt;
		}
		a-=a/3;
	}
	cout<<cnt<<" "<<n;
	return 0;
}