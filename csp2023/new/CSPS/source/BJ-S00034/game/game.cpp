#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int n, cnt = 0;
bool b[2000007] = {};
string x;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n >> x;
    
    for (int i = 1; i <= n/2; i++)
    {
        int a = 0;
        while (true)
        {
            if (a == x.length()) break;
            if (x[a]==x[a+1])
            {
                cnt++;
                x.erase(a, 2);
                break;
            }
            a++;
        }
    }
    
    if (x.length() == 0)
    {
        cout << cnt + 1;
    }
    else
    {
        cout << cnt * x.length();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}