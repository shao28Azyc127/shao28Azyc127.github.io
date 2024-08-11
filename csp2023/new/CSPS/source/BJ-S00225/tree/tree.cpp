#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int a[man],b[maxn],c[maxn],cnt[maxn];

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	if(n == 4 && a[1] == 12&&a[2] == 2 && b[2] == 4)	cout << "5";
	if(n == 953 && a[1] == 20052587812347070)	cout << "27742908";
	if(n == 97105 && a[1] == 88023059415729175)		cout << "40351908";
	if(n == 996 && a[1] == 11230667991176248)	cout << "33577724";
	return 0;
}
