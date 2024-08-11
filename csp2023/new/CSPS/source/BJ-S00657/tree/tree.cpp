#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	int h=0,d=1;
	while(h<a)
	{
		h+=max(b+d*c,1);
		d++;
	}
	cout<<max(n,d);
	return 0;
}
