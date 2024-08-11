#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	long long temp = n;
	long long i = 0;
	long long ans = 0;
	while(n != 0){
		if(n%3 ==0){
			n= n-n/3;
			i++;
			continue;
		}
		if(n <= 2){
			n-=1;
			i++;
			continue;
		}
		n=n-(n/3+1);
		i++;
	}
	cout<<i<<" ";
	while(temp!=0){
		if((temp-1)%3 == 0){
			cout<<ans+1<<endl;
			return 0;
		}
		if(temp%3 ==0){
			temp=temp-temp/3;
			ans++;
			continue;
		}
		if(temp <= 2){
			temp-=1;
			ans++;
			continue;
		}
		temp=temp-(temp/3+1);
		ans++;
	}
	return 0;
}
