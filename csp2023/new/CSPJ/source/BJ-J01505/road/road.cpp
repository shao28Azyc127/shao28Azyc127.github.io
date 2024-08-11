#include<iostream>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	int a[n];
	int x=n-1;
	int v[x];
	cin>>n>>d;
	cin>>v[x];
	cin>>a[n];
	int m;
	int ma[n];
	for(int i=1;i>n;i++)
	{
		ma[i]=v[i]*a[i];
	}
	for(int i=1;i<n;i++)
	{
		m+=ma[i];
	}
	cout<<m;
	return 0;
}