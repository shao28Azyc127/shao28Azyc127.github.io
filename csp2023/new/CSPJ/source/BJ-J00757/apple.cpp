#include  <iostream>
#include  <cstdio>
using namespace std;
const int N = 1e6 + 5;
bool f[N] , flag = 0;
int id = 1 , ans , cnt = 0 , n;
bool check()
{
    for(int i = 1; i <= n; i++)
    {
        if(f[i] == 0) return true;
    }
    return false;
}
int main()
{
    freopen("apple.in" , "r" , stdin);
    freopen("apple.out" , "w" , stdout);
    cin >> n;
    for(int i = 1; i <= n && check(); i++)
    {
        cnt++;
        for( ; ; )
        {
            //cout << id << endl;
            f[id] = 1;
            for(int k = 1; k <= 3; k++)
            {
                id++;
                while(f[id])
                {
                    id++;
                }

            }
            if(id > n) break;
            if(id == n && !flag)
            {
                ans = i;
                f[id] = 1;
                flag = 1;
                break;
            }
        }
        id = 1;
        while(f[id]) id++;
    }
    if(ans == 0 && !flag)
    {
        ans = cnt;
        //cout << "skjhdkj\n";
    }
    cout << cnt << " " << ans;
    return 0;
}
