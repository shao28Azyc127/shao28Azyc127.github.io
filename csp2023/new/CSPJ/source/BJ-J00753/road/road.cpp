#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	int a[n],b[n];
	cin>> n>> d;
	for(int i=0;i<n-1;i++) cin>> a[i];
	for(int i=0;i<n;i++) cin>> b[i];
	int num=0;
	for(int i=0;i<n-1;i++) num+=a[i];
	cout<< num/4*b[0];
	return 0;
}

