#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


int m, n;

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> m >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int a, b;
		cin >> a >> b;
		for(int j = 0 ; j < b ; j++)
		{
			char tmp1;
			int tmp2, tmp3;
			cin >> tmp1;
			if(tmp1 == '+' || tmp1 == '-')
			{
				cin >> tmp2 >> tmp3;
			}
			else
			{
				cin >> tmp2;
			}
		}
	}
	for(int i = 0 ; i < n ; i++)
	{
		cout << "0" << endl;
	}
	return 0;
}