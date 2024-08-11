#include<bits/stdc++.h>
using namespace std;
unsigned long long opcounter=0;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	string a;
	int n;
	long long cnt=0;
	cin>>n>>a;
	int lena=a.size();
	while(lena!=0)
	{
		for(int i=0;i<lena-1;i++)
		{
			if(a[i]==a[i+1])
			{
				a.erase(i,2);
				lena-=2;
				cnt++;
			}	
		}
		opcounter++;
		if(opcounter>lena)
			break;
	}
	if(lena==0)
		cnt++;
	cout<<cnt;	
	return 0;
}