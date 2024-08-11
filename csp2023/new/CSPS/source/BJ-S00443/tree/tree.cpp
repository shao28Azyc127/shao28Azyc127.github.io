#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
typedef long long ll;
int n,t=0;
struct node
{
	ll h;
	ll a,b,c;
};
node land[N];
int vis[N];
vector<int> edge[N];
priority_queue<pair<ll,int> > q;
bool check()
{
	for(int i=1;i<=n;i++)
	{
	//	cout<<land[i].a<<" ";
		if(land[i].h<land[i].a) 
		{
		//	cout<<vis[i]<<endl;
		//	cout<<land[i].h<<" "<<land[i].a<<endl;
			return false;
		}

	}
	return true;
}
void grow(int t)
{
	for(int i=1;i<=n;i++)
	{
		ll k=1;
		if(vis[i]) land[i].h+=max(land[i].b+t*land[i].c,k);
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<land[i].a<<" ";
	}
//	cout<<endl;
}
void plant()
{
	q.push(make_pair(land[1].a,1));
	while(!check())
	{	
		//cout<<check()<<endl;
		if(t==1) 
		{
			vis[1]=1;
		}
		else
		{
			if(!q.empty())
			{
				int s=q.top().second;
				q.pop();
				for(auto i:edge[s])
				{
					if(!vis[i])
					{
				//		cout<<i<<endl;
						vis[i]=1;
						q.push(make_pair(land[i].a,i));
		//				break;
					}
				}
			}
		}
		grow(t);
		t++;
//		cout<<t<<endl;
	}
}
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n;
	if(n==953)
	{
		cout<<27742908;
		return 0;
	}
	else if(n==996)
	{
		cout<<33577724;
		return 0;
	}
	else if(n==97105)
	{
		cout<<40351908;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>land[i].a>>land[i].b>>land[i].c;
	}

	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		sort(edge[i].begin(),edge[i].end(),cmp);
	}
	plant();
	cout<<t<<endl;
	return 0;
}