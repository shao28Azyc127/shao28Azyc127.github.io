#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in", r, stdin);
    freopen("apple.out", w, stdout);
    int n;
    cin >> n;
    int list[n];
    for (int k = 0; k < n; k++)
    {
        list[k] = 1;
    }
    int sum = n, i;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j += 2)
        {
            if (j == n - 1)
            {
                cout << i + 1 << endl;
            }
            if (list[j] == 1)
            {
                list[j] = 0;
            }
            else
            {
                j++;
            }
        }
    }
    cout << i + 1 << endl;
    return 0;
}