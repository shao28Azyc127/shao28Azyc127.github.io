#include <iostream>
#include <cstdio>
using namespace std;
int a[1000005];
int main()
{
	
	freopen("apple.in" , "r" , stdin);
	freopen("apple.out" , "w" , stdout);
	
	int n , cur , t = 0;
	cin >> n;
	while(true)
	{
		cur = 1;
		while(a[cur] != 0)
		{
			cur++;
		}
		if(cur > n) break;
		t++;
		int time = 0;
		for(int i = cur;i <= n;i++)
		{
			if(a[i] != 0) continue;
			time++;
			if(time % 3 == 1)
			{
				a[i] = t;
			}
		}
	}
	cout << t << " " << a[n] << endl;
	return 0;
}