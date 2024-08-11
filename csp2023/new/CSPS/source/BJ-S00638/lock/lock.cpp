#include <cstdio>
using namespace std;

int n, a[10][10], p[10], ans;

bool check( int x )
{
	int cnt = 0, m[5];
	
	for ( int i=1; i<=5; i++ )
	{
		if ( p[i] != a[x][i] )
		{
			m[++cnt] = i;
		}
		
		if ( cnt >= 3 ) return false;
	}
	
	if ( cnt == 1 ) return true;
	if ( cnt == 0 ) return false;
	
	if ( m[2]-m[1] != 1 ) return false;
	if ( (p[m[2]]-a[x][m[2]]+10)%10 != (p[m[1]]-a[x][m[1]]+10)%10 ) return false;
	
	return true;
}

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	
	scanf("%d", &n);
	
	for ( int i=1; i<=n; i++ )
	{
		for ( int j=1; j<=5; j++ )
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	for ( int b=0; b<=9; b++ )
	{
		p[1] = b;
		
		for ( int c=0; c<=9; c++ )
		{
			p[2] = c;
			
			for ( int d=0; d<=9; d++ )
			{
				p[3] = d;
				
				for ( int e=0; e<=9; e++ )
				{
					p[4] = e;
					
					for ( int f=0; f<=9; f++ )
					{
						p[5] = f;
						
						bool flag = true;
						
						for ( int i=1; i<=n; i++ )
						{
							if ( !check(i) )
							{
								flag = false;
								break;
							} 
						}
						
						if ( flag ) 
						{
							//printf("%d%d%d%d%d\n", p[1], p[2], p[3], p[4], p[5]);
							ans++;
						}
						
					}
				}
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
