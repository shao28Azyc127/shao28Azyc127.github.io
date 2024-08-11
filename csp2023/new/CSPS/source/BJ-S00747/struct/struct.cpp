#include<bits/stdc++.h>
#define fs first
#define sc second
#define mp make_pair
#define endl '\n'
#define tomax(x,y) x=max((x),(y));
using namespace std;
typedef string str;
typedef long long ll;
typedef pair<str,str> pss;
namespace solve
{
	struct var
	{
		str tp;
		ll adr;
		bool operator<(const var other) const
		{
			return adr<other.adr;
		}
	};
	typedef pair<str,var> psv;
	typedef pair<var,str> pvs;
	struct typ
	{
		ll sz,ax;
		map<str,var> dy;
		set<pvs> sdy;
	};
	map<str,typ> tps;
	map<str,var> va;
	set<pvs> sva;
	ll ladr;
	void init()
	{
		tps.insert(mp(str("byte"),(typ){1,1,map<str,var>(),set<pvs>()}));
		tps.insert(mp(str("short"),(typ){2,2,map<str,var>(),set<pvs>()}));
		tps.insert(mp(str("int"),(typ){4,4,map<str,var>(),set<pvs>()}));
		tps.insert(mp(str("long"),(typ){8,8,map<str,var>(),set<pvs>()}));
	}
	void def(str name,vector<pss> con)
	{
		ll x=0,ca=0;
		map<str,var> bl;
		set<pvs> bls;
		for(pss i:con)
		{
			typ cur=tps[i.fs];
			bl.insert(mp(i.sc,(var){i.fs,((ca%cur.ax==0)?ca:((ca/cur.ax+1)*cur.ax))}));
			//cout<<"definsert: "<<" "<<ca<<" "<<i.sc<<" "<<((ca%cur.ax==0)?ca:((ca/cur.ax+1)*cur.ax))<<endl;
			bls.insert(mp((var){i.fs,((ca%cur.ax==0)?ca:((ca/cur.ax+1)*cur.ax))},i.sc));
			ca=((ca%cur.ax==0)?ca:(ca/cur.ax+1)*cur.ax)+cur.sz;
			tomax(x,cur.ax);
		}
		tps.insert(mp(name,(typ){((ca%x==0)?ca:((ca/x+1)*x)),x,bl,bls}));
		cout<<((ca%x==0)?ca:((ca/x+1)*x))<<' '<<x<<endl;
	}//-fsanitize=undefined,address
	void decl(pss d)
	{
		typ cur=tps[d.fs];
		va.insert(mp(d.sc,(var){d.fs,((ladr%cur.ax==0)?ladr:((ladr/cur.ax+1)*cur.ax))}));
		sva.insert(mp((var){d.fs,((ladr%cur.ax==0)?ladr:((ladr/cur.ax+1)*cur.ax))},d.sc));
		cout<<((ladr%cur.ax==0)?ladr:((ladr/cur.ax+1)*cur.ax))<<endl;
		ladr=((ladr%cur.ax==0)?ladr:((ladr/cur.ax+1)*cur.ax))+cur.sz;
	}
	void show_variables()
	{
		for(psv vr:va)
		{
			cerr<<"==========\nType: "<<vr.sc.tp<<"\nName: "<<vr.fs<<"\nAddress: "<<vr.sc.adr<<endl;
		}
	}
	ll subaddr(var fa,string lft)
	{
		//cout<<"subabbr("<<lft<<");"<<endl;
		typ fat=tps[fa.tp];
		for(int i=0;i<lft.size();++i)
		{
			if(lft[i]=='.')
			{
				var f=fat.dy[lft.substr(0,i)];
				//cerr<<"=====f====\nType: "<<f.tp<<"\nAddress: "<<f.adr<<endl;
				return f.adr+subaddr(f,lft.substr(i+1,lft.size()-i-1));
			}
		}
		//cout<<fat.dy[lft].adr<<endl;
		return fat.dy[lft].adr;
	}
	ll addr(string varr)
	{
		//cout<<"addr: "<<varr<<endl;
		for(int i=0;i<varr.size();++i)
		{
			if(varr[i]=='.')
			{
				var f=va[varr.substr(0,i)];
				//cout<<varr.substr(i+1,varr.size()-i-1)<<endl;
				return f.adr+subaddr(f,varr.substr(i+1,varr.size()-i-1));
			}
		}
		return va[varr].adr;
	}
	str svarname(typ tttp,ll addrr)
	{
		auto res=tttp.sdy.upper_bound(mp((var){str("\0"),addrr},str("zzzzzzzzzzz")));
		res--;
		typ ttp=tps[res->fs.tp];
		if(ttp.sdy.size()==0)
		{
			if(res->fs.adr>addrr||(res->fs.adr+ttp.sz)<addrr) return str("ERR");
			return res->sc;
		}
		else
		{
			string svnm=svarname(ttp,addrr-(res->fs.adr));
			if(svnm=="ERR") return svnm;
			return ((res->sc+".")+svnm);
		}
	}
	str varname(ll addrr)
	{
		if(sva.size()==0) return str("ERR");
		auto res=sva.upper_bound(mp((var){str("\0"),addrr},str("zzzzzzzzzzz")));
		res--;
		typ ttp=tps[res->fs.tp];
		if(ttp.sdy.size()==0)
		{
			if(res->fs.adr>addrr||(res->fs.adr+ttp.sz)<addrr) return str("ERR");
			return res->sc;
		}
		else
		{
			string svnm=svarname(ttp,addrr-(res->fs.adr));
			if(svnm=="ERR") return svnm;
			return ((res->sc+".")+svnm);
		}
	}
	void main()
	{
		init();
		int n;
		cin>>n;
		int op;
		while(n--)
		{
			//cout<<"???input:::"<<endl;
			cin>>op;
			if(op==1)
			{
				string s;
				vector<pss> vas;
				int k;
				cin>>s>>k;
				for(int i=1;i<=k;++i)
				{
					string tpn,nm;
					cin>>tpn>>nm;
					vas.push_back(mp(tpn,nm));
				}
				def(s,vas);
			}
			else if(op==2)
			{
				string tpn,nm;
				cin>>tpn>>nm;
				decl(mp(tpn,nm));
			}
			else if(op==3)
			{
				string test;
				cin>>test;
				cout<<addr(test)<<endl;
			}
			else
			{
				ll addrr;
				cin>>addrr;
				cout<<varname(addrr)<<endl;
			}
			//cout<<n<<endl;
			//show_variables();
		}
		
	}
}
int main()
{
	//("struct.in","r",stdin);
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve::main();
	return 0;
}
