#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<pair<int ,int > > v[N];
int ans,k,n;
void fans()
{
	queue<pair<int,int> > q;
	q.push({1,k});
	while(!q.empty())
	{
		if(q.front().first==n&&q.front().second%k==0)
		{
			ans=q.front().second;
			return;
		}
		else if(q.front().first==n)
		{
			q.pop();
			continue;
		}
		for(int i=0;i<v[q.front().first].size();i++)
		{
			if(v[q.front().first][i].second<=q.front().second)
				q.push({v[q.front().first][i].first,q.front().second+1});
		}
		q.pop();
	}
	ans=-1;
	return;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int m;
	cin>>n>>m>>k;
	for(int i=1,be,en,ti;i<=m;i++)
	{
		cin>>be>>en>>ti;
		v[be].push_back({en,ti});
	}
	fans();
	cout<<ans<<endl;
	return 0;
}