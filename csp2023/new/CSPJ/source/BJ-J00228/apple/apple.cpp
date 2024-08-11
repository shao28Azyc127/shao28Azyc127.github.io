#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int vis[N];
int n;
int cnt=0,d=0,don=0,p=0,now=1;
bool flg;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while (cnt<n)
	{
		d++;
		p=0;
		flg=false;
		now=don+1;
		while (now<=n)
		{
			if (vis[now]==0)
			{
				p=(p+1)%3;
				if (p==1)
				{
					if (!flg)
					{
						flg=true;
						don=now;
					}
					vis[now]=d;
					cnt++;
				}
			}
			now++;
		}
	}
	cout<<d<<" "<<vis[n]<<endl;	
	return 0;
}