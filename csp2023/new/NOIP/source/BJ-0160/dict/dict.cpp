#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=3010;
char s[N];
int mx[N],mn[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)mx[i]=-1,mn[i]=26;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)mx[i]=max(mx[i],s[j]-'a');
		for(int j=1;j<=m;j++)mn[i]=min(mn[i],s[j]-'a');
	}
	for(int i=1;i<=n;i++)
	{
		bool f=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			f&=mn[i]<mx[j];
		}
		printf("%d",(int)f);
	}
	return 0;
}