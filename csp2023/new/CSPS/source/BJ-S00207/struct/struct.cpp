#include <bits/stdc++.h>
#define int long long
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 1005
#define N 1200005
using namespace std;
int read() {
	int w = 0, x = 0; char ch = getchar();
	while(!isdigit(ch)) w |= ch == '-', ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return w ? -x : x;
}
int tot, numson[maxn], siz[maxn], a[maxn], len[maxn], son[maxn][maxn], o[maxn][maxn];
char s[maxn][maxn], nam[maxn][maxn][11], t[1000005];

char nam2[maxn][maxn]; int typ[maxn], tot2, pos, beg[maxn];

int lens[maxn], lennam[maxn][maxn], lennam2[maxn];
int CEIL(int x, int y) {
	return ((x + y - 1) / y) * y;
}
int ed[maxn], totnod = 1;

int id[N], ch[N][26];
int doit(int x, char c) {
	int k = c - 'a';
	if(!ch[x][k]) ch[x][k] = ++totnod;
	return ch[x][k];
}
void ins() {
	int now = 0;
	ru(i, 1, lens[tot]) now = doit(now, s[tot][i]);
	assert(!id[now]);id[now] = tot;
	ed[tot] = ++totnod;
	ru(i, 1, numson[tot]) {
		now = ed[tot];
		ru(j, 1, lennam[tot][i]) now = doit(now, nam[tot][i][j]);
		assert(!id[now]); id[now] = i;
	}
}
void ins2() {
	int now = 1;
	ru(i, 1, lennam2[tot2]) now = doit(now, nam2[tot2][i]);
	assert(!id[now]); id[now] = tot2;
}
char ans[10005];
int find() {
	int lent = strlen(t + 1), now = 0;
	ru(i, 1, lent) now = ch[now][t[i] - 'a'];
	return id[now];
}
signed main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	lens[1] = 4, siz[1] = a[1] = 1;
	s[1][1] = 'b', s[1][2] = 'y', s[1][3] = 't', s[1][4] = 'e';
	lens[2] = 5, siz[2] = a[2] = 2;
	s[2][1] = 's', s[2][2] = 'h', s[2][3] = 'o', s[2][4] = 'r', s[2][5] = 't';
	lens[3] = 3, siz[3] = a[3] = 4;
	s[3][1] = 'i', s[3][2] = 'n', s[3][3] = 't';
	lens[4] = 4, siz[4] = a[4] = 8;
	s[4][1] = 'l', s[4][2] = 'o', s[4][3] = 'n', s[4][4] = 'g';
	ru(i, 1, 4) tot++, ins();
	int NN = read();
	while(NN--) {
		//printf("!\n"); fflush(stdout);
		int op = read();
		if(op == 1) {
			tot++;
			scanf("%s", s[tot] + 1); lens[tot] = strlen(s[tot] + 1);
			numson[tot] = read();
			ru(i, 1, numson[tot]) {
				scanf("%s", t + 1);
				son[tot][i] = find(); //printf("??? %d\n", son[tot][i]);
				a[tot] = max(a[tot], a[son[tot][i]]);
				scanf("%s", nam[tot][i] + 1); lennam[tot][i] = strlen(nam[tot][i] + 1);
			}
			//printf("!\n");
			o[tot][1] = 0;
			ru(i, 2, numson[tot]) o[tot][i] = CEIL(o[tot][i - 1] + siz[son[tot][i - 1]], a[son[tot][i]]);
			siz[tot] = CEIL(o[tot][numson[tot]] + siz[son[tot][numson[tot]]], a[tot]);
			//printf("!\n");
			ins();
			printf("%lld %lld\n", siz[tot], a[tot]);
		}
		if(op == 2) {
			tot2++;
			scanf("%s", t + 1);
			typ[tot2] = find(); //printf("tpy %d %d\n", tot2, typ[tot2]);
			scanf("%s", nam2[tot2] + 1); lennam2[tot2] = strlen(nam2[tot2] + 1);
			//printf("??? %d %d %d\n", typ[tot2], pos, a[typ[tot2]]);
			printf("%lld\n", beg[tot2] = CEIL(pos, a[typ[tot2]]));
			pos = beg[tot2] + siz[typ[tot2]];
			ins2();
		}
		if(op == 3) {
			scanf("%s", t + 1);
			int len = strlen(t + 1);
			t[++len] = '.';
			int ans = 0;
			int pos = 1, now = 0;
			ru(i, 1, len) {
				if(t[i] == '.') {
					int v = id[pos]; //printf("eee %d ", v);
					if(!now) ans += beg[v], pos = ed[typ[v]], now = typ[v];
					else ans += o[now][v], pos = ed[son[now][v]], now = son[now][v];
					//printf("%d\n", now);
				}
				else assert(t[i] >= 'a'), pos = ch[pos][t[i] - 'a'];
			}
			printf("%lld\n", ans);
		}
		if(op == 4) {
			int top = 0;
			int x = read(); //printf("!%lld ", x);
			int pos = upper_bound(beg + 1, beg + tot2 + 1, x) - beg - 1;
			x -= beg[pos];
			ru(i, 1, lennam2[pos]) ans[++top] = nam2[pos][i];
			pos = typ[pos];
			if(x >= siz[pos]) {
				printf("ERR\n");
				continue;
			}
			int fl = 0;
			while(pos > 4) {
				int rk = upper_bound(o[pos] + 1, o[pos] + numson[pos] + 1, x) - o[pos] - 1;
				x -= o[pos][rk];
				ans[++top] = '.';
				ru(i, 1, lennam[pos][rk]) ans[++top] = nam[pos][rk][i]; 
				pos = son[pos][rk];
				if(x >= siz[pos]) {
					printf("ERR\n");fl = 1;
					break;
				}
			}
			if(fl) continue;
			ru(i, 1, top) putchar(ans[i]);
			putchar('\n');
		}
	}
	return 0;
}