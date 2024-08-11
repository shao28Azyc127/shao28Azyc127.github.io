#include <cstdio>
using namespace std;

int c, t, n, m, k, x, y;
long long d, v, ans;

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	
	if ( c==17 || c==18 )
	{
		while ( t-- )
		{
			scanf("%d%d%d%lld", &n, &m, &k, &d);
			ans = 0;
			
			for ( int i=1; i<=m; i++ )
			{
				scanf("%d%d%lld", &x, &y, &v);
				
				if ( y>k || x<y ) continue;
				
				if ( y*d < v ) ans += v-y*d;
			}
			
			printf("%lld\n", ans);
		}
		
		return 0;
	}
}
