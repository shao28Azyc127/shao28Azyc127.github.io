#include <bits/stdc++.h>
#define MAXN 2000009
#define MAXL 400
using namespace std;

string s;
int n;
bool dp[MAXN][MAXL];
bool book[MAXN][MAXL];
int CharNum[26][MAXN];
//dp[i][j] -> Check(i,i+2*j)
//Check(l,r) -> dp[l][(r-l+1)/2]


long long FastCheck()
{
	long long ans = 0;
	stack<char> S;
	for(int i=0;i<n;i++)
	{
		while(!S.empty())
		{
			S.pop();
		}
		for(int j=i;j<n;j++)
		{
			char now = s[j];
			if(!S.empty())
			{
				if(now == S.top())
					S.pop();
				else
					S.push(now);
			}
			else
			{
				S.push(now);
			}
			ans += S.empty();
		}
	}
	return ans;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s;
	cout<<FastCheck()<<endl;
	return 0;
}