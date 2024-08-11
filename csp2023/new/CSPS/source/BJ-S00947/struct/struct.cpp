#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
typedef long long ll;
const int N=120;
struct Node
{
	std::string name,ch[N];
	int id[N],c;
	ll pos[N],sz,mx;
}a[N];
std::string var[N];
int loc[N],cnt1,cnt2;
ll pos[N];
inline int Find(std::string &s)
{
	for(int i=1;i<=cnt1;++i) if(a[i].name==s) return i;
	return 0;
}
inline std::vector<std::string> split_str(std::string &s)
{
	std::string cur;
	std::vector<std::string> res;
	for(int i=0;i<int(s.size());++i)
		if(s[i]=='.'){if(cur.size()) res.emplace_back(cur),cur="";}
		else cur+=s[i];
	if(cur.size()) res.emplace_back(cur);
	return res;
}
std::string A;
bool Z;
void dfs(int u,ll p)
{
	if(u<=4){Z=true;return ;}
	for(int i=1;i<=a[u].c;++i) if(a[u].pos[i]<=p&&p<a[u].pos[i]+a[a[u].id[i]].sz){A+=a[u].ch[i]+".",dfs(a[u].id[i],p-a[u].pos[i]);break;}
}
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int T;
	std::cin>>T;
	a[1].sz=a[1].mx=1,a[1].name="byte",a[2].sz=a[2].mx=2,a[2].name="short",a[3].sz=a[3].mx=4,a[3].name="int",a[4].sz=a[4].mx=8,a[4].name="long",cnt1=4;
	ll cur=0;
	while(T--)
	{
		int opt;
		std::cin>>opt;
		std::string tp,q;
		if(opt==1)
		{
			++cnt1;
			std::cin>>a[cnt1].name>>a[cnt1].c;
			ll z=0;
			a[cnt1].mx=0;
			for(int i=1;i<=a[cnt1].c;++i)
			{
				std::cin>>tp>>a[cnt1].ch[i];
				int &x=a[cnt1].id[i];
				x=Find(tp);
				a[cnt1].mx=std::max(a[cnt1].mx,a[x].mx);
			}
			for(int i=1;i<=a[cnt1].c;++i)
			{
				ll cur=a[a[cnt1].id[i]].mx;
				a[cnt1].sz+=(cur-a[cnt1].sz%cur)%cur;
				a[cnt1].pos[i]=a[cnt1].sz,a[cnt1].sz+=a[a[cnt1].id[i]].sz;
			}
			a[cnt1].sz+=(a[cnt1].mx-a[cnt1].sz%a[cnt1].mx)%a[cnt1].mx;
			std::cout<<a[cnt1].sz<<" "<<a[cnt1].mx<<"\n";
		}
		else if(opt==2)
		{
			++cnt2;
			std::cin>>tp>>var[cnt2];
			int &x=loc[cnt2];
			x=Find(tp);
			cur+=(cur-cur%a[x].mx)%a[x].mx;
			pos[cnt2]=cur,cur+=a[x].sz;
			std::cout<<pos[cnt2]<<"\n";
		}
		else if(opt==3)
		{
			std::cin>>q;
			auto r=split_str(q);
			int x=0;
			for(int i=1;i<=cnt2;++i) if(var[i]==r[0]) x=i;
			int u=loc[x];
			ll ans=pos[x];
			for(int i=1;i<int(r.size());++i)
			{
				int nxt=0;
				for(int j=1;j<=a[u].c;++j) if(a[u].ch[j]==r[i]) nxt=j;
				ans+=a[u].pos[nxt],u=a[u].id[nxt];
			}
			std::cout<<ans<<"\n";
		}
		else if(opt==4)
		{
			ll w=0;
			std::cin>>w;
			for(int i=1;i<=cnt2;++i) if(pos[i]<=w&&w<pos[i]+a[loc[i]].sz){A=var[i]+".",Z=false,dfs(loc[i],w-pos[i]);break;}
			if(!Z) std::cout<<"ERR\n";
			else std::cout<<A.substr(0,int(A.size())-1)<<"\n";
		}
	}
	return 0;
}