#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
struct qwq
{
	int bg,tp;
	string nm;
};
int dyq[1005]={0,1,2,4,8};//duiqiyaoqiu=dyq
int sz[1005]={0,1,2,4,8};
string NAME[1005]={"","byte","short","int","long"};
vector<qwq> a[100005];
map<string,int> mp;
signed main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp["byte"]=1;
	mp["short"]=2;
	mp["int"]=3;
	mp["long"]=4;
	int nw=5;
	int T;
	cin >> T;
	while(T--)
	{
		int op;
		cin >> op;
		if(op==1)
		{
			string s;
			cin >> s;
			int k;
			cin >> k;
			mp[s]=++nw;
			vector<pair<int,string> > v;
			int mx=1;
			for(int i=1;i<=k;i++)
			{
				string x,y;
				cin >> x >> y;
				v.push_back({mp[x],y});
				mx=max(mx,dyq[mp[x]]);
			}
			int x=0;
			//cerr << mx << "?" << "\n";
			for(int i=0;i<k;i++)
			{
				while(x%dyq[v[i].first]!=0) ++x;
				a[nw].push_back({x,v[i].first,v[i].second});
				x+=sz[v[i].first];
			//	cerr << x << "??\n";
			}
			while(x%mx!=0) ++x;
			sz[nw]=x;
			dyq[nw]=mx;
			cout << x << " " << mx << "\n";
		}
		if(op==2)
		{
			string x,y;
			cin >> x >> y;
			while(sz[5]%dyq[mp[x]]!=0) ++sz[5];
			cout << sz[5] << "\n";
			a[5].push_back({sz[5],mp[x],y});
			sz[5]+=sz[mp[x]];
		}
		if(op==3)
		{
			string s;
			cin >> s;
			vector<string> v;
			s+='.';
			string t;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='.')
				{
					v.push_back(t);
					t="";
				}
				else t+=s[i];
			}
			int ans=0,nw=5;
			for(auto t:v)
			{
				for(auto k:a[nw])
				{
					if(k.nm==t)
					{
						ans+=k.bg;
					//	cerr << k.nm << " " << k.tp << " " << ans << "???\n";
						nw=k.tp;
						break;
					}
				}
			}
			cout << ans << "\n";
		}
		if(op==4)
		{
			int x;
			cin >> x;
			int nw=5;
			string ans="";
			while(1)
			{
				int flag=0;
				for(auto k:a[nw])
				{
					if(k.bg<=x&&sz[k.tp]+k.bg>x)
					{
						flag=1;
						ans+="."+k.nm;
						nw=k.tp,x-=k.bg;
						break;
					}
				}
				if(!flag)
				{
					ans=".ERR";
					break;
				}
				if(nw<=4)
				{
					if(x<sz[nw]);
					else ans=".ERR";
					break;
				}
			}
			cout << ans.substr(1) << "\n";
		}
	}
	return 0;
}