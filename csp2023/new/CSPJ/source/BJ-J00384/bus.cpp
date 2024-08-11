#include <iostream>
#include <vector>

// #define debug

using namespace std;

const int N=1e4+1,INF=1e9;
vector<int> nei[N],ti[N];
int n,m,k,res=INF;

void dfs(int cur,int t)
{
	#ifdef debug
	for(int i=1;i<=t;i++)
	{
		cout<<"  ";
	}
	cout<<cur<<" "<<t<<endl;
	#endif

	if(cur==n)
	{
		if(t%k==0)
		{
			res=min(res,t);
		}
		return ;
	}

	for(int i=0;i<nei[cur].size();i++)
	{
		int to=nei[cur][i];
		if(ti[cur][i]<=t)
		{
			dfs(to,t+1);
		}
	}
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);

	cin>>n>>m>>k;

	int maxa=0;
	while(m--)
	{
		int u,v,a;
		cin>>u>>v>>a;

		maxa=max(maxa,a);
		#ifdef debug
		cout<<maxa<<endl;
		#endif
		nei[u].push_back(v);
		ti[u].push_back(a);
	}

	#ifdef debug
	cout<<maxa<<" "<<k<<endl;
	#endif
	for(int i=0;i<=maxa+k;i+=k)
	{
		#ifdef debug
		cout<<"#Begin"<<" "<<i<<endl;
		#endif
		dfs(1,i);
		#ifdef debug
		cout<<endl<<endl;
		#endif
	}

	if(res!=INF)
	{
		cout<<res<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}

	return 0;
}