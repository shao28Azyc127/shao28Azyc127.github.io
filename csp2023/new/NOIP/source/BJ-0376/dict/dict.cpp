#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string maxn[3005],minn[3005],s;
int n,m;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		sort(s.begin(),s.begin()+m);
		minn[i]=maxn[i]=s;
		reverse(maxn[i].begin(),maxn[i].end());/*
		cout<<"min:"<<minn[i]<<"\nmax:"<<maxn[i]<<endl;*/
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			if(minn[i]>=maxn[j])
			{
				cout<<0;
				break;
			}
		}
		cout<<1;
	}
	return 0;
}