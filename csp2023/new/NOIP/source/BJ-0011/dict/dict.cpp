#include<iostream>
using namespace std;
struct str
{
	int l,r;
};
int n,m;
char s[3010];
str a[3010];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s+1;
		a[i].l=26,a[i].r=-1;
		for(int j=1;j<=m;j++)
		{
			a[i].l=min(a[i].l,s[j]-'a');
			a[i].r=max(a[i].r,s[j]-'a');
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				continue;
			}
			flag&=(a[i].l<a[j].r);
		}
		cout<<flag;
	}
	cout<<endl;
	return 0;
}