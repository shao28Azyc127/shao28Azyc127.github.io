#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define pc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
const ll INF=1e9+7;
const ll LLINF=1e18+7;
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
inline ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
inline ll lowbit(ll x){return x&(-x);}
inline ll read()
{
	ll x=0,f=0;char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
inline void write(ll x){if(x<0){x=-x;pc('-');}if(x>9)write(x/10);pc(x%10+'0');}
const ll MAXN=207;
string st[]={"byte","short","int","long"};
ll leng[]={1,2,4,8};
ll n,a[MAXN],adr=0;
ll tpnum=0;
struct NODE
{
	ll x;
	string ty[MAXN];
	string name[MAXN];
	ll len,maxn;
}STR[MAXN];
map<string,ll>mp;
ll nodenum=0;
struct node
{
	string s;ll tp,adr;// adr   ÆðÊ¼µØÖ·
}b[MAXN];
vector<ll>ele;
map<string,ll>mp1;
string s,s1;
ll find(ll st)
{
	s1="";
	ll f=0;
	for(ll i=st;i<s.length();i++)
	{
		if(s[i]=='.')break;
		f=1;
		s1+=s[i];
	}
	return f;
}
bool check()
{
	for(ll i=0;i<4;i++)
	{
		ll f=1;
		for(ll j=0;j<st[i].length();j++)
			if(s1[j]!=st[i][j])f=0;
		if(f)return 1;
	}
	return 0;
}
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	n=read();
	STR[++tpnum].len=1;STR[tpnum].maxn=1;STR[1].x=0;
	mp["byte"]=1;
	STR[++tpnum].len=2;STR[tpnum].maxn=2;STR[1].x=0;
	mp["short"]=2;
	STR[++tpnum].len=4;STR[tpnum].maxn=4;STR[1].x=0;
	mp["int"]=3;
	STR[++tpnum].len=8;STR[tpnum].maxn=8;STR[1].x=0;
	mp["long"]=4;
	ele.push_back(-1);
	while(n--)
	{
		ll op=read();
		// cout<<op<<' ';
		if(op==1)
		{
			cin>>s;
			mp[s]=++tpnum;
			STR[tpnum].x=read();
			ll tmp1=0;
			for(ll i=0;i<STR[tpnum].x;i++)
			{
				cin>>STR[tpnum].ty[i]>>STR[tpnum].name[i];
				ll tmp=STR[mp[STR[tpnum].ty[i]]].maxn;
				if(tmp1%tmp)tmp1=(tmp1/tmp+1)*tmp;
				tmp1+=STR[mp[STR[tpnum].ty[i]]].len;
				// STR[tpnum].len+=STR[mp[STR[tpnum].ty[i]]].len;
				STR[tpnum].maxn=max(STR[tpnum].maxn,STR[mp[STR[tpnum].ty[i]]].maxn);
				// cout<<tmp1<<' ';
			}//puts("AWA");
			STR[tpnum].len=tmp1;
			if(STR[tpnum].len%STR[tpnum].maxn)STR[tpnum].len=(STR[tpnum].len/STR[tpnum].maxn+1)*STR[tpnum].maxn;
			cout<<STR[tpnum].len<<' '<<STR[tpnum].maxn<<'\n';
		}
		else if(op==2)
		{
			cin>>s>>s1;
			ll tmp=STR[mp[s]].maxn;
			if(adr%tmp)adr=(adr/tmp+1)*tmp;
			b[++nodenum].s=s1;b[nodenum].tp=mp[s];b[nodenum].adr=adr;adr+=STR[mp[s]].len;
			ele.push_back(nodenum);
			mp1[s1]=nodenum;
			cout<<b[nodenum].adr<<'\n';
		}
		else if(op==3)
		{
			cin>>s;find(0);ll las=s1.length()+1;
			ll x=mp1[s1];ll ans=b[x].adr;x=b[x].tp;
			ll tmp=find(las);
			las+=s1.length()+1;
			while(!check())
			{
				// cout<<s1<<' '<<x<<' '<<ans<<'\n';
				ll tmp=ans;
				for(ll i=0;i<STR[x].x;i++)
				{
					ll tmp1=STR[mp[STR[x].ty[i]]].maxn;
					if(tmp%tmp1)tmp=(tmp/tmp1+1)*tmp1;
					ans=tmp;
					if(s1==STR[x].name[i])
					{
						x=mp[STR[x].ty[i]];
						break;
					}
					tmp+=STR[mp[STR[x].ty[i]]].len;
					ans=tmp;
				}
				// pc(10);pc(10);
				ll fff=find(las);
				las+=s1.length()+1;
				// cout<<s1<<' '<<tmp<<'\n';
				if(!fff)break;
			}
			write(ans),pc(10);
		}
		else
		{
			ll A=read();
			ll x=-1;
			if(A<0||A>=adr)
			{
				puts("ERR");
				continue;
			}ll now=0;bool f=1;
			for(ll i=1;i<=nodenum;i++)
			{
				if(b[i].adr>A)
				{
					now=b[i-1].adr;
					x=i-1;
					if(b[i-1].adr+STR[b[i-1].tp].len-1<A)f=0;
					break;
				}
			}
			if(x==-1)x=nodenum;
			if(!f)
			{
				puts("ERR");
				continue;
			}
			// puts("AWA1111");
			// cout<<x<<'\n';
			// puts("AWA111");pc(10);
			string ans="";ans+=b[x].s;
			x=b[x].tp;
			// puts("?????");
			// cout<<x<<'\n';
			while(STR[x].x)
			{
				// cout<<x<<' '<<now<<'\n';
				bool flag=0;
				for(ll i=0;i<STR[x].x;i++)
				{
					// cout<<now<<' ';
					ll tmp=now;
					if(tmp%STR[mp[STR[x].ty[i]]].maxn)tmp=(tmp/STR[mp[STR[x].ty[i]]].maxn+1)*STR[mp[STR[x].ty[i]]].maxn;
					// if(now==30)
					// {
					// 	cout<<tmp<<' '<<STR[mp[STR[x].ty[i]]].len<<' ';
					// }
					now=tmp;
					now+=STR[mp[STR[x].ty[i]]].len;
					if(now>A)
					{
						
						// if(now==56)cout<<now<<' '<<A<<' '<<now-STR[mp[STR[x].ty[i]]].len<<' '<<f<<"LXY"<<'\n';
						now-=STR[mp[STR[x].ty[i]]].len;
						if(now>A)
						{
							f=0;
							break;
						}
						flag=1;
						// cout<<f;puts("AWA");
						ans+=".";ans+=STR[x].name[i];
						x=mp[STR[x].ty[i]];
						break;
					}
				}
				// pc(10);
				if(!flag)
				{
					f=0;break;
				}
			}
			if(!f)puts("ERR");
			else cout<<ans<<'\n';
		}
		// cout<<n<<'\n';
	}
	return 0;
}