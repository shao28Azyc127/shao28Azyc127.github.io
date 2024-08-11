#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3010;

int cls[Maxn][Maxn];
int maxc [Maxn][Maxn];
int minest = 1;
int a[Maxn] = {};

bool cmp (int a, int b) {
	return a > b;
}

int main () {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m;
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			char c;
			scanf ("%c", &c);
			if (c == '\n') scanf ("%c", &c);
			maxc[i][j] = cls[i][j] = c - 'a';
			//cout <<char(cls[i][j] + 'a');
		}
		//cout <<endl;
		sort (maxc[i] + 1, maxc[i] + m + 1, cmp);
	}
	for (int i = 1; i <= n; i ++) {
		int tot = 1;
		while (maxc[minest][tot] == maxc[i][tot] && tot <= m) 
			tot ++;
		//printf ("i : %d, tot : %d \n", i, tot);
		if (maxc[minest][tot] > maxc[i][tot]) 
			minest = i;
	}
	//minest = 8;
	//cout <<minest <<"\n";
	//for (int i = 1; i <= n; i ++) {
	//	for (int j = 1; j <= m; j ++) {
	//		printf ("%c%c", maxc[i][j] + 'a', " \n"[j == m]);
	//	}
	//}
	bool flag = true;
	for (int i = 1; i <= n; i ++) {
		if (i == minest)
			continue;
		int tot = 1;
		while (maxc[minest][m - tot + 1] == maxc[i][tot] && tot <= m) tot ++;
		if (maxc[minest][m - tot + 1] >= maxc[i][tot]){
			flag = false;
			break;
		} 
	}
	a[minest] = int(flag);
	for (int i = 1; i <= n; i ++) {
		if (i == minest)
			continue;
		int tot = 1;
		while (maxc[minest][tot] == maxc[i][m - tot + 1] && tot <= m) tot ++;
		//printf("maxc[%d][%d] >= maxc[%d][%d] : %c ? %c : %d\n", 
		//i, m - tot + 1, minest, tot, maxc[i][m - tot + 1] + 'a', maxc[minest][tot] + 'a',
		//(int)maxc[i][m - tot + 1] >= maxc[minest][tot]); 
		if (maxc[i][m - tot + 1] >= maxc[minest][tot]){
			a[i] = 0;
		} else {
			a[i] = 1;
		}
	}
	for (int i = 1; i <= n; i ++)
		printf ("%d", a[i]);
	printf ("\n"); 
 	return 0;
}
