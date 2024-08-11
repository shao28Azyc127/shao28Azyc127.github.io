#include <bits/stdc++.h>
using namespace std;
const int N = 3000 + 10;

int n, m, id1, id2;

char ch[N][N], s1[N], s2[N];

bool cmp(char a, char b) {
	return a > b;
}

bool check(char s[], char ss[]) {
	for(int i = 1; i <= m; i++)
		if(s[i] > ss[i])
			return 1;
		else if(s[i] < ss[i])
			return 0;
	return 0;
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		s1[i] = s2[i] = 'z';
	for(int i = 1; i <= n; i++) {
		cin >> (ch[i] + 1);
		sort(ch[i] + 1, ch[i] + m + 1, cmp);
		//for(int i = 1; i <= m; i++)
		//	cout << ch[i];
		//cout << endl;
		if(check(s1, ch[i])) {
			id2 = id1, id1 = i;
			for(int j = 1; j <= m; j++)
				s2[j] = s1[j], s1[j] = ch[i][j];
		}
		else if(check(s2, ch[i])) {
			id2 = i;
			for(int j = 1; j <= m; j++)
				s2[j] = ch[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		sort(ch[i] + 1, ch[i] + m + 1);
		if(id1 == i && check(ch[i], s2))
			cout << 0;
		else if(check(ch[i], s1))
			cout << 0;
		else
			cout << 1;
	}
	return 0;
}
