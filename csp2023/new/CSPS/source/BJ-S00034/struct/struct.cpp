#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int n, op, k;
string s;

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> s >> k;
            for (int j = 1; j <= k; j++)
            {
                string t, n;
                cin >> t >> n;
            }
        }
    }

    // cout << 

    fclose(stdin);
    fclose(stdout);
    return 0;
}