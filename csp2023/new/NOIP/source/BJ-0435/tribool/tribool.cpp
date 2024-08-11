#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int NT=6e4;
struct str{
	char v;
	int x,y;
}strt;
int a[N];//0:F 1:T 2:U
vector<vector<int> >vec;
vector<int> nt;
vector<str> ins;
bool Same(int ni)
{
	for(int i=0;i<vec[ni].size();i++)
		if(vec[ni][i]!=nt[i])
			return 0;
	return 1;
}
int C(int n)
{
	int ans=1;
	for(int i=1;i<=n;i++)
		ans*=3;
	return ans;
}
void Mkv(int n)
{
	for(int i=0;i<C(n);i++)
	{
		int it=i;
		for(int j=0;j<n;j++)
		{
			nt.push_back(it%3);
			it/=3;
		}
		vec.push_back(nt);
		nt.clear();
	}
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	char v;
	int c,t,n,m,x,y,ans,cnt;
	cin>>c>>t;
	if(c==3||c==4)
	{	
		for(int i=1;i<=t;i++)
		{
			memset(a,0,sizeof(a));
			ans=0;
			cin>>n>>m;
			for(int j=1;j<=m;j++)
			{
				cin>>v>>x;
				if(v=='T')
					a[x]=1;
				else if(v=='F')
					a[x]=0;
				else
					a[x]=2;
			}
			for(int j=1;j<=n;j++)
				if(a[j]==2)
					ans++;
			cout<<ans<<endl;
		}
	}
	else if(c==1||c==2)
	{
		for(int i=1;i<=t;i++)
		{
			vec.clear();
			ins.clear();
			ans=INT_MAX;
			cin>>n>>m;
			for(int j=1;j<=m;j++)
			{
				cin>>strt.v;
				if(strt.v=='T'||strt.v=='F'||strt.v=='U')
				{
					cin>>strt.x;
					strt.y=0;
					ins.push_back(strt);
				}
				else
				{
					cin>>strt.x>>strt.y;
					ins.push_back(strt);
				}
			}
			Mkv(n);
			for(int k=0;k<vec.size();k++)
			{
				cnt=0;
				for(int j=0;j<vec[k].size();j++)
					nt[j]=vec[k][j];
				for(int j=0;j<ins.size();j++)
				{
					if(ins[j].v=='T')
						vec[k][ins[j].x-1]=1;
					else if(ins[j].v=='F')
						vec[k][ins[j].x-1]=0;
					else if(ins[j].v=='U')
						vec[k][ins[j].x-1]=2;
					else if(ins[j].v=='+')
						vec[k][ins[j].x-1]=vec[k][ins[j].y-1];
					else if(vec[k][ins[j].y-1]!='U')
						vec[k][ins[j].x-1]=vec[k][ins[j].y-1]^1;
				}
				if(!Same(k))
					continue;
				for(int j=0;j<vec[k].size();j++)
					if(vec[k][j]=='U')
						cnt++;
				ans=min(cnt,ans);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}