#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
//for a struct
vector<pair<int,string> > v[110];
//type, name

map<string,int> pos;//trans type into number
map<int,string> tra;//trans number into typename
map<string,pii> add;//change name into address
struct str{
	int sz,mx;
}s[110];int cnt=4;
vector<int> son[110];
signed main()
{
	ios::sync_with_stdio(false);
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n;cin>>n;
	//1:byte  2:short  3:int  4:long
	s[1].sz=s[1].mx=1;pos["byte"]=1;
	s[2].sz=s[2].mx=2;pos["short"]=2;
	s[3].sz=s[3].mx=4;pos["int"]=3;
	s[4].sz=s[4].mx=8;pos["long"]=4;
	int addr=0;
	for(int i=1;i<=n;i++)
	{
		int op;cin>>op;
		if(op==1)
		{
			string sss;
			cin>>sss;
			int k;cin>>k;
			cnt++;
			s[cnt].mx=0;
			s[cnt].sz=0;
			pos[sss]=cnt;
			int now=0;//now address
			for(int j=1;j<=k;j++)
			{
				string a,b;
				cin>>a>>b;
				int sz=s[pos[a]].sz,mx=s[pos[a]].mx;
				s[cnt].mx=max(s[cnt].mx,mx);
				now=(now+mx-1)/mx*mx;
				now+=sz;
				v[cnt].pb(mp(pos[a],b));
			}
			int lim=(now+s[cnt].mx-1)/s[cnt].mx*s[cnt].mx;
			s[cnt].sz=lim;
			cout<<s[cnt].sz<<" "<<s[cnt].mx<<"\n";
		}
		else if(op==2)
		{
			string a,b;
			cin>>a>>b;
			int mx=0,sz=0,p=pos[a];
			mx=s[p].mx,sz=s[p].sz;
			addr=(addr+mx-1)/mx*mx;
			cout<<addr<<'\n';
			if(p>4)
			{
				int now=addr;
				for(auto x:v[p])
				{
					auto type=x.fi;
					auto nm=x.se;
					int sz=s[type].sz,mx=s[type].mx;
					now=(now+mx-1)/mx*mx;
					string name=b+"."+nm;
					add[name]=mp(now,now+sz-1);
					now+=sz;
				}
			}
			else
			{
				int now=addr;
				int sz=s[pos[a]].sz,mx=s[pos[a]].mx;
				now=(now+mx-1)/mx*mx;
				string name=b;
				add[name]=mp(now,now+sz-1);
				now+=sz;
			}
			addr+=sz;
		}
		if(op==3)
		{
			string s;
			cin>>s;
			cout<<add[s].fi<<"\n";
		}
		if(op==4)
		{
			int ss=0;cin>>ss;
			bool flag=0;
			for(auto x:add)if(x.se.fi<=ss&&x.se.se>=ss){flag=1;cout<<x.fi<<'\n';break;}
			if(!flag)cout<<"ERR\n";
		}
	}
	return 0;
}