#include <bits/stdc++.h>
using namespace std;

int n;
int code[10][6];
bool book[6][10];
int cham[6];

//Beautiful,isn't it?--cham

bool check(int num)
{
	vector<int> d;
	int ans[6];
	int uz = 0;
	vector<int> uzi;
	for(int i=1;i<=5;i++)
	{
		ans[i] = code[num][i] - cham[i];
		uz += bool(ans[i]);
		if(ans[i])
			uzi.push_back(i);
	}

	if(uz == 0||uz > 2)
	{
		return 0;
	}
	else if(uz == 1)
	{
		return 1;
	}
	else//uz == 2
	{
		if(abs(uzi[0] - uzi[1]) != 1)
		{
			return 0;
		}
		else
		{
			return ((ans[uzi[0]]+10)%10) == ((ans[uzi[1]]+10)%10);
		}
	}
}


int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>code[i][j];
			book[j][code[i][j]] = 1;
		}
	}
	int ans = 0;
	for(int i1 = 0;i1<=9;i1++)
		for(int i2=0;i2<=9;i2++)
			for(int i3=0;i3<=9;i3++)
				for(int i4=0;i4<=9;i4++)
					for(int i5=0;i5<=9;i5++)
					{
						cham[1] = i1;
						cham[2] = i2;
						cham[3] = i3;
						cham[4] = i4;
						cham[5] = i5;
						bool OK = 1;
						for(int i=1;i<=n;i++)
						{
							if(!check(i))
							{
								OK = 0;
								break;
							}
						}
						ans+=OK;
					}
	cout<<ans;
	return 0;
}