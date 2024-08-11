#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,re,ans1=0,ans2;
	bool b=true;
	scanf("%d",&n);
	re=n;
	while(re > 0)
	{
		int k=1;
		while(k <= re)
		{
			re--;
			if(k == re && b)
			{
				ans2=k;
				b=false;
			}
			k+=2;
		}
		ans1++;
	}
	if(n%3 == 1)
	{
		ans2=1;
	}
	printf("%d %d\n",ans1,ans2);
}
