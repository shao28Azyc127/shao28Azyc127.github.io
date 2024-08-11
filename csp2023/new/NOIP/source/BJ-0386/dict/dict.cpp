#include <fstream>
#include <algorithm>
#include <cstring>
#define N 3010

using namespace std;

ifstream cin("dict.in");
ofstream cout("dict.out");

string a[N];

bool cmpa(char x, char y)
{
	return x < y;
}

bool cmpb(char x, char y)
{
	return x > y;
}

int main()
{
	int n, m;
	int l, k;
	char w[N];
	string s, s1, s2;
	s1 = s2 = "0";
	cin >> n >> m;
	if (n == 1)
		cout << 1;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> w;
			l = strlen(w);
			sort(w, w + l, cmpa);
			a[i] = w;
			sort(w, w + l, cmpb);
			s = w;
			if (s1 == "0" || s < s1)
			{
				s2 = s1;
				s1 = s;
				k = i;
			}
			else if (s2 == "0" || s < s2)
				s2 = s;
		}
		for (int i = 1; i <= n; i++)
			if (k == i)
			{
				if (a[i] < s2)
					cout << 1;
				else
					cout << 0;
			}
			else
			{
				if (a[i] < s1)
					cout << 1;
				else
					cout << 0;
			}
	}
	return 0;
}