#include<bits/stdc++.h>
using namespace std;
int n,sum,aim;
bool q;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	while(n>=3)
	{
		if(n%3==1&&q==0)
		{
			aim=sum+1;
			q=1;
		}
		if(n%3==0)
		{
			n=n-n/3;
		}
		else
		{
			n=n-n/3-1;
		}
		sum++;
		
	}
	sum+=n;
	if(q==0)
	aim=sum;
	cout << sum << " "<< aim;
	fclose(stdin);
	fclose(stdout);
	return 0;
}