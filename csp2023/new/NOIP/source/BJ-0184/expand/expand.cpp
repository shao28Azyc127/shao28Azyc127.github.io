#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int c, n, m, q, a[N], b[N], ap[N], av[N], bp[N], bv[N], flg;
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int x, y, id, v;
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
	if(a[1]==b[1]) putchar('0');
		else if(n==1)
			if(a[1]<b[1]){flg=1;
				for(int i = 2; i <= m; i++) if(a[1]>=b[i]){ flg=0,putchar('0');break;}
				if(flg)putchar('1');
			}
			else{flg=1;
				for(int i = 2; i <= m; i++) if(a[1]<=b[i]){ flg=0,putchar('0');break;}
				if(flg)putchar('1');
			}
		else if(m==1)
			if(a[1]<b[1]){flg=1;
				for(int i = 2; i <= n; i++) if(a[i]>=b[1]){ putchar('0');break;}
				if(flg)putchar('1');
			}
			else{flg=1;
				for(int i = 2; i <= n; i++) if(a[i]<=b[1]){ putchar('0');break;}
				if(flg)putchar('1');
			}
		else if((a[1]-b[1])*(a[n]-b[m])>0) putchar('1');
		else putchar('0');
	while(q--){//cout<<q<<endl;
		scanf("%d%d", &x, &y);
		for(int i = 1; i <= x; i++)
			scanf("%d%d", &ap[i], &v), av[ap[i]]=a[ap[i]], a[ap[i]]=v;
		for(int i = 1; i <= y; i++)
			scanf("%d%d", &bp[i], &v), bv[bp[i]]=b[bp[i]], b[bp[i]]=v;
		if(a[1]==b[1]) putchar('0');
		else if(n==1)
			if(a[1]<b[1]){flg=1;
				for(int i = 2; i <= m; i++) if(a[1]>=b[i]){ flg=0,putchar('0');break;}
				if(flg)putchar('1');
			}
			else{flg=1;
				for(int i = 2; i <= m; i++) if(a[1]<=b[i]){ flg=0,putchar('0');break;}
				if(flg)putchar('1');
			}
		else if(m==1)
			if(a[1]<b[1]){flg=1;
				for(int i = 2; i <= n; i++) if(a[i]>=b[1]){ putchar('0');break;}
				if(flg)putchar('1');
			}
			else{flg=1;
				for(int i = 2; i <= n; i++) if(a[i]<=b[1]){ putchar('0');break;}
				if(flg)putchar('1');
			}
		else if((a[1]-b[1])*(a[n]-b[m])>0) putchar('1');
		else putchar('0');
		/*if(a[1]<b[1]){
			for(int i = 2, j = 2; i <= n; i++){
				while(j<=m && a[i]>=b[j] && a[i-1]<b[j]) j++;
				if(a[i-1]>=b[j]&&a[i]>=b[j]){ putchar('1'); break; }
			}
1 2 1 1
1 1
2
0 0
		}*/
		for(int i = 1; i <= x; i++)
			a[ap[i]]=av[ap[i]];
		for(int i = 1; i <= y; i++)
			b[bp[i]]=bv[bp[i]];
	}
	return 0;
}
