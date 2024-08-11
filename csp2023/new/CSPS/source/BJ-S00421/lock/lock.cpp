#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int N=114514;

ll a[10][10],n;
inline int chk(int aa,int b,int c,int d,int e)
{
	int t[10]={0,aa,b,c,d,e};
	vector<int> eq(10,0);
	for (int i=1;i<=n;i++) //t&a[i]
	{
		int cnt=0;
		for (int j=1;j<=5;j++)
			eq[j]=(t[j]==a[i][j]);
		for (int j=1;j<=5;j++)
			cnt+=eq[j];
		if (cnt==5||cnt<3) return 0;
		if (cnt==3)
		{
			int ok=0;
			for (int j=1;j<5;j++)
			{
				if (!eq[j]&&!eq[j+1])
				{
					int u=t[j],v=t[j+1];
					int x=a[i][j],y=a[i][j+1];
					//u->x,v->y
					if (u<x&&(v+x-u+10)%10==y) ok=1;
					if (u>x&&(v-u+x+10)%10==y) ok=1;
				}
			}
			if (!ok) return 0;
		}
	}
	return 1;
}

int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=5;j++) cin>>a[i][j];
	ll ans=0;
	for (int aa=0;aa<10;aa++)
	{
		for (int b=0;b<10;b++)
		{
			for (int c=0;c<10;c++)
			{
				for (int d=0;d<10;d++)
				{
					for (int e=0;e<10;e++) //10^5
					ans+=chk(aa,b,c,d,e);
				}
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
