#include<iostream>
using namespace std;
int a[9][6],x[6];
int f(int x,int y)
{
    if(x < y) return y-x;
    return y+10-x;
}
bool check(int a[],int b[])
{
    int diff = 0,d1 = 0,d2 = 0;
    for(int i = 1;i <= 5;i++)
        if(a[i] != b[i])
        {
            if(!diff) d1 = i;
            else d2 = i;
            diff++;
        }
    if(diff == 1) return 0;
    if(diff == 2 && d2-d1 == 1 && f(a[d1],b[d1]) == f(a[d2],b[d2])) return 0;
    return 1;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= 5;j++)
            scanf("%d",&a[i][j]);
    int ans = 0;
    for(x[1] = 0;x[1] <= 9;x[1]++)
        for(x[2] = 0;x[2] <= 9;x[2]++)
            for(x[3] = 0;x[3] <= 9;x[3]++)
                for(x[4] = 0;x[4] <= 9;x[4]++)
                    for(x[5] = 0;x[5] <= 9;x[5]++)
                    {
                        bool flag = 1;
                        for(int i = 1;i <= n;i++)
                            if(check(x,a[i]))
                            {
                                flag = 0;
                                break;
                            }
                        if(flag) ans++;
                    }
    cout << ans << endl;
    return 0;
}