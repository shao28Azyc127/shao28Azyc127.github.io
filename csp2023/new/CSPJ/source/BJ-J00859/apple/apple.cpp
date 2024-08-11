#include<iostream>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	
	long long day=0,n,dayn=0;
	cin>>n;
	long long n2=n,n3=n;
	while(n){
		day++;
		long long a=1+(n-1)/3;
		n-=a;
		
	}
	cout<<day<<" ";
	while(n3){
		long long b=1+(n3-1)/3;
		n3-=b;
		dayn++;
		if((n2-1)%3==0){
			cout<<dayn;
			break;
		}
		else{
			n2-=b;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}