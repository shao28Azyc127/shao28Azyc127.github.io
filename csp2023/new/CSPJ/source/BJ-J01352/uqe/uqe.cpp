#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
int m,t,a,b,c;
int gcdd(int xx,int yy,int zz)
{
	if(zz==0)
	{
		return yy;
	}
	return gcdd(yy,zz,yy%zz);
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int n;
	scanf("%d%d",&t,&m);
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(b*b-4*a*c<0)
		{
			printf("NO\n");
			break;
		}
		if(b==c&&c==0)
		{
			cout<<0<<endl;
			break;
		}
		n=b*b-4*a*c;
		if(n==0)
		{
			int f=0;
			cout<<f;
			if(b<0)
			{
				f++;
			}
			if(a<0)
			{
				f=(f+1)%2;
			}
			if(f==0)
			{
				a=fabs(a);
				b=fabs(b);
			}
			else
			{
				cout<<'-';
			}
			a*=2;
			int d=gcdd(max(a,b),min(a,b),max(a,b)%min(a,b));
			cout<<b/d<<'/'<<c/d<<endl;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
