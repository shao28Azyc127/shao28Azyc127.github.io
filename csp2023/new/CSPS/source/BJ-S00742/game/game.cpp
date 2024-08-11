#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 * 2 + 5;
char a[N];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    int n, cnt = 1;
    cin>>n;

    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                continue;
            if(a[i] == a[j])
            {
                i++;
                cnt++;
                break;
            }
        }
    }

    cout<<cnt;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
