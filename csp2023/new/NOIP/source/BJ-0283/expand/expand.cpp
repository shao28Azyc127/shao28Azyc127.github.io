#include <cstdio>
using namespace std;

int c, n, m, q, x, y;

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	scanf("%d%d%d%d", &c, &n, &m, &q);
	
	if ( c == 1 )
	{
		scanf("%d%d", &x, &y);
		
		if ( x == y )
		{
			for ( int i=1; i<=q; i++ ) printf("0");
		}
		else
		{
			for ( int i=1; i<=q; i++ ) printf("1");
		}
		
		return 0;
	}
}
