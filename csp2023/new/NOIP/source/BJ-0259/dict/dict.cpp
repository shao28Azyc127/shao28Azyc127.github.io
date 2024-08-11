#include <bits/stdc++.h>
using namespace std;
int b[3010];
struct node
{
	string s1;
	int d;
}a[6010];
bool cmp(char x,char y)
{
	return x>y;
}
bool cmp2(node x,node y)
{
	if(x.s1!=y.s1)
		return x.s1<y.s1;
	return x.d<y.d;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m,k=0,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		a[++k].s1=s;
		a[k].d=i;
		sort(s.begin(),s.end(),cmp);
		a[++k].s1=s;
		a[k].d=i+n;
	}
	sort(a+1,a+k+1,cmp2);
	for(i=1;i<=n;i++)
	{
		if(a[i].d>n)
			break;
		if(i!=n||(i==n&&(a[i].s1!=a[i+1].s1||a[i].d+n==a[i+1].d)))
			b[a[i].d]=1;
	}
	for(i=1;i<=n;i++)
		cout<<b[i];
	return 0;
}
