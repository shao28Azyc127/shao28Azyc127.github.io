#include<bits/stdc++.h>
using namespace std;

int n;

int dg(int x){
	if(x == 1)
	{
		return 1;
	}
	else
	{
		if(x % 2 == 1)
		{
			return dg(ceil(x / 2)) + 1;
		}
		else
		{
			return dg(ceil(x / 2) + 1) + 1;
		}
	}
}

int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	cout << dg(n) << " " << dg(n) << endl;
 	return 0;
}
