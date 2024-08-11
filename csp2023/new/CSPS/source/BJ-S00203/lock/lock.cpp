#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
inline int read()
{
	int res=0,op=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		op|=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return op?-res:res;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
int n,a[10][10],b[10],ans;
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	n=read();
	for(re int i=1;i<=n;++i)
	{
		a[i][1]=read();
		a[i][2]=read();
		a[i][3]=read();
		a[i][4]=read();
		a[i][5]=read();
	}
	for(b[1]=0;b[1]<=9;++b[1])
	{
		for(b[2]=0;b[2]<=9;++b[2])
		{
			for(b[3]=0;b[3]<=9;++b[3])
			{
				for(b[4]=0;b[4]<=9;++b[4])
				{
					for(b[5]=0;b[5]<=9;++b[5])
					{
						bool flag=1;
						for(re int l=1;l<=n;++l)
						{
							int cnt=0;
							for(re int t1=1;t1<=5;++t1)
							{
								cnt+=a[l][t1]!=b[t1];
								for(re int t2=t1+2;t2<=5;++t2)
								{
									if(a[l][t1]!=b[t1]&&a[l][t2]!=b[t2])
									{
										flag=0;
										break;
									}
								}
								if(!flag) break;
							}
							if(cnt>2||!cnt) flag=0;
							if(!flag) break;
							for(re int t1=1;t1<=4;++t1)
							{
								if(a[l][t1]!=b[t1]&&a[l][t1+1]!=b[t1+1]&&(a[l][t1]-b[t1]+10)%10!=(a[l][t1+1]-b[t1+1]+10)%10)
								{
									flag=0;
									break;
								}
							}
							if(!flag) break;
						}
						ans+=flag;
					}
				}
			}
		}
	}
	write(ans);
	return 0;
}