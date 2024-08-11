#include <bits/stdc++.h>
using namespace std;

struct Apple
{
	int day;
	bool d;
	Apple()
	{
		day = 0;
		d = false;
	}
};

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, curr, day = 1;
	bool flag;
	vector<Apple> apple;
	cin >> n;
	apple.resize(n + 10);
	
	while (true)
	{
		curr = 1;
		while (apple[curr].d)
			curr++;
		if (curr > n)
			break;
		while (true)
		{
			apple[curr].d = true;
			apple[curr].day = day;
			while(curr <= n && apple[curr].d)
				curr++;
			curr++;
			if (curr > n)
				break;
			while(curr <= n && apple[curr].d)
				curr++;
			curr++;
			if (curr > n)
				break;
			while(curr <= n && apple[curr].d)
				curr++;
			if (curr > n)
				break;
		}
		day++;
	}
	
	printf("%d %d", day - 1, apple[n].day);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
