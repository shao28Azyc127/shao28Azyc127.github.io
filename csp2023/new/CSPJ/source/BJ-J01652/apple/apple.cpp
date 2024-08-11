#include<bits/stdc++.h>
#define F
using namespace std;
const int MAXN=1e6+10;

int n;
int d,ansn;
bool vis[MAXN];

int main()
{
	#ifdef F
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	#endif
	cin>>n;
	int tot=n;
	while(tot!=0)
	{
		d++;
		int cnt=2;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
				continue;
			if(cnt<2)
			{
				cnt++;
				continue;
			}
			else
			{
				cnt=0;
				vis[i]=true;
				tot--;
				if(i==n)
					ansn=d;
			}
		}
	}
	cout<<d<<" "<<ansn<<endl;
	return 0;
}