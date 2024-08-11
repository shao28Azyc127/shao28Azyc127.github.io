#include <cstdio>
#include <algorithm>
using namespace std;

int c, t, n, m;
char v;
int ans, d[100005], a[100005][5], b[100005], cnt;
bool vis[100005];

void dfs12 ( int x )
{
	if ( cnt > ans ) return;
	
	if ( x > n )
	{
		for ( int i=1; i<=n; i++ )
		{
			if ( a[i][0] == 1 )
			{
				if ( b[i] != a[i][1] ) return ;
			}
			else if ( a[i][0] == 2 )
			{
				if ( b[i] != b[a[i][1]] ) return ;
			}
			else if ( a[i][0] == 3 )
			{
				if ( b[i] == 0 ) 
				{
					if ( b[a[i][1]] != 0 ) return ;
				}
				else
				{
					if ( b[a[i][1]] != 3-b[i] ) return ;
				}
			}
		}
		
		ans = min(ans, cnt);
		return ;
	}
	
	if ( a[x][0] == 1 )
	{
		 b[x] = a[x][1];
		 if ( b[x] == 0 ) 
		 {
			 cnt++;
			 dfs12(x+1);
			 cnt--;
		 }
		 else
		 {
			 dfs12(x+1);
		 } 
	} 
	
	b[x] = 0;
	cnt++;
	dfs12(x+1);
	cnt--;
	
	b[x] = 1;
	dfs12(x+1);
	
	b[x] = 2;
	dfs12(x+1);
	
}

int dfs ( int x )
{
	if ( vis[x] ) return d[x];
	
	vis[x] = true;
	
	if ( a[x][0] == 1 ) 
	{
		d[x] = 1;
		return 1;
	}
	
	if ( a[x][0] == 0 )
	{
		d[x] = 0;
		return 0;
	}
	
	d[x] = dfs(a[x][1]);
	
	return d[x];
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);

	scanf("%d%d", &c, &t);
	
	if ( c==1 || c==2 )
	{
		int x, y;
		
		while ( t-- )
		{
			scanf("%d%d", &n, &m);
			
			ans = n+1;
			
			for ( int i=1; i<=n; i++ ) 
			{
				d[i] = 0;
				vis[i] = false;
				a[i][0] = a[i][1] = 0;
			}
			
			for ( int i=1; i<=m; i++ )
			{
				getchar();
				v = getchar();
				getchar();
				
				if ( v == 'U' )
				{
					scanf("%d", &x);
					a[x][0] = 1;
					a[x][1] = 0;
				}
				else if ( v == 'T' )
				{
					scanf("%d", &x);
					a[x][0] = 1;
					a[x][1] = 1;
				}
				else if ( v == 'F' )
				{
					scanf("%d", &x);
					a[x][0] = 1;
					a[x][1] = 2;
				}
				else if ( v == '+' )
				{
					scanf("%d%d", &x, &y);
					
					if ( x != y )
					{
						if ( a[y][0] == 0 )
						{
							a[x][0] = 2;
							a[x][1] = y;
						}
						else if ( a[y][0] == 1 )
						{
							a[x][0] = 1;
							a[x][1] = a[y][1];
						}
						else if ( a[y][0] == 2 ) 
						{
							a[x][0] = 2;
							a[x][1] = a[y][1];
						}
						else if ( a[y][0] == 3 )
						{
							a[x][0] = 3;
							a[x][1] = a[y][1];
						}
					}
				}
			
				
				//printf("\n%c %d %d\n", v, x, a[x][0]);
			
				else if ( v == '-' )
				{
					scanf("%d%d", &x, &y);
					
					if ( x != y )
					{
						if ( a[y][0] == 0 )
						{
							a[x][0] = 3;
							a[x][1] = y;
						}
						else if ( a[y][0] == 1 )
						{
							a[x][0] = 1;
							if ( a[y][1] == 0 ) a[x][1] = a[y][1];
							else a[x][1] = 3-a[y][1];
						}
						else if ( a[y][0] == 2 ) 
						{
							a[x][0] = 3;
							a[x][1] = a[y][1];
						}
						else if ( a[y][0] == 3 )
						{
							a[x][0] = 2;
							a[x][1] = a[y][1];
						}
					}
					else
					{
						a[x][0] = 3;
						a[x][1] = x;
					}
				}
				
				//printf("\n%c %d %d\n", v, x, a[x][0]);
			}
			
			dfs12(1);
			
			printf("%d\n", ans);
			//if ( t ==1) return 0;
		}
		
		return 0;
	}
	
	if ( c==3 || c==4 )
	{
		int x;
		
		while ( t-- )
		{
			scanf("%d%d", &n, &m);
			
			ans = 0;
			
			for ( int i=1; i<=n; i++ ) d[i] = 0;
			
			for ( int i=1; i<=m; i++ )
			{
				getchar();
				v = getchar();
				getchar();
				scanf("%d", &x);
				
				if ( v == 'U' ) d[x] = 1;
				else d[x] = 0;
				
				//printf("%c %d %d\n", v, x, d[x]);
			}
			
			for ( int i=1; i<=n; i++ )
			{
				ans += d[i];
			}
			
			printf("%d\n", ans);
		}
		
		return 0;
	}
	
	if ( c==5 || c==6 )
	{
		int x, y;
		
		while ( t-- )
		{
			scanf("%d%d", &n, &m);
			
			ans = 0;
			
			for ( int i=1; i<=n; i++ ) 
			{
				d[i] = 0;
				vis[i] = false;
				a[i][0] = a[i][1] = 0;
			}
			
			for ( int i=1; i<=m; i++ )
			{
				getchar();
				v = getchar();
				getchar();
				
				if ( v == 'U' )
				{
					scanf("%d", &x);
					a[x][0] = 1;
				}
				else
				{
					scanf("%d%d", &x, &y);
					
					if ( x != y )
					{
						if ( a[y][0] == 0 )
						{
							a[x][0] = 2;
							a[x][1] = y;
						}
						else if ( a[y][0] == 1 )
						{
							a[x][0] = 1;
						}
						else if ( a[y][0] == 2 ) 
						{
							a[x][0] = 2;
							a[x][1] = a[y][1];
						}
					}
				}
				
				//printf("\n%c %d %d\n", v, x, a[x][0]);
			}
			
			for ( int i=1; i<=n; i++ )
			{
				ans += dfs(i);
				//printf("%d\n", d[i]);
			}
			
			printf("%d\n", ans);
			//if ( t ==1) return 0;
		}
		
		return 0;
	}
	
	return 0;
}
