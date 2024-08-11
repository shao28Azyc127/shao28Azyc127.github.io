#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

int n, T, m, a[N], lag[128], f[N];

// code : U = 0 T = 1 a1 = 2 a2 = 3 ... an = n + 1 F = n + 2 not a1 = n + 2 ...

int rev(int sig){return sig?(sig>n+1?sig-n-1:sig+n+1):0;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int read(){
	int s=0,ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return s;
}

signed main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	read(); T = read();
	lag['U'] = 0;
	lag['T'] = 1;
	while(T--)
	{
		n = read(); m = read();
		lag['F'] = rev(1);
		for(int i = 1; i <= n; i++) a[i] = i + 1;
		for(int i = 1; i <= 2 * n + 2; i++) f[i] = i;
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			char op;
			scanf("%c", &op);
			x = read();
			if(!isalpha(op))
			{
				y = read();
				a[x] = a[y];
				if(op == '-') a[x] = rev(a[x]);
			}
			else a[x] = lag[op];
		}
		for(int i = 1; i <= n; i++)
		{
			if(find(i + 1) != find(a[i]))
				f[find(i + 1)] = find(a[i]);
			if(find(rev(i + 1)) != find(rev(a[i])))
				f[find(rev(i + 1))] = find(rev(a[i]));
		}
		for(int i = 1; i <= n; i++)
			if(find(i + 1) == find(rev(i + 1)) && find(i + 1) != find(0))
				f[find(i + 1)] = find(0);
		int res = 0;
		for(int i = 1; i <= n; i++)
			res += (find(i + 1) == find(0));
		printf("%d\n", res);
	}
	return 0;
}
