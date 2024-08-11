#include<bits/stdc++.h>

using namespace std;

int read()
{
	int s = 0, ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
	return s;
}

struct cond
{
	int a[5];

	void input()
	{
		for(int i = 0; i < 5; i++)
			cin >> a[i];
	}

	int inte()
	{
		return a[0] * 10000 + a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4];
	}
}a[8];

bool b[8][100000];
int cand[81];

void work(int id)
{
	cond tmp = a[id];
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			tmp.a[i] = (tmp.a[i] + 1) % 10;
			b[id][tmp.inte()] = 1;
			cand[i * 9 + j] = tmp.inte();
		}
		tmp.a[i] = (tmp.a[i] + 1) % 10;
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			tmp.a[i] = (tmp.a[i] + 1) % 10;
			tmp.a[i + 1] = (tmp.a[i + 1] + 1) % 10;
			b[id][tmp.inte()] = 1;
			cand[45 + i * 9 + j] = tmp.inte();
		}
		tmp.a[i] = (tmp.a[i] + 1) % 10;
		tmp.a[i + 1] = (tmp.a[i + 1] + 1) % 10;
	}
}

int n, ans;

int main()
{
	#ifndef DEBUG	
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	#endif
	n = read();
	for(int i = 0; i < n; i++)
	{
		a[i].input();
		work(i);
	}
	for(int i = 0; i < 81; i++)
	{
		int flag = 1;
		for(int j = 0; j < n; j++)
		{
			if(!b[j][cand[i]])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
