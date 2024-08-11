#include <iostream>
using namespace std;
typedef long long LL;

const LL XR = 1e9;
bool vis[XR];

int main()
{ 
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	LL n, cnt = 0, cur=0, dc=0, nc;
	cin >> n;
	while (cnt < n)
	{
		dc++;
		cur++;
		int pc = 0;
		for (LL i = cur; i <= n; i++)
		{
			if (!vis[i]) {
				if (pc % 3 == 0) {
					pc = 3;	
					cnt++;
					vis[i] = true;
					if (i == n) nc = dc;
				}
				pc--;
			}
		}
	}
	cout << dc << " " << nc << endl;
}
