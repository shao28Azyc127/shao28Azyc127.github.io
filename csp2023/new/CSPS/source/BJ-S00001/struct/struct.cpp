#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n;
int rt=1,p=1;
long long sz[N];
long long mmx[N];
map<string,int>mp,tt[N];
vector<pair<int,long long> >v[N];
vector<string>g[N];
string lst;
long long find(int u,long long x)
{
	if(u+sz[u]-1<x||x<0)
	{
		return -1;
	}
	if(v[u].size()==0)
	{
		if(u<=5&&u>1&&sz[u]-1>=x&&x>=0)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	int l=0,r=(v[u].size())-1;
	int as=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(v[u][mid].second<=x)
		{
			as=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	lst=g[u][as];
	long long tmp=find(v[v[u][as].first][0].first,x-v[u][as].second);
	if(tmp==-1)return -1;
	else return v[u][as].second+tmp;
}
void print(int u,long long x)
{
	if(v[u].size()==0)
	{
		return;
	}
	int l=0,r=(v[u].size())-1;
	int as=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(v[u][mid].second<=x)
		{
			as=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<g[u][as];
	if(v[v[v[u][as].first][0].first].size()!=0)
	{
		cout<<'.';
	}
	print(v[v[u][as].first][0].first,x-v[u][as].second);
}
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	mp["int"]=++p;
	sz[p]=4;
	mmx[p]=4;
	mp["long"]=++p;
	sz[p]=8;
	mmx[p]=8;
	mp["short"]=++p;
	sz[p]=2;
	mmx[p]=2;
	mp["byte"]=++p;
	sz[p]=1;
	mmx[p]=1;
	long long smm=0;
	while(n--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			string typ;
			int k;
			cin>>typ>>k;
			int u=++p;
			mp[typ]=u;
			long long sm=0;
			for(int i=1;i<=k;i++)
			{
				string t,name;
				cin>>t>>name;
				++p;
				sz[p]=sz[mp[t]];
				mmx[p]=mmx[mp[t]];
				mmx[u]=max(mmx[u],mmx[p]);
				v[p].push_back({mp[t],0});
				sm=(((sm+mmx[p]-1)/mmx[p]))*mmx[p];
				v[u].push_back({p,sm});
				g[u].push_back(name);
				tt[u][name]=(g[u].size()-1);
				sm+=sz[p];
				
			}
			sm=(sm+mmx[u]-1)/mmx[u]*mmx[u];

			sz[u]=sm;
			cout<<sz[u]<<' '<<mmx[u]<<'\n';
		}
		else if(op==2)
		{
			string t,name;
			cin>>t>>name;
			++p;
			sz[p]=sz[mp[t]];
			mmx[p]=mmx[mp[t]];
			v[p].push_back({mp[t],0});
			smm=(((smm+mmx[p]-1)/mmx[p]))*mmx[p];
			cout<<smm<<'\n';
			v[1].push_back({p,smm});
			g[1].push_back(name);
			tt[1][name]=(g[1].size()-1);
			smm+=sz[p];
			sz[1]=smm;
		}
		else if(op==3)
		{
			string tmp;
			cin>>tmp;
			string nm="";
			int u=1;
			long long ans=0;
			tmp=tmp+".";
			for(int i=0;i<tmp.length();i++)
			{
				if(tmp[i]=='.')
				{
					if(1)
					{
						int j=tt[u][nm];
						int vv=v[u][j].first;
						if(g[u][j]==nm)
						{
							//cout<<u<<' '<<v[u][j].first<<' '<<v[u][j].second<<' '<<nm<<"???\n";
							ans+=v[u][j].second;
							u=v[vv][0].first;
						}
					}
					nm="";
				}
				else
				{
					nm=nm+tmp[i];
				}
			}
			cout<<ans<<'\n';
		}
		else
		{
			long long tmp=0;
			cin>>tmp;
			
			if(tmp>=sz[1])
			{
				cout<<"ERR\n";
				continue;
			}
			long long ans=find(1,tmp);
			if(ans!=-1)
			{
				print(1,ans);
				cout<<'\n';
			}
			else cout<<"ERR\n";
		}
	}
}
