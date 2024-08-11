#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
struct wo
{
	string word;
	int num[30];
} words[3005];

bool checks(int nn, int mm)
{
	int st1 = -1 , st2 = -1;
	// bool flag1 = false, flag2 = false;
	for(int i = 0 ; i < 30 ; i++)
	{
		if(words[nn].num[i] != 0 && st1 == -1)
		{
			// flag1 = true;
			st1 = i;
		}
		if(words[mm].num[30-i-1] != 0 && st2 == -1)
		{
			st2 = 30-i-1;
		}
	}
	if(st1 < st2)
	{
		return true;
	}
	return false;
}

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < 30 ; j++)
		{
			words[i].num[j] = 0;
		}
		cin >> words[i].word;
		for(int j = 0 ; j < m ; j++)
		{
			words[i].num[words[i].word[j] - 'a']++;
		}
		// sort(words[i].max, words[i].max+m, greater<int>());
		// sort(words[i].min, words[i].min+m);
	}
	for(int i = 0 ; i < n ; i++)
	{
		bool flag = true;
		for(int j = 0 ; j < n ; j++)
		{
			if(i == j)
			{
				continue;
			}
			if(!checks(i, j))
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
	cout << endl;
	return 0;
}