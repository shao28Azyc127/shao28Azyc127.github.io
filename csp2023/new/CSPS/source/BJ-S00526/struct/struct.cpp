#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int P[2]={1000000007,998244353};
struct mint
{
	int x[2];
	mint(){x[0]=x[1]=0;}
	mint(int _x){x[0]=_x%P[0];x[1]=_x%P[1];}
	mint(int a,int b){x[0]=a;x[1]=b;}
};
mint operator+(mint a,mint b){return mint((a.x[0]+b.x[0])%P[0],(a.x[1]+b.x[1])%P[1]);}
mint operator-(mint a,mint b){return mint((a.x[0]+P[0]-b.x[0])%P[0],(a.x[1]+P[1]-b.x[1])%P[1]);}
mint operator*(mint a,mint b){return mint(1ll*a.x[0]*b.x[0]%P[0],1ll*a.x[1]*b.x[1]%P[1]);}
bool operator==(mint a,mint b){return a.x[0]==b.x[0]&&a.x[1]==b.x[1];}
bool operator<(mint a,mint b){if(a.x[0]==b.x[0])return a.x[1]<b.x[1];return a.x[0]<b.x[0];}
int n;
struct Struct
{
	map<mint,int> name;
	ll sid[111],off[111],siz,mx;
	string iname[111];
	int k;
}S[111];
map<mint,int> sname,mname;int sn;
ll msid[111],moff[111],msiz;string iname[111],trash;
int m;
char s[100011],t[100011];const mint B=27;
mint Hash(const char *s,string &S=trash)
{
	int tt=strlen(s);
	mint hsh=0;
	for(int i=0;i<tt;++i)hsh=hsh*B+s[i]-'a'+1,S+=s[i];
	trash.clear();
	return hsh;
}
ll Nxt(ll x,ll y){return x%y==0?x:x+y-x%y;}
vector<mint> v;
string ans;
void solve(int id,ll addr)
{//printf("solve(%d,%lld)\n",id,addr);
	if(1<=id&&id<=4){if(addr>=S[id].siz)ans.clear();return;}
	if(id==0)
	{
		if(addr>=msiz){ans.clear();return;}
		int I=m;
		for(int i=1;i<=m;++i)
		{
			if(moff[i]>addr){I=i-1;break;}
		}
		ans+=iname[I];ans+='.';
		solve(msid[I],addr-moff[I]);
	}
	else
	{
		if(addr>=S[id].siz){ans.clear();return;}
		int I=S[id].k;
		for(int i=1;i<=S[id].k;++i)
		{
			if(S[id].off[i]>addr){I=i-1;break;}
		}
		ans+=S[id].iname[I];ans+='.';
		solve(S[id].sid[I],addr-S[id].off[I]);
	}
}
int main()
{
	freopen("struct.in","r",stdin);freopen("struct.out","w",stdout);
	scanf("%d",&n);
	sn=4;
	string ts;
	ts="byte";sname[Hash(ts.c_str())]=1;S[1].siz=S[1].mx=1;
	ts="short";sname[Hash(ts.c_str())]=2;S[2].siz=S[2].mx=2;
	ts="int";sname[Hash(ts.c_str())]=3;S[3].siz=S[3].mx=4;
	ts="long";sname[Hash(ts.c_str())]=4;S[4].siz=S[4].mx=8;
	while(n--)
	{
		int op;scanf("%d",&op);
		if(op==1)
		{
			++sn;
			scanf("%s%d",s+1,&S[sn].k);
			sname[Hash(s+1)]=sn;
			for(int i=1;i<=S[sn].k;++i)
			{
				scanf("%s%s",s+1,t+1);
				mint hs=Hash(s+1),ht=Hash(t+1,S[sn].iname[i]);
				int is=sname[hs];
				S[sn].name[ht]=i;
				S[sn].sid[i]=is;
				S[sn].off[i]=Nxt(S[sn].off[i-1]+S[S[sn].sid[i-1]].siz,S[is].mx);
				S[sn].siz=S[sn].off[i]+S[is].siz;
				S[sn].mx=max(S[sn].mx,S[is].mx);
			}
			S[sn].siz=Nxt(S[sn].off[S[sn].k]+S[S[sn].sid[S[sn].k]].siz,S[sn].mx);
			printf("%lld %lld\n",S[sn].siz,S[sn].mx);
		}
		else if(op==2)
		{
			scanf("%s%s",s+1,t+1);
			mint hs=Hash(s+1),ht=Hash(t+1,iname[m+1]);
			mname[ht]=++m;
			int is=sname[hs];
			msid[m]=is;
			moff[m]=Nxt(moff[m-1]+S[msid[m-1]].siz,S[is].mx);
			msiz=moff[m]+S[is].siz;
			printf("%lld\n",moff[m]);
		}
		else if(op==3)
		{
			scanf("%s",s+1);int len=strlen(s+1);s[len+1]='.';
			ll addr=0;v.clear();
			mint hsh=0;
			for(int i=1;i<=len+1;++i)
			{
				if(s[i]=='.')v.push_back(hsh),hsh=0;
				else hsh=hsh*B+s[i]-'a'+1;
			}
			int aim=mname[v[0]],si=msid[aim];
			addr=moff[aim];
			for(int i=1;i<v.size();++i)
			{
				aim=S[si].name[v[i]];
				addr+=S[si].off[aim];si=S[si].sid[aim];
			}
			printf("%lld\n",addr);
		}
		else
		{
			ll addr;scanf("%lld",&addr);
			ans.clear();
			solve(0,addr);
			if(ans.size()==0){printf("ERR\n");continue;}
			ans.pop_back();
			printf("%s\n",ans.c_str());
		}
	}
	fclose(stdin);fclose(stdout);return 0;
}