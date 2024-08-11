#include <bits/stdc++.h>
using namespace std;

int sit[10][10];
int diff[10], dg[10], n, ans;

bool check(int num, int d[])
{
    int cntm = 0, cntnm = 0;
    diff[1] = diff[2] = diff[3] = diff[4] = diff[5] = 0;
    for(int i = 1; i <= 5; i++)
    {
        if(sit[num][i] == d[i])
        {
            cntm++;
        }
        else
        {
            diff[++cntnm] = i;
        }
    }
    if(cntm < 3)
    {
        //cout << "m<3 " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << " " << d[5] << endl;
        return false;
    }
    if(cntm == 3)
    {
        if(diff[2] - diff[1] != 1)
        {
            //cout << "dnc " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << " " << d[5] << endl;
            return false;
        }
        int dis1p, dis1n, dis2p, dis2n;
        if(sit[num][diff[1]] >= d[diff[1]])
        {
            dis1n = sit[num][diff[1]] - d[diff[1]];
            dis1p = (10 - sit[num][diff[1]]) + d[diff[1]];
            dis1n %= 10;
            dis1p %= 10;
        }
        else
        {
            dis1n = (10 - d[diff[1]]) + sit[num][diff[1]];
            dis1p = d[diff[1]] - sit[num][diff[1]];
            dis1n %= 10;
            dis1p %= 10;
        }
        if(sit[num][diff[2]] >= d[diff[2]])
        {
            dis2n = sit[num][diff[2]] - d[diff[2]];
            dis2p = (10 - sit[num][diff[2]]) + d[diff[2]];
            dis2n %= 10;
            dis2p %= 10;
        }
        else
        {
            dis2n = (10 - d[diff[2]]) + sit[num][diff[2]];
            dis2p = d[diff[2]] - sit[num][diff[2]];
            dis2n %= 10;
            dis2p %= 10;
        }
        if(dis1p == dis2p || dis1n == dis2n)
        {
            //cout << "dcc " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << " " << d[5] << endl;
            return true;
        }
        //cout << "dcw " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << " " << d[5] << endl;
        return false;
    }
    else if(cntm != 5)
    {
        //cout << "dsc " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << " " << d[5] << endl;
        return true;
    }
    //cout << "dfw " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << " " << d[5] << endl;
    return false;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cin >> sit[i][j];
        }
    }
    for(int dg1 = 0; dg1 < 10; dg1++)
    {
        for(int dg2 = 0; dg2 < 10; dg2++)
        {
            for(int dg3 = 0; dg3 < 10; dg3++)
            {
                for(int dg4 = 0; dg4 < 10; dg4++)
                {
                    for(int dg5 = 0; dg5 < 10; dg5++)
                    {
                        bool flag = true;
                        for(int i = 1; i <= n; i++)
                        {
                            dg[1] = dg1;
                            dg[2] = dg2;
                            dg[3] = dg3;
                            dg[4] = dg4;
                            dg[5] = dg5;
                            if(!check(i, dg))
                            {
                                flag = false;
                                break;
                            }
                        }
                        if(flag)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}