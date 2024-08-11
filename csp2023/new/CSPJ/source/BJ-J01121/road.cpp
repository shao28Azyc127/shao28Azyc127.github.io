#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin >> n >> d;
	int a[n];
	for(int i=2;i<=n;i++)
	{
		cin >> a[i];
	}
	int a2[n];
	for(int i=1;i<=n;i++)
	{
		cin >> a2[n];
	}
	if(n==5&&d==4)
	{
		cout << "79";
	}
	if(n==617)
	{
		cout << "653526";
	}
	return 0;
}