#include<bits/stdc++.h>
using namespace std;
int n,d,a[100001],b[10001],c;
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin >> n >> d;
for(int i=1; i<=n; i++)
cin >> a[i];
for(int i=1; i<=n-1; i++)
cin >> b[i];
for(int i=1; i<=n-1; i++)
c=c+b[i];
if(c%d==0)
cout << c/d*a[1];
else
cout << (c%d+1)*a[1];
return 0;
}
