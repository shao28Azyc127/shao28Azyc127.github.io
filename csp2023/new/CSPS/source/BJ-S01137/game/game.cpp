#include<bits/stdc++.h>
#define F
using namespace std;
const int MAXN=2000010;
int n;
struct Node
{
	char val;
	bool iserase;
};
Node s[MAXN];
int ans=0;

int main()
{
	#ifdef F
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	#endif
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].val;
		s[i].iserase=false;
	}
	for(int i=2;i<=n;i+=2)//len
	{
		for(int j=1;j<=n-i+1;j++)
		{
			int fir=0,sec=0;
			for(int k=j;k<=j+i-1;k++)
			{
				if(s[k].iserase)
					continue;
				else
				{
					if(!fir)
						fir=s[k].val;
					else
					{
						sec=s[k].val;
						if(fir==sec)
							ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}