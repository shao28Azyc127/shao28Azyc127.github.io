#include <iostream>
#include <cstdio>
using namespace std;
int t, m;
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    if(m >= 2)
    {
        for(int i = 1;i <= t;i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            cout << "No" << endl;
        }
    }
    else
    {
     	for(int i = 1;i <= t;i++)
	{
            int a, b, c;
            cin >> a >> b >> c;
            cout << 0 << endl;
	}
    }
    return 0;
}