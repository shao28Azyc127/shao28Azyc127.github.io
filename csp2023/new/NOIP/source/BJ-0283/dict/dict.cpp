#include <cstdio>
using namespace std;

int n, m;
bool flag, flagg;
char s[3005];
int a[3005][30];
int cnt, maxi, maxx[3005][3005], maxxx[3005], minn[3005][3005];

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	if ( n == 1 )
	{
		puts("1");
		return 0;
	}
	
	for ( int i=1; i<=m; i++ ) maxxx[i] = 30;
	
	for ( int i=1; i<=n; i++ )
	{
		scanf("%s", s+1);
		
		for ( int j=1; j<=m; j++ )
		{
			a[i][s[j]-'a']++;
		}
		
		cnt = 0;
		flag = true;
		flagg = true;
		
		for ( int j=25; j>=0; j-- )
		{
			for ( int k=1; k<=a[i][j]; k++ )
			{
				maxx[i][++cnt] = j;
				
				//printf("%d %d %d %d\n", i, cnt, j, maxxx[cnt]);
				
				if ( flagg && j>maxxx[cnt] )
				{
					flag = false;
					break;
				}
				
				if ( j < maxxx[cnt] ) flagg = false;
			}
			
			if ( !flag ) break;
		}
		
		if ( flag )
		{
			if ( flagg )
			{
				maxi = 0;
			}
			else
			{
				maxi = i;
				
				for ( int j=1; j<=m; j++ )
				{
					maxxx[j] = maxx[i][j];
				}
			}
		}
		
		cnt = 0;
		
		for ( int j=0; j<=25; j++ )
		{
			for ( int k=1; k<=a[i][j]; k++ )
			{
				minn[i][++cnt] = j;
			}
		}
	}
	
	/*for ( int i=1; i<=m; i++ ) printf("%d ", maxxx[i]);
	puts("");*/
	
	for ( int i=1; i<=n; i++ )
	{
		flag = true;
		
		for ( int j=1; j<=m; j++ )
		{
			if ( minn[i][j] < maxxx[j] )
			{
				printf("1");
				flag = false;
				break;
			}
			
			if ( minn[i][j] > maxxx[j] )
			{
				printf("0");
				flag = false;
				break;
			}	
		}
		
		if ( flag ) 
		{
			if ( maxi == i ) printf("1");
			else printf("0");
		}
	}
	
	return 0;
}
