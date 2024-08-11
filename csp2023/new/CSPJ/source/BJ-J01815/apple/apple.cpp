#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool a[500000005];

bool ___a(int n)
{
    for (int i = 1;i <= n;i++)
    {
        if (a[i])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    memset(a,true,sizeof a);
    int tot = 1,tot1 = 0;
    while (___a(n))
    {
        int cnt = 0;
        for (int i = 1;i <= n;i++)
        {
            if (a[i])
            {
                cnt++;
            }
            if (cnt % 3 == 1)
            {
                a[i] = false;
            }
        }
        if (a[n])
        {
            tot++;
        }
        tot1++;
    }
    cout << tot1 << " " << tot << endl;
    return 0;
}