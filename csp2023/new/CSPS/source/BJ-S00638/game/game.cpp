#include <cstdio>
using namespace std;

int n, ans;
char s[2000005];
bool dp[8005][8005];

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%d", &n);
	scanf("%s", s+1);
	
	for ( int i=1; i<n; i++ )
	{
		if ( s[i] == s[i+1] ) 
		{
			dp[i][2] = true;
			ans++;
			//printf("%d %d\n", i, i+1);
		}
	}
	
	for ( int k=4; k<=n; k+=2 )
	{
		for ( int i=1; i+k-1<=n; i++ )
		{
			if ( s[i]==s[i+k-1] && dp[i+1][k-2] )
			{
				dp[i][k] = true;
				ans++;
				//printf("%d %d\n", i, i+k-1);
				continue;
			}
			
			for ( int j=2; j<=k-2; j+=2 )
			{
				if ( dp[i][j] && dp[i+j][k-j] ) 
				{
					dp[i][k] = true;
					ans++;
					//printf("%d %d\n", i, i+k-1);
					break;
				}
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
