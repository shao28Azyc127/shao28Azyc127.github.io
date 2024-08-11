#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<utility>
#include<set>
using namespace std;

typedef pair<int,int> pii;
string s;
int n;
bool vis[40001][40001];
set<pii> m;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>s;
	if(n<=40000)
	{
		int ans=0;
		queue<pii> q;
		s="_"+s+"-";
		for(int i=1;i<=n;i++)
		{
			int ni=i+1;
			while(s[ni]==s[i])
				{if((ni-i)%2!=0) {q.push(make_pair(i,ni)); vis[i][ni]=1;} ni++;}
		//	cout<<ni<<endl;
		}
		while(!q.empty())
		{
		//	cout<<q.size()<<endl;
			pii t=q.front(); q.pop();
			ans++;
			int b=t.first,e=t.second;
			if(b-1<0&&e+1==n) continue;
			if(s[b-1]==s[b]&&s[e]==s[e+1]) continue;
			if(s[b-1]==s[e+1])
				if(!vis[b-1][e+1])
					{q.push(make_pair(b-1,e+1)); vis[b-1][e+1]=1;}
			if(s[b-1]!=s[b])
			{
				for(int i=1;i<b;i++)
					if(vis[i][b-1]&&!vis[i][e])
						{q.push(make_pair(i,e)); vis[i][e]=1;}
			}
			if(s[e+1]!=s[e])
			{
				for(int i=e+1;i<=n;i++)
					if(vis[e+1][i]&&!vis[b][i])
						{q.push(make_pair(b,i)); vis[b][i]=1;}
			}
		}
		cout<<ans;
	}
	else
	{
		int ans=0;
		queue<pii> q;
		s="_"+s+"-";
		for(int i=1;i<=n;i++)
		{
			int ni=i+1;
			while(s[ni]==s[i])
				{if((ni-i)%2!=0) {q.push(make_pair(i,ni)); m.insert(make_pair(i,ni));} ni++;}
		//	cout<<ni<<endl;
		}
		while(!q.empty())
		{
		//	cout<<q.size()<<endl;
			pii t=q.front(); q.pop();
			ans++;
			int b=t.first,e=t.second;
			if(b-1<0&&e+1==n) continue;
			if(s[b-1]==s[b]&&s[e]==s[e+1]) continue;
			if(s[b-1]==s[e+1])
				if(!m.count(make_pair(b-1,e+1)))
					{q.push(make_pair(b-1,e+1)); m.insert(make_pair(b-1,e+1));}
			if(s[b-1]!=s[b])
			{
				for(int i=1;i<b;i++)
					if(m.count(make_pair(i,b-1))&&!m.count(make_pair(i,e)))
						{q.push(make_pair(i,e)); m.insert(make_pair(i,e));}
			}
			if(s[e+1]!=s[e])
			{
				for(int i=e+1;i<=n;i++)
					if(m.count(make_pair(e+1,i))&&!m.count(make_pair(b,i)))
						{q.push(make_pair(b,i)); m.insert(make_pair(b,i));}
			}
		}
		cout<<ans;
	}
	return 0;
}
