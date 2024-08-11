#include <bits/stdc++.h>
//#define N 101
//#define N 11
//#define D 101
#define N 100001
using namespace std;
int a[N], b[N], distanc[N], distanc2[N], dpans, YOUXIANG;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 2; i <= n; i ++)
    {
        cin >> distanc[i];
        distanc2[i] = distanc[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if (i == 1)
        {
            b[i] = a[i];
            continue;
        }
        else
        {

            b[i] = min(b[i - 1], a[i]);
            YOUXIANG -= distanc[i] * d;
            int x = (-YOUXIANG) / d;
            if (x * d != -YOUXIANG)
            {
                x ++;
            }
            YOUXIANG += x * d;
            dpans += x * b[i];
            /*if (d * x == distanc[i])
            {
                dpans += x * b[i];
            }
            else
            {
                x ++;
                dpans += min(x * b[i], distanc2[i] / d * b[i]);
                distanc[i + 1] -= d * x - distanc[i];
            }*/
            dpans += x * b[i];

        }
        //for (int j = qianzhuihe[i - 1] + 1; j <= summ; j ++)
        //{
        //    if (j - qianzhuihe[i - 1] >= d)
        //    {
        //        dp[j] = min(dp[(j - d) / d * d] + a[i] * (d), dp[j]);
        //    }
    }
    cout << dpans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
