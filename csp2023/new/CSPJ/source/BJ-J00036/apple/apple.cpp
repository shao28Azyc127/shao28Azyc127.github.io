#include<bits/stdc++.h>
using namespace std;

long long n,i=0,flag,c;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	while(n>0){
		n--;
		//cout << n << endl;
		if(n%3==0&&flag==0){
			c=i+1;
			flag=1;
		}
		n-=n/3;
		i++;
	}
	cout << i << ' ' << c;
	
	
	return 0;
}
