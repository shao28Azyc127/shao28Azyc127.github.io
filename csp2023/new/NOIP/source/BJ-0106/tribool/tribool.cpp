// #include<iostream>
#include<cstdio>
using namespace std;
#define N 100005
int c, t, n, m, ans;
char tp[N];
bool iu[N];

inline int min(int a, int b) {
	return a < b ? a : b;
}

struct op {
	char tp;
	int f, t;
};
op ops[N];

inline char un(char i) {
	return i == 'T' ? 'F' : (i == 'F' ? 'T' : i);
}

struct comb {
	char c[11];
	
	void operator=(const comb &o) {
		for (int i=0;i<11;i++) {
			c[i]=o.c[i];
		}
	}
	bool operator==(const comb &o) const {
		for (int i=0;i<11;i++) {
			if (c[i]!=o.c[i])
				return false;
		}
		return true;
	}
	
	void print() const {
		for (int i=1;i<=m;i++) {
			printf("%c ", c[i]);
		}
		printf("\n");
	}
	
	void run(op o) {
		if (o.tp == '+') {
			c[o.t] = c[o.f];
		} else if (o.tp == '-') {
			c[o.t] = un(c[o.f]);
		} else {
			c[o.t] = o.tp;
		}
		// print();
	}
};

void gen(int d, comb a) {
	if (d) {
		comb t = a;
		t.c[d] = 'T';
		gen(d-1, t);
		comb f = a;
		f.c[d] = 'F';
		gen(d-1, f);
		comb u = a;
		u.c[d] = 'U';
		gen(d-1, u);
	} else {
		comb aa=a;
		for (int i=1;i<=m;i++) {
			aa.run(ops[i]);
		}
		if (aa == a) {
			int ansi = 0;
			for (int i=1;i<=m;i++) {
				if (a.c[i] == 'U') {
					ansi++;
				}
			}
			ans = min(ans, ansi);
		}
	}
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%d%d", &c, &t);
	for (int i=1;i<=t;i++) {
		scanf("%d%d", &n, &m);
		ans = 0x3f3f3f3f;
		if (c >= 3 && c <= 6) {
			ans = 0;
			for (int j=1;j<=n;j++) {
					iu[j] = 0;
				}
		}// #3~6
		for (int j=1;j<=m;j++) {
			scanf("%s", &ops[j].tp);
			if (ops[j].tp == '+' || ops[j].tp == '-') {
				scanf("%d%d", &ops[j].t, &ops[j].f);
				if (c >= 5 && c <= 6) {
					if (iu[ops[j].f] && !iu[ops[j].t]) {
						iu[ops[j].t] = 1;
						ans++;
					}
					else if (!iu[ops[j].f] && iu[ops[j].t]) {
						iu[ops[j].t] = 0;
						ans--;
					}
				}// #5~6
			} else {
				scanf("%d", &ops[j].t);
				if (c >= 3 && c <= 6) {
					if (ops[j].tp == 'U' && !iu[ops[j].t]) {
						iu[ops[j].t] = 1;
						ans++;
					}
					else if (ops[j].tp != 'U' && iu[ops[j].t]) {
						iu[ops[j].t] = 0;
						ans--;
					}
				}// #3~6
			}
		// printf("%c ", ops[j].tp);
		}
		if (c >= 5 && c <= 6) {
			int ansl=ans;
			for (int ii=1;ii<=114514;ii++) {
				for (int j=1;j<=n;j++) {
					// iu[j] = 0;
				}
			for (int j=1;j<=m;j++) {
				if (ops[j].tp == '+') {
					if (iu[ops[j].f] && !iu[ops[j].t]) {
						iu[ops[j].t] = 1;
				// printf("+%d\n", ops[j].t);
						ans++;
						//flag = 1;
					}
					else if (!iu[ops[j].f] && iu[ops[j].t]) {
						iu[ops[j].t] = 0;
				// printf("-%d\n", ops[j].t);
						ans--;
						//flag = 1;
					}
				} else {
					if (ops[j].tp == 'U' && !iu[ops[j].t]) {
						iu[ops[j].t] = 1;
				// printf("+%d\n", ops[j].t);
						ans++;
						//flag = 1;
					}
					else if (ops[j].tp != 'U' && iu[ops[j].t]) {
						iu[ops[j].t] = 0;
				// printf("-%d\n", ops[j].t);
						
						ans--;
						//flag = 1;
					}
				}
			}
			if (ansl == ans) break;
				// printf("%d\n", ans);
				ansl = ans;
			}
		}// #3~6
		if (n <= 10 && m <= 10) {
			comb a;
			gen(m, a);
		} // #1,2
		
		/*
		for (int j=1;j<=m;j++) {
			if (a[j].tp == 'U') {
				tp[a[j].t] = a[j].tp;
			} else if (a[j].tp == '+') {
				tp[a[j].t] = tp[a[j].f];
			} else if (a[j].tp == '-') {
				tp[a[j].t] = un(tp[a[j].f]);
			}
		}
		*/
		printf("%d\n", ans);
	}
	return 0;
}
