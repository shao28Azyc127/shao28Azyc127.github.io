#include<bits/stdc++.h>
using namespace std;
int arr[10000][10000];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt=0;
	int l,r;
	int ans=0;
	//bool flag=0;
	for(int k=1;k<n;k++)
	{
		for(int j=k-1;j>=0;j--)
		{
			ans=0;
			for(int i=j;i<=k;i++)
			{
				if((k-j)%2==0)break;
				//if()
				ans=k-j+1;
				if(s[i]==s[i+1])
				{
					//cout<<i<<" "<<i+1<<endl;
					ans-=2;
					if(ans==0)
					{
						if(arr[i][i+1]!=1)
						{
							arr[i][i+1]=1;
							cnt++;
						}
						//flag=1;
						break;
					}
					//cnt++;
					l=i-1;
					r=i+1+1;
					while(l>=0&&r<n)
					{
						//cout<<l<<" "<<r<<endl;
						if(s[l]==s[r])
						{
							//cout<<l<<" "<<r<<endl;
							//cnt++;
							ans-=2;
							if(ans==0)
							{
								if(arr[l][r]!=1)
								{
									arr[l][r]=1;
									cnt++;
								}
								//flag=1;
								break;
							}
							l--;
							r++;
						}
						else break;
					}
				}
				//if(flag)break;
			}
		}
	}
	for(int k=1;k<n;k++)
	{
		for(int j=k-1;j>=0;j--)
		{
			for(int i=j;i<=k;i++)
			{
				for(int h=j+1;h<=k-1;h++)
				{
					if(arr[j][h]==1&&arr[h+1][k]==1&&arr[j][k]!=1)
					{
						arr[j][k]=1;
						//cout<<100;
						cnt++;
						//flag=1;
						break;
					}
				}
			}
		}
	}
	//cout<<endl;
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==1)
			{
				cout<<i<<" "<<j<<endl;
			}
		}
		//cout<<endl;
	}*/
	cout<<cnt;
	return 0;
}
