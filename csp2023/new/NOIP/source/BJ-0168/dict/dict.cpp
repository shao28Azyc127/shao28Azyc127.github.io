#include <bits/stdc++.h>
using namespace std;

const int NR = 3010;
string s[NR];
int cnt[30];

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
			cnt[j] = 0;
		for (int j = 1; j <= m; j++)
		{
			char c = ' ';
			while (c < 'a' || c > 'z') c = getchar();
			cnt[c - 'a']++;
		}
		s[i] = "";
		for (int j = 0; j < 26; j++)
			while (cnt[j]--) s[i] += char(j + 'a');
	}
	string t(m, 'z');
	for (int i = 1; i <= n; i++)
		reverse(s[i].begin(), s[i].end()), t = min(t, s[i]);
	int p = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == t) p = (p ? 0 : i);
	for (int i = 1; i <= n; i++)
	{
		reverse(s[i].begin(), s[i].end());
		printf("%d", int(s[i] < t || (s[i] == t && i == p)));
	}
	printf("\n");
	return 0;
}