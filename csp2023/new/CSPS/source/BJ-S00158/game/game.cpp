#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;
char c[N];
bool vis[N];
struct node
{
	int pre,nxt;
}ll[N];
bool check(int l,int r)
{
	//cout<<l<<" "<<r<<endl;
	if ((r-l+1)%2!=0) return false;
	memset(vis,0,sizeof(vis));
	bool flg=false;
	int cnt=0;
	while (cnt<n)
	{
		flg=false;
		for (int i=l;i<=r;i++)
		{
			if (vis[i]) continue;
			if (ll[i].nxt>r) continue;
			if (c[i]==c[ll[i].nxt])
			{
				//cout<<"  "<<i<<" "<<ll[i].nxt<<endl;
				vis[i]=true;
				vis[ll[i].nxt]=true;
				ll[ll[i].pre].nxt=ll[ll[i].nxt].nxt;
				ll[ll[ll[i].nxt].nxt].pre=ll[i].pre;
				ll[i].pre=ll[i].nxt=ll[ll[i].nxt].nxt=ll[ll[i].nxt].pre=0;
				flg=true;
				cnt+=2;
			}
		}
		if (!flg) break;
	}
	for (int i=1;i<=n;i++)
	{
		ll[i].pre=i-1;
		ll[i].nxt=i+1;
	}
	return cnt==r-l+1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long ans=0;
	cin>>n;
	cin>>(c+1);
	for (int i=1;i<=n;i++)
	{
		ll[i].pre=i-1;
		ll[i].nxt=i+1;
	}
	for (int l=1;l<=n;l++)
	{
		for (int r=l+1;r<=n;r++)
		{
			if (check(l,r))
			{
				//for (int i=l;i<=r;i++) cout<<c[i];
				//cout<<endl;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}