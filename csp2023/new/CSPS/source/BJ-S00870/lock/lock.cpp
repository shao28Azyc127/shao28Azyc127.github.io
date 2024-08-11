#include <bits/stdc++.h>
using namespace std;

int n;
int ans[90];
int b[90];
bool flag[90];
int a[6];
int ansn;
int build(int a5,int a4,int a3,int a2,int a1)
{
    return (a5 * 10000 + a4 * 1000 + a3 * 100 + a2 * 10 + a1);
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    ansn = 0;
    for(int t = 1;t <= n;t++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin >> a[5] >> a[4] >> a[3] >> a[2] >> a[1];
        int T = 0;
        for(int i = 1;i <= 5;i++)
            for(int j = 1;j <= 9;j++)
            {
                a[i] = (a[i] + j) % 10;
                int c = build(a[5],a[4],a[3],a[2],a[1]);
                if(t == 1)
                {
                    ansn++;
                    ans[ansn] = c;
                    flag[ansn] = 1;
                }
                T++;
                b[T] = c;
                a[i] = (a[i] + 10 - j) % 10; 
            }
        for(int i = 1;i <= 4;i++)
        {
            for(int j = 1;j <= 9;j++)
            {
                a[i] = (a[i] + j) % 10;
                a[i+1] = (a[i+1] + j) % 10;
                int c = build(a[5],a[4],a[3],a[2],a[1]);
                if(t == 1)
                {
                    ansn++;
                    ans[ansn] = c;
                    flag[ansn] = 1;
                }
                T++;
                b[T] = c;
                a[i] = (a[i] + 10 - j) % 10; 
                a[i+1] = (a[i+1] + 10 - j) % 10;
            }
        }
        if(t != 1)
            for(int i = 1;i <= ansn;i++)
            {
                if(!flag[i]) continue;
                bool alive = 0;
                for(int j = 1;j <= T;j++)
                {
                    if(ans[i] == b[j])
                    {
                        alive = 1; break;
                    }
                }
                if(!alive)
                    flag[i] = 0;
            }
    }    
    int sum = 0;
    for(int i = 1;i <= ansn;i++)
        if(flag[i]) sum++;
    cout << sum << endl;
    return 0;
}