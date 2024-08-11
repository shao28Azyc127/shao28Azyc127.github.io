#include<bits/stdc++.h>
using namespace std;

int s[10000000] = {};
int l[10000000][2] = {};
int n;

stack <int> a;
stack <int> b;

int main()
{
    freopen("game.in", r ,stdin);
    freopen("game.out", w, stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        s[i] = int(c - 96);
    }
    a.push(-1);
    b.push(-1);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool f = true;
            if ((j - i) % 2 == 1)
            {
                for (int k = i; k <= (i + j) / 2; k++)
                {
                    if (s[k] != s[j - k + i])
                    {
                        f = false;
                    }
                }
                if (f)
                {
                    l[sum][0] = i;
                    l[sum][1] = j;
                    sum++;
                }
            }
        }
    }
    int sum0 = sum;
    for (int i = 0; i < sum0 ; i++)
    {
        for (int j = 0; j < sum0; j++)
        {
            if (l[i][1] + 1 == l[j][0])
            {
                l[sum0][0] = l[i][0];
                l[sum0][1] = l[j][1];
                sum0++;
            }
        }
    }
    cout << sum0 << endl;
    return 0;
}
