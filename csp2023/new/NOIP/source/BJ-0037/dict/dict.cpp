/*
Shall I compare thee to a summer's day?
Thou art more lovely and more temperate:
Rough winds do shake the darling buds of May,
And summer's lease hath all too short a date;
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 3000;

int n, m;
string s[N + 5], inv[N + 5];

string pre[N + 5], suf[N + 5];

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		sort(s[i].begin(), s[i].end());
		inv[i] = s[i];
		reverse(inv[i].begin(), inv[i].end());
	}

	pre[1] = inv[1];
	for (int i = 2; i <= n; i++)
	{
		pre[i] = min(pre[i - 1], inv[i]);
	}
	suf[n] = inv[n];
	for (int i = n - 1; i > 0; i--)
	{
		suf[i] = min(suf[i + 1], inv[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		bool ok = true;
		if (i > 1)
			ok &= (s[i] < pre[i - 1]);
		if (i < n)
			ok &= (s[i] < suf[i + 1]);
		if (ok)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	return 0;
}
