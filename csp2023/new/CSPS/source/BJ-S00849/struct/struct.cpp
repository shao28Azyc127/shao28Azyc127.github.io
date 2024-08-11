#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=105;
struct strc
{
	string name,sonname[MAXN];
	int n,sz,dq,son[MAXN],st[MAXN];
}s[MAXN];
struct node
{
	int id,st,sz,dq;
	string name;
}a[MAXN];
int n1,n2,q,op,ed,x;
vector<string> ans;
map<string,int> mp;
string str,qr[MAXN];
void solve1()
{
	n1++;
	cin>>s[n1].name>>s[n1].n;
	int now=0;
	for(int i=1;i<=s[n1].n;i++)
	{
		cin>>str>>s[n1].sonname[i];
		int v=mp[str];
		s[n1].son[i]=v;
		s[n1].dq=max(s[n1].dq,s[v].dq);
		now+=(s[v].dq-now%s[v].dq)%s[v].dq;
		s[n1].st[i]=now,now+=s[v].sz;
	}
	now+=(s[n1].dq-now%s[n1].dq)%s[n1].dq;
	s[n1].sz=now,mp[s[n1].name]=n1;
	cout<<s[n1].sz<<' '<<s[n1].dq<<endl;
}
void solve2()
{
	cin>>str>>a[++n2].name;
	a[n2].id=mp[str],a[n2].sz=s[a[n2].id].sz,a[n2].dq=s[a[n2].id].dq;
	ed+=(a[n2].dq-ed%a[n2].dq)%a[n2].dq;
	a[n2].st=ed,ed+=a[n2].sz;
	cout<<a[n2].st<<endl;
}
void solve3()
{
	cin>>str;
	for(int i=1;i<=100;i++) qr[i]="";
	int N=1;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='.') N++;
		else qr[N]+=str[i];
	}
	int nowst,nowid;
	for(int i=1;i<=n2;i++)
	{
		if(a[i].name!=qr[1]) continue;
		nowst=a[i].st,nowid=a[i].id;
	}
	for(int i=2;i<=N;i++)
	{
		for(int j=1;j<=s[nowid].n;j++)
		{
			if(s[nowid].sonname[j]!=qr[i]) continue;
			nowst+=s[nowid].st[j],nowid=s[nowid].son[j];
			break;
		}
	}
	cout<<nowst<<endl;
}
bool find(int u,int wz)
{
	if(u<=4) return 1;
	for(int i=1;i<=s[u].n;i++)
	{
		if(s[u].st[i]<=wz&&s[u].st[i]+s[s[u].son[i]].sz>wz)
		{
			ans.push_back(s[u].sonname[i]);
			return find(s[u].son[i],wz-s[u].st[i]);
		}
	}
	return 0;
}
void solve4()
{
	cin>>x;
	ans.clear();
	for(int i=1;i<=n2;i++)
	{
		if(a[i].st<=x&&a[i].st+a[i].sz>x)
		{
			ans.push_back(a[i].name);
			if(find(a[i].id,x-a[i].st))
			{
				for(int i=0;i<ans.size();i++)
				{
					if(i) putchar('.');
					cout<<ans[i];
				}
				putchar('\n');
			}
			else puts("ERR");
			return;
		}
	}
	puts("ERR");
}
signed main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>q;
	n1=4;
	s[1].name="byte",s[1].n=0,s[1].sz=s[1].dq=1;
	s[2].name="short",s[2].n=0,s[2].sz=s[2].dq=2;
	s[3].name="int",s[3].n=0,s[3].sz=s[3].dq=4;
	s[4].name="long",s[4].n=0,s[4].sz=s[4].dq=8;
	for(int i=1;i<=n1;i++) mp[s[i].name]=i;
	while(q--)
	{
		cin>>op;
		if(op==1) solve1();
		if(op==2) solve2();
		if(op==3) solve3();
		if(op==4) solve4();
	}
	return 0;
}