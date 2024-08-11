#include<bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int c[100001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	//int ans=0;
	int k=0;
	for(int i=1;i<n;i++)
	{
		int tmp;
		if(a[i]%m==0)
		{
			tmp=a[i]/m;
		}
		else
		{
			tmp=a[i]/m+1;
		}
		c[k]=tmp*b[i-1];
		k++;
	}
	sort(c,c+k);
	if(k%2==0)
	{
		k/=2;
	}
	else
	{
		k/=2;
		k++;
	}
	int sum=0;
	for(int i=0;i<k;i++)
	{
		sum+=c[i];
	}
	cout<<sum;
}
