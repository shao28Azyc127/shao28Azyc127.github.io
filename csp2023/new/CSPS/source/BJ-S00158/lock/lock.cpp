#include <bits/stdc++.h>
using namespace std;
int n;
int l[15][10];
int is[10];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=5;j++) cin>>l[i][j];
	}
	int cnt=0,ans=0,cnt1=0,cnt2=0;
	for (int one=0;one<=9;one++)
	{
		for (int two=0;two<=9;two++)
		{
			for (int three=0;three<=9;three++)
			{
				for (int four=0;four<=9;four++)
				{
					for (int five=0;five<=9;five++)
					{
						bool flg=true;
						for (int i=1;i<=n;i++)
						{
							cnt=0;
							if (one!=l[i][1]) is[++cnt]=1;
							if (two!=l[i][2]) is[++cnt]=2;
							if (three!=l[i][3]) is[++cnt]=3;
							if (four!=l[i][4]) is[++cnt]=4;
							if (five!=l[i][5]) is[++cnt]=5;
							if (cnt>=3)
							{
								flg=false;
								break;
							}
							else if (cnt==0)
							{
								flg=false;
								break;
							}
							else if (cnt==2)
							{
								if (is[2]==2&&is[1]==1)
								{
									bool f=false;
									for (int j=0;j<=9;j++)
									{
										if ((l[i][2]+j)%10==two&&(l[i][1]+j)%10==one)
										{
											f=1;
											break;
										}
									}
									if (!f)
									{
										flg=false;
										break;
									}
								}
								else if (is[2]==3&&is[1]==2)
								{
									bool f=false;
									for (int j=0;j<=9;j++)
									{
										if ((l[i][3]+j)%10==three&&(l[i][2]+j)%10==two)
										{
											f=1;
											break;
										}
									}
									if (!f)
									{
										flg=false;
										break;
									}
								}
								else if (is[2]==4&&is[1]==3)
								{
									bool f=false;
									for (int j=0;j<=9;j++)
									{
										if ((l[i][4]+j)%10==four&&(l[i][3]+j)%10==three)
										{
											f=1;
											break;
										}
									}
									if (!f)
									{
										flg=false;
										break;
									}
								}
								else if (is[2]==5&&is[1]==4)
								{
									bool f=false;
									for (int j=0;j<=9;j++)
									{
										if ((l[i][5]+j)%10==five&&(l[i][4]+j)%10==four)
										{
											f=1;
											break;
										}
									}
									if (!f)
									{
										flg=false;
										break;
									}
								}
								else
								{
									flg=false;
									break;
								}
							}
						}
						if (flg) ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}