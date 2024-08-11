#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n,a[N],b[N][N],c[N],t[N];
bool chck(int j,int i)
{
	if((t[i]+10)%10==(t[i+1]+10)%10)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>b[i][j];
		}
	}
	int ans=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				for(int l=0;l<10;l++)
				{
					for(int w=0;w<10;w++)
					{
						c[1]=i;
						c[2]=j;
						c[3]=k;
						c[4]=l;
						c[5]=w;
						bool ttg=0;
						for(int tmp=1;tmp<=n;tmp++)
						{
							for(int jj=1;jj<=5;jj++)
							{
								t[jj]=c[jj]-b[tmp][jj];
							}
							int cnt=0;
							bool tg=0;
							for(int jj=1;jj<=5;jj++)
							{
								if(t[jj]!=0)
								{
									cnt++;
								}
							}
							if(cnt==1)
							{
								continue;
							}
							else if(cnt==2)
							{
								for(int jj=1;jj<=4;jj++)
								{
									if(chck(tmp,jj)&&t[jj]!=0)
									{
										tg=1;
										break;
									}
								}
								if(!tg)ttg=1;
							}
							else ttg=1;
						}
						if(ttg==0)ans++;
					}
				}
			}
		}
	}
	cout<<ans;
}
