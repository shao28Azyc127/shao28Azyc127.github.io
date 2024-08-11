#include <bits/stdc++.h>
using namespace std;
char c[2000009];
int main(){
	//int s;
	long long n,a=2,l=0;
	char b;
	cin>>n;
	cin>>b;
	c[1]=b;
    for(long long i=2;i<=n;i++){
		cin>>b;
		if(b==c[a-1]){
			a-=1;
			l++;
		}
		else{
			c[a]=b;
		}
		a++;
	}
	if(a==2){
		l++;
	}
	cout<<l;

return 0;
}
