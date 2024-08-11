#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct Apple
{
	int idx;
	bool exist;
	Apple() : idx(0), exist(true) {}
	Apple(int i, bool e) : idx(i), exist(e) {}
	virtual ~Apple() {}
};
vector<Apple> apples;
int n_taken_day;
void clear_taken()
{
start_clear:
	for (int i = 0; i < apples.size(); i++)
	{
		if (!apples[i].exist)
		{
			apples.erase(apples.begin() + i);
			goto start_clear;
		}
	}
}

void take(int day, int n)
{
	for (int i = 0; i < apples.size(); i += 3)
	{
		if (apples[i].idx == n) n_taken_day = day;
		apples[i].exist = false;
	}
	clear_taken();
}
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) apples.push_back(Apple(i, true));
	int day = 1;
	while (!apples.empty()) take(day++, n);
	cout << day - 1 << ' ' << n_taken_day << endl;
	return 0;
}
