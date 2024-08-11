#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int tmp=n,res1=0,res2=-1;
	while (tmp>0)
	{
		if (tmp%3==1&&res2==-1) res2=res1+1;
		tmp=tmp-(tmp%3==0?tmp/3:tmp/3+1);
		res1++;
	}
	cout<<res1<<" "<<res2;
	return 0;
}
