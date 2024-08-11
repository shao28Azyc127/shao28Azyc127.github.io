#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N=3005;
string s[N],sx[N];
char st[N][N];
int n,m;


int val[N];
int mins=1e9+7,sec=1e9+7;
int minn,sen;
void gett(string s,int num)
{
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		st[num][i]=s[i-1];
		cnt*=26;
		cnt+=(s[i-1]-'a'+1);
	}
	val[num]=cnt;
	if(cnt<mins)
	{
		sec=mins;
		sen=minn;
		mins=cnt;
		minn=num;
	}
	else if(cnt<sec)
	{
		sec=cnt;
		sen=num;
	}
	return ;
}
int getss(string x)
{
	int tmp=0;
	for(int i=0;i<m;i++)
	{
		tmp*=26;
		tmp+=(x[i]-'a'+1);
	}
	return tmp;
}


int mul(short a[],int b,int siz)
{
	for(int i=1;i<=siz;i++)
	{
		a[i]*=b;
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[siz+2]!=0)
	{
		siz+=2;
	}
	else if(a[siz+1]!=0)
	{
		siz++;
	}
	return siz;
}
int add(short a[],int b,int siz)
{
	a[1]+=b;
	a[2]+=a[1]/10;
	a[1]%=10;
	if(a[siz+2]!=0)
	{
		siz+=2;
	}
	else if(a[siz+1]!=0)
	{
		siz++;
	}
	return siz;
}
void ge(string s,int num)
{
	short cnt[605];
	int siz=0;
	for(int i=1;i<=m;i++)
	{
		st[num][i]=s[i-1];
		siz=mul(cnt,26,siz);
		siz=add(cnt,(s[i-1]-'a'+1),siz);
	}
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	if(m<=2)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> s[i];
			gett(s[i],i);
		}
		for(int i=1;i<=n;i++)
		{
			sort(st[i]+1,st[i]+1+m);
		}
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout << st[i][j] ;
			}
			cout << endl;
		}*/
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				sx[i]+=st[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(i==minn)
			{
				if(getss(sx[i])<sec)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				if(getss(sx[i])<mins)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin >> s[i];
			ge(s[i],i);
		}
	}
	return 0;
}
