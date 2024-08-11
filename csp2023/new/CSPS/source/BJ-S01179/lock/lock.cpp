#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("lock.in", r ,stdin);
    freopen("lock.out", w, stdout);
    int n = 0;
    int R[10][5] = {};
    int T[5] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> R[i][j];
        }
    }
    if (n == 1)
    {
        cout << "81" << endl;
    }
    int sim = 0, sl[5] = {};
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (R[i][j] == R[i - 1][j])
            {
                sim++;
                sl[j] = 1;
            }
        }
        for (int j = 1; j < 4; j++)
        {
            if (sl[j] == 0)
            {
                sl[j + 1] = 0;
                sl[j - 1] = 0;
                j++;
            }
        }
        for (int j = 0; j < 5; j++)
        {
            if (sl[j] == 1)
            {
                T[j] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (T[i] == 0)
        {
            sum += 9;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (T[i - 1] == 0 && T[i] == 0)
        {
            sum += 9;
        }
    }
    cout << sum << endl;
    return 0;
}
