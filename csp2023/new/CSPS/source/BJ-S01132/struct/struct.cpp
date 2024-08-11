#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll lst=0;
struct node
{
	string name;
	int type;
	ll pos;
}t[10010];int tl=0;
struct st
{
	string name;
	node son[110];int m;
	ll mx,size;
}st[110];int sl=0;
void op1()
{
	sl++;
	cin>>st[sl].name;
	scanf("%d",&st[sl].m);
	st[sl].mx=-999;
	for(int i=1;i<=st[sl].m;i++)
	{
		string type;
		cin>>type>>st[sl].son[i].name;
		if(type=="byte") st[sl].son[i].type=-1,st[sl].mx=max(st[sl].mx,1ll);
		else if(type=="short") st[sl].son[i].type=-2,st[sl].mx=max(st[sl].mx,2ll);
		else if(type=="int") st[sl].son[i].type=-4,st[sl].mx=max(st[sl].mx,4ll);
		else if(type=="long") st[sl].son[i].type=-8,st[sl].mx=max(st[sl].mx,8ll);
		else
		{
			for(int j=1;j<=sl;j++)
			{
				if(st[j].name==type)
				{
					st[sl].son[i].type=j;
					st[sl].mx=max(st[sl].mx,st[j].mx);
					break;
				}
			}
		}
	}
	ll ed=0;
	for(int i=1;i<=st[sl].m;i++)
	{
		ll mx,size;
		if(st[sl].son[i].type<0) mx=size=-st[sl].son[i].type;
		else mx=st[st[sl].son[i].type].mx,size=st[st[sl].son[i].type].size;
		while(ed%mx!=0) ed++;
		st[sl].son[i].pos=ed; ed+=size;
	}
	while(ed%st[sl].mx!=0) ed++;
	st[sl].size=ed;
	printf("%lld %lld\n",st[sl].size,st[sl].mx);
}
void op2()
{
	tl++;
	string type;
	cin>>type>>t[tl].name;
	if(type=="byte") t[tl].type=-1;
	else if(type=="short") t[tl].type=-2;
	else if(type=="int") t[tl].type=-4;
	else if(type=="long") t[tl].type=-8;
	else
	{
		for(int j=1;j<=sl;j++)
		{
			if(st[j].name==type)
			{
				t[tl].type=j;
				break;
			}
		}
	}
	ll mx,size;
	if(t[tl].type<0) mx=size=-t[tl].type;
	else mx=st[t[tl].type].mx,size=st[t[tl].type].size;
	while(lst%mx!=0) lst++;
	t[tl].pos=lst; lst+=size;
	printf("%lld\n",t[tl].pos);
}
string re;
bool eq(int l,int r,string s)
{
	int len=s.length();
	if(len!=r-l+1) return 0;
	for(int i=0;i<len;i++) if(s[i]!=re[l+i]) return 0;
	return 1;
}
void op3()
{
	cin>>re;
	int len=re.length();
	int le=0;
	bool flag=0;
	ll ans;
	int p;
	re[len]='.';
	for(int i=0;i<=len;i++)
	{
		if(re[i]=='.')
		{
			if(!flag)
			{
				for(int j=1;j<=tl;j++)
				{
					if(eq(le,i-1,t[j].name))
					{
						ans=t[j].pos;
						p=t[j].type;
						flag=1;
						break;
					}
				}
			}
			else
			{
				for(int j=1;j<=st[p].m;j++)
				{
					if(eq(le,i-1,st[p].son[j].name))
					{
						ans+=st[p].son[j].pos;
						p=st[p].son[j].type;
						break;
					}
				}
			}
			le=i+1;
		}
	}
	printf("%lld\n",ans);
}
string as[110];int asl;
void op4()
{
	asl=0;
	ll m;
	scanf("%lld",&m);
	int p;
	for(int i=1;i<=tl+1;i++)
	{
		if(i>tl||m<t[i].pos)
		{
			as[++asl]=t[i-1].name;
			m-=t[i-1].pos;
			p=t[i-1].type;
			break;
		}
	}
	while(p>0)
	{
		for(int j=1;j<=st[p].m+1;j++)
		{
			if(j>st[p].m||m<st[p].son[j].pos)
			{
				as[++asl]=st[p].son[j-1].name;
				m-=st[p].son[j-1].pos;
				p=st[p].son[j-1].type;
				break;
			}
		}
	}
	p=-p;
	if(m>=p) printf("ERR\n");
	else
	{
		cout<<as[1];
		for(int i=2;i<=asl;i++) cout<<"."<<as[i];
		printf("\n");
	}
}
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int op; scanf("%d",&op);
		if(op==1)
		{
			op1();
		}
		if(op==2)
		{
			op2();
		}
		if(op==3)
		{
			op3();
		}
		if(op==4)
		{
			op4();
		}
	}
	return 0;
}