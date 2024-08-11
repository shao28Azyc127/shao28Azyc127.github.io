#include <cstdio>
#define ll long long
using namespace std;
const int N=2e6,MOD=1e9+9;
int n;
char str[N+2],sta[N+2],top;
ll huiwen(int l,int r)
{
	if(r<=l)
		return 0;
	ll cnt=0;
	int i,j,k,mid=l+(r-l>>1);
	for(i=l;i<=mid;i++)
	{
		j=mid+1+(mid-i)%2;
		for(j;j<=r;j+=2)
		{
			top=0;
			str[0]=0;
			for(k=i;k<=j;k++)
				if(str[k]==sta[top])
					top--;
				else
					sta[++top]=str[k];
			if(!top)
				cnt++;
		}
	}
	return cnt+huiwen(l,mid)+huiwen(mid+1,r);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",str+1);
	printf("%lld",huiwen(1,n));
	return 0;
}