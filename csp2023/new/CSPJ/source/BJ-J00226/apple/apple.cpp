#include<iostream>
#include<stdio.h>
using namespace std;
int n;
bool f[1000001], flag;
int cnt, nday;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(!flag)
    {
        cnt++;
        flag = 1;
        int c = 0;
        bool qwq = 1;
        for(int i = 1; i <= n; i++)
        {
            if((c%3) == 0 && !f[i])
            {
                if(i == n)
                {
                    nday = cnt;
                }
                f[i] = 1;
                c++;
            }
            else
            {
                if(!f[i]) c++;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(!f[i])
            {
                flag = 0;
                break;
            }
        }
    }
    cout << cnt << " " << nday;
    return 0;
}
