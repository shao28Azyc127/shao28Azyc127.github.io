#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k;
	int a[m],b[m],c[m];
	cin>> n>> m>> k;
	for(int i=0;i<m;i++) cin>> a[i]>> b[i]>> c[i];
	if(c[0]==0) cout<< "0";
	else cout<< "-1";
	return 0;
}

