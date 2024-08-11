#include<bits/stdc++.h>
using namespace std;

int t, m;

bool gcd(int ip, int iq){
	for(int i = 2; i <= sqrt(ip); i++)
	{
		if(iq % i == 0 || iq % (ip / i) == 0)
		{
			return false;
		}
	}
	if(iq % ip == 0)return false;
	return true;
}

void check(int x, int px, int qx){
	for(int px = -m; px <= m; px++)
	{
		for(int qx = 1; qx <= m; qx++)
		{
			if(abs(qx) > m)
			{
				break;
			}
			if(!gcd(px, qx) || double(x) != double(px) / double(qx))
			{
				break;
			}
			//double ans = p / q;
			if(qx == 1)
			{
				cout << px << endl;
			}
			else cout << px << "/" << qx << endl;
		}
		if(abs(px) > m)
		{
			break;
		}
	}
	return;
}

int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> t >> m;
	for(int i = 1; i <= t; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(b == 0 && c == 0)
		{
			cout << 0 << endl;
			continue;
		}
		if(b * b - 4 * a * c < 0)
		{
			cout << "NO" << endl;
			continue;
		}
		else if(b * b - 4 * a * c == 0)
		{
			int x = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
			int p = -m, q = 1;
			check(x, p, q);
			continue;
		}
		/*else
		{
			int x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
			int x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
			continue;
		}*/
	}
	return 0;
}