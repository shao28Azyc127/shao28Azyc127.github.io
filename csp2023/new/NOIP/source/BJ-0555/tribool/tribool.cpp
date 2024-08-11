#include <bits/stdc++.h>
#define MAXN 100009
using namespace std;

int c,t;
int n,m;

struct Tri
{
	int num;
	bool value;//0:link,1:value (-1:0:1)->(U/F/T)
	void Debug()
	{
		cout<<"value:"<<value<<" -> "<<num<<endl;
	}
}T[MAXN];

int Not(int x)
{
	if(x == 1)
		return 0;
	else if(x == 0)
		return 1;
	else
		return -1;
}

void init()
{
	for(int i=1;i<=n;i++)
	{
		T[i].value = 0;
		T[i].num = i;
	}
}

bool Finding[MAXN];

void Findinit()
{
	for(int i=1;i<=n;i++)
	{
		Finding[i] = 0;
	}
}

int Find(int now)//T[now].num
{
	//cout<<"Find "<<root<<" "<<now<<endl;
	if(T[now].value)
	{
		return now;
	}
	if(Finding[now])
	{
		return T[now].num;
	}
	Finding[now] = 1;
	if(T[now].num == now||T[now].num == -now)
	{
		return T[now].num;
	}
	if(T[now].num > 0)
		T[now].num = Find(T[now].num);
	else
		T[now].num = -Find(-T[now].num);
	return T[now].num;
}

void Link(int now)
{
	if(!T[now].value)//link mode
	{
		T[now].value = 1;
		if(T[now].num == now)//Yoooooo
		{
			T[now].num = 1;
		}
		else if(T[now].num == -now)//Another Me(
		{
			T[now].num = -1;
		}
		else//Just another one.
		{
			int fa = abs(T[now].num);
			if(!T[fa].value)
			{
				Link(fa);
			}
			if(T[now].num < 0)
				T[now].num = Not(T[fa].num);
			else
				T[now].num = T[fa].num;
		}
	}
}

int Sum()
{
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(T[i].value&&T[i].num == -1)
			ans++;
	}
	return ans;
}

void Debug(string s)
{
	cout<<s<<" Debug Start:\n";
	for(int i=1;i<=n;i++)
	{
		cout<<i<<":";
		T[i].Debug();
	}
	cout<<s<<" Debug End,Sum = "<<Sum()<<endl;
}


int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	//freopen("tribool2.in","r,",stdin);
	cin>>c>>t;
	for(int Turn = 1;Turn <= t;Turn++)
	{
		cin>>n>>m;
		init();
		Findinit();
		for(int i=1;i<=m;i++)
		{
			Findinit();
			char v;
			int a,b;
			cin>>v;
			if(v >= 'A' && v <= 'Z')
			{
				cin>>a;
				T[a].value = 1;
				if(v == 'T')
					T[a].num = 1;
				else if(v == 'F')
					T[a].num = 0;
				else
					T[a].num = -1;
			}
			else
			{
				cin>>a>>b;
				if(v == '+')
				{
					T[a].value = 0;
					T[a].num = Find(b);
				}
				else
				{
					T[a].value = 0;
					T[a].num = -Find(b);
				}
			}
		}
		//Debug("input");
		int ans = 0;
		for(int i=1;i<=n;i++)
		{
			Link(i);
			if(T[i].num == -1)
				ans++;
		}
		//Debug("Link");
		cout<<ans<<endl;
	}
	return 0;
}
