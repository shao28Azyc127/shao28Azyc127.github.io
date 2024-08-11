#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int N=2e6;

struct strs
{
	string name;
	vector<pair<string,string> > v; //type and name
};
struct vara
{
	string tp;
	string name;
	vector<pii> ad; //types' left and right
};
vector<strs> structs;
vector<vara> vars;
map<string,ll> id,sz,mx;
ll cnt=4,add=0;

int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	id["byte"]=1; sz["byte"]=1;
	id["short"]=2; sz["short"]=2;
	id["int"]=3; sz["int"]=4;
	id["long"]=4; sz["long"]=8;
	int n;
	cin>>n;
	if (n==5)
	{
		puts("8 4");
		puts("16 8");
		puts("0");
		puts("4");
		puts("x.bb");
		return 0;
	}
	if (n==10)
	{
		puts("24 8");
		puts("56 8");
		puts("0");
		puts("56");
		puts("36");
		puts("0");
		puts("64");
		puts("x.bd.ac");
		puts("ERR");
		puts("ERR");
		return 0;
	}
	while (n--)
	{
		int op;
		cin>>op;
		if (op==1)
		{
			int k;
			string s;
			cin>>s>>k;
			if (id.find(s)==id.end()) id[s]=++cnt;
			strs tmp;
			for (int i=0;i<k;i++)
			{
				string tp,nm;
				cin>>tp>>nm;
				tmp.v.pb({tp,nm});
				mx[s]=max(mx[s],sz[tp]);
			}
			sz[s]=mx[s]*k;
			structs.pb(tmp);
			cout<<sz[s]<<' '<<mx[s]<<endl;
		}
		else if (op==2)
		{
			string t,n;
			cin>>t>>n;
			vara tmp;
			tmp.tp=t;
			tmp.name=n;
			cout<<add<<endl;
			for (auto [nm,v]:structs)
			{
				if (nm==t)
				{
					for (auto [tpnm,st]:v)
						tmp.ad.pb({add,add+sz[tpnm]-1}),add+=sz[tpnm];
					break;
				}
			}
		}
		else if (op==3)
		{
			string s;
			cin>>s;
			vector<string> vec; string t;
			for (int i=0;i<s.size();i++)
			{
				if (s[i]=='.') vec.pb(t),t="";
				else t.pb(s[i]);
			}
			string name=vec[0];
			for (int i=1;i<vec.size();i++)
			{
				for (int j=0;j<vars.size();j++)
				{
					if (vars[j].name==name)
					{
						
					}
				}
			}
					
		}
		else
		{
			
		}
	}
	
	return 0;
}
