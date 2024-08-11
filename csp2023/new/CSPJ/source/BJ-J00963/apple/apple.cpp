#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out" , "w", stdout);
    int n, num = 0, day, M[1000000005];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        M[i]= i;
    }
    for (int i = 1; i <= n; i++)
    {
        M[i] = 0;
        for (int j = i; j <= n; j += 2)
        {
            M[j] = 0;
        }
        if (M[n] == 0)
        {
            day = i;
        }
        num += 1;
    }
    cout << num << " " << day;
    return 0;
}