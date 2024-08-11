#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int N;
int op;
int k;
int cnt=0;//count struct
int cnt2=0;//count var
string t,s,n,curstring;
long long curRofv;
struct variable
{
	long long l,r;
	string state;
	int cate;
	string name;
}v[105];
struct STRUCT
{
	string structname;
	int catemax;
	struct var
	{
		string name;
		int cate;
		int l,r;
	}V[105];
}ST[105];
void definestruct()
{
	cin>>s;
	scanf("%d",&k);
	cnt++;
	for(int i=1;i<=k;i++)
	{
		cin>>t>>ST[cnt].V[i].name;
		ST[cnt].structname=s;
		if(t=="byte")ST[cnt].V[i].cate=1;
		else if(t=="short")ST[cnt].V[i].cate=2;
		else if(t=="int")ST[cnt].V[i].cate=4;
		else if(t=="long")ST[cnt].V[i].cate=8;
		else
		{
			for(int j=1;j<=cnt;j++)
		    {
			    if(ST[j].structname==t)
			    {
			    	ST[cnt].V[i].cate=ST[j].catemax;
			    }
		    }
		}
		ST[cnt].catemax=max(ST[cnt].catemax,ST[cnt].V[i].cate);
	}
	int curR=0;
	for(int i=1;i<=k;i++)
	{
		ST[cnt].V[i].l=curR;
		ST[cnt].V[i].r=ST[cnt].V[i].l+ST[cnt].catemax-1;
		curR=ST[cnt].V[i].r+1;
	}
	cout<<curR<<" "<<ST[cnt].catemax<<endl;
}
void define()
{
	cnt2++;
	cin>>t>>n;
	v[cnt2].name=n;
	if(t=="byte"){v[cnt2].cate=1;v[cnt2].state="byte";}
	else if(t=="short"){v[cnt2].cate=2;v[cnt2].state="short";}
	else if(t=="int"){v[cnt2].cate=4;v[cnt2].state="int";}
	else if(t=="long"){v[cnt2].cate=8;v[cnt2].state="long";}
	else
	{
		for(int i=1;i<=cnt;i++)
		{
			if(ST[i].structname==t)
			{
				v[cnt2].cate=ST[i].catemax;
			}
		}
	}
	while(curRofv%v[cnt2].cate!=0)
	    curRofv++;
	v[cnt2].l=curRofv;
	cout<<v[cnt2].l<<endl;
	v[cnt2].r=v[cnt2].l+v[cnt2].cate-1;
	curRofv=v[cnt2].r+1;
}

void up()
{
	return;
}
void ask()
{
	cin>>s;
	string curname[105];
	int tmp=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='.')
		{
			tmp++;
			if(tmp==1)
			{
				for(int i=1;i<=cnt2;i++)
				{
					if(v[cnt2].name==curname[tmp])
					{
						if(v[cnt2].state=="byte"||v[cnt2].state=="int"||v[cnt2].state=="short"||v[cnt2].state=="long")
						{
							cout<<v[cnt2].l<<endl;
							return;
						}
						else
						{
							up();
						}
					}
				}
		    }
		}
		curname[tmp]+=s[i];
	}
}
long long addr;
string pos;
string temp;
void ask2()
{
	scanf("%lld",&addr);
	for(int i=1;i<=cnt2;i++)
	{
		if(v[i].l<=addr&&v[i].r>=addr)
		{
			if(v[i].state=="byte"||v[i].state=="int"||v[i].state=="short"||v[i].state=="long")
			{
				temp=v[i].name;
				pos='.'+temp+pos;
				up();
				return;
			}
			else
			{
				cout<<"ERR"<<endl;
				return;
			}
		}
	}
	cout<<"ERR"<<endl;
	return;
}
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			definestruct();
		}
		else if(op==2)
		{
			define();
		}
		else if(op==3)
		{
			ask();
		}
		else if(op==4)
		{
			ask2();
		}
	}
	
    return 0;
}
