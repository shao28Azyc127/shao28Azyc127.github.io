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
const int N=2e6+10;
char s[N];
int sum[N][2][2];
int c1[N],c2[N];
//     i   A  B
int st[N],top=0;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=read();scanf("%s",s+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int j=i;j<=n;j++)
		{
			if(top){if(st[top]==s[j])top--;else st[++top]=s[j];}
			else st[++top]=s[j];
			ans+=!top;
		}
	}
	printf("%d\n",ans);
	return 0;
}