#include<bits/stdc++.h>
using namespace std;

int p[1000010], q[1000010];
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d", &n);
    int a = 1, b = 2, c = 3;
    int cnt = 2;
    while(c<n)
    {
        c = a + b;
        a = b;
        b = c;
        cnt++;
    }
    if(n == 1) cout <<1  << " ";
    else if(n == 2) cout << 2 << " ";
    else if(n == 3) cout << 3 << " ";
    else if(c == n) cout << cnt << " ";
    else cout << cnt - 1 << " ";

    p[1] = 3;
    q[0] = q[1] = 1;
    cnt = 0;
    while(true)
    {
        cnt++;
        if(n % p[cnt] == q[cnt])
        {
            cout << cnt << endl;
            return 0;
        }
        q[cnt + 1] = q[cnt] + q[cnt - 1];
        p[cnt + 1] = q[cnt] + p[cnt];
    }
    return 0;
}
