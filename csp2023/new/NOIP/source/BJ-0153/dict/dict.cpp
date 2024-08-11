#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
string mn[3005],mx[3005];
bool ok[3005];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>mn[i];
		sort(mn[i].begin(),mn[i].end());
		mx[i]=mn[i];
		reverse(mx[i].begin(),mx[i].end());
		ok[i]=1;
	}
	string mnx=mx[0];
	for(int i=1;i<n;i++)
	{
//		cout<<mn[i]<<" "<<mnx<<endl;
		if(mn[i]>=mnx)	ok[i]=0;
		if(mx[i]<mnx)	mnx=mx[i];
	}
//	cout<<endl;
	mnx=mx[n-1];
	for(int i=n-2;i>=0;i--)
	{
//		cout<<mn[i]<<" "<<mnx<<endl;
		if(mn[i]>=mnx)	ok[i]=0;
		if(mx[i]<mnx)	mnx=mx[i];
	}
//	cout<<endl;
	for(int i=0;i<n;i++)	cout<<ok[i];
	cout<<endl;
}