#include <iostream>
#include <cstring>
using namespace std;
const int NR = 1e6 + 10;
bool flag[NR];
int a[NR];
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) a[i] = i;
    memset(flag, true, sizeof(flag));
    int ans, las, remain = n;
    while(remain)
    {
        int cnt = 0;
        ans ++;
        bool fir = false;
        for(int x = 1; x <= n; x ++)
        {
            if(flag[x])
            {
                cnt ++;
                if(fir == false)
                {
                    remain --;
                    cnt = 0;
                    flag[x] = false;
                    fir = true;
                    if(x == n) las = ans;
                }
            }
            if(cnt == 3)
            {
                remain --;
                cnt = 0;
                flag[x] = false;
                if(x == n) las = ans;
            }

        }
        //for(int i = 1; i <= n; i ++) cout << (int)flag[i] << " ";
        //cout << endl;
    }
    cout << ans << " " << las;
    return 0;
}
