#include<iostream>
#include<cstdio>
using namespace std;
int n , n1 , ans1 , ans2;
int main()
{
	freopen("apple.in" , "r" , stdin);
	freopen("apple.out" , "w" , stdout);
	cin >> n;
	n1 = n;
	while(n1 > 0)
	{
		ans1 ++;
		if(n1 % 3 == 1 && !ans2)ans2 = ans1;
		n1 = n1 - (n1 + 2) / 3;
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}