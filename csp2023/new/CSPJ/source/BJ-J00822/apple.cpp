#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int t = n,cnt = 0;
    while(t > 0)
    {
        int tt = t / 3;
        if(t % 3 != 0) t--;
        t -= tt;
        cnt++;
    }
    cout << cnt;
    t = n;
    cnt = 0;
    while(t > 0)
    {
        if(t % 3 == 1)
        {
            cout << " " << cnt + 1;
            break;
        }
        int tt = t / 3;
        if(t % 3 != 0) t--;
        t -= tt;
        cnt++;
    }
    return 0;
}
