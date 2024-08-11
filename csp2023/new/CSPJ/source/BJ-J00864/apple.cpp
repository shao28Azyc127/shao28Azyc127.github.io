#include <bits/stdc++.h>
using namespace std;

int r[1000010], l[1000010], num, cnt;

int main()
{
    int n;
    cin >> n;
    num = n;
    r[0] = 1;
    for(int i = 1;i <= n; i++)
    {
        r[i] = i + 1;
        l[i] = i - 1;
    }
    while(num)
    {
        cnt++;
        for(int i = r[0];i <= n; i = r[r[r[i]]])
        {
            if(i == r[0]) r[0] = r[i];
            if(i == n) cout << cnt << " ";
            r[l[i]] = r[i];
            l[r[i]] = l[i];
            num--;
        }
    }
    cout << cnt << endl;
    return 0;
}
