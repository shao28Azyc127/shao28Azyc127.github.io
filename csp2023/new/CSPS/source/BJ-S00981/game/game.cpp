#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int n, ans;
string a;

string erases(string aaa, int ii, int jj)
{
	string tmp;
	for(int i = 0 ; i < aaa.size() ; i++)
	{
		if(i < ii || i > jj)
		{
			tmp += aaa[i];
		}
	}
	return tmp;
}

bool erasable(string aa)
{
	bool flag = true;
	while(flag && aa.size() > 0)
	{
		flag = false;
		vector<int> tmpp;
		for(int i = 0 ; i < aa.size()-1 ; i++)
		{
			if(aa[i] == aa[i+1])
			{
				flag = true;
				tmpp.emplace_back(i);
				i++;
			}
		}
		for(int i = tmpp.size()-1 ; i >= 0 ; i--)
		{
			// ans++;
			aa = erases(aa, tmpp[i], tmpp[i]+1);
		}
		while(tmpp.size() > 0)
		{
			tmpp.pop_back();
		}
		// cout << tmpp.size() << endl;
	}
	if(aa.size() > 0)
	{
		return false;
	}
	return true;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ans = 0;
	cin >> n;
	cin >> a;
	// cout << a << endl;
	// cout << a << endl;
	for(int i = 0; i < n-1 ; i++)
	{
		for(int j = i+1 ; j < n ; j++)
		{
			string tmppp;
			for(int k = i ; k <= j ; k++)
			{
				tmppp = tmppp + a[k];
			}
			// cout << tmppp << endl;
			if(erasable(tmppp))
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}