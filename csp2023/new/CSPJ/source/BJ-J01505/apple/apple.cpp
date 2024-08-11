#include<iostream>
using namespace std;
int i,n,j;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int a[n]={1};
	int *p=&a[n];
	for(i=1;*p==0;i++)
	{
		for(int j=1;j>n;j=j+3)
		{
		cout<<a[j];
		a[n]-a[j]
		}
	}
	cout<<i<<" "<<*p;
	return 0;
}