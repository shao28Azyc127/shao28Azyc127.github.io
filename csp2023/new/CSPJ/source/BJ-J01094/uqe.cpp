#include <iostream>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if (b*b-4*a*c<0)
		{
			printf("NO\n");
		}
		else 
		{
			for (int i=m;i>=0;i--)
			{
				if (a*i*i+b*i+c==0)
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
