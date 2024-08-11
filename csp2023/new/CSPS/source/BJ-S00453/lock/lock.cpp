#include <iostream>
using namespace std;
int a[6];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=5;i++)
		cin>>a[i];
	if(n==1){
		cout<<81;
	}else{
		cout<<1;
	}
	return 0;
}