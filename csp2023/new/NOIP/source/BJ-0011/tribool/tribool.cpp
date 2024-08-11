#include<iostream>
#include<vector>
using namespace std;
int Task,T,n,m,f[100010],num;
vector<pair<int,bool> > e[100010];
bool mark[100010],flag;
void dfs(int now)
{
	mark[now]=1,num++;
	for(int i=0;i<e[now].size();i++)
	{
		int t=e[now][i].first;
		bool v=e[now][i].second;
		if(mark[t])
		{
			flag&=((f[t]<0&&f[now]<0)||f[t]==(f[now]^v));
			continue;
		}
		f[t]=f[now]^v,dfs(t);
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>Task>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			f[i]=i<<1;
			mark[i]=0;
			e[i].clear();
		}
		while(m--)
		{
			char op;
			int x;
			cin>>op>>x;
			if(op=='+'||op=='-')
			{
				int y;
				cin>>y;
				f[x]=f[y]^(op=='-');
			}
			else
			{
				f[x]=(op=='U')?-1:(op=='T');
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]>=2)
			{
				e[i].push_back({f[i]>>1,f[i]&1});
				e[f[i]>>1].push_back({i,f[i]&1});
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]>=2||mark[i])
			{
				continue;
			}
			dfs(i);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!mark[i])
			{
				f[i]=0,num=0,flag=1,dfs(i);
				ans+=flag?0:num;
			}
			ans+=(f[i]<0);
		}
		cout<<ans<<endl;
	}
	return 0;
}