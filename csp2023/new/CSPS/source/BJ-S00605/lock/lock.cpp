
#include <bits/stdc++.h>
using namespace std;

int a[10][6];
int ans[81][5];
int ans2[81][5];
int ans3[81][5];
int aa = 0;
int pd(int a1, int a2, int a3, int a4, int a5)
{
    for(int j = 0; j < 81; j++)
    {
        ans2[j][0] = a1;
        ans2[j][1] = a2;
        ans2[j][2] = a3;
        ans2[j][3] = a4;
        ans2[j][4] = a5;
    }

    for(int x = 0; x < 5; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            ans2[(x * 9) + y][x] = (ans2[(x * 9) + y][x] + y + 1) % 10;
        }
    }

    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            ans2[46 + (x * 9) + y][x] = (ans2[46 + (x * 9) + y ][x] + y + 1) % 10;
            ans2[46 + (x * 9) + y][x + 1] = (ans2[46 + (x * 9) + y][x + 1] + y + 1) % 10;
        }
    }

    for(int i = 0; i < 81; i++)
    {
        for(int j = 0; j < 81; j++)
        {
            if(ans[i][0] == ans2[j][0] && ans[i][1] == ans2[j][1] && ans[i][2] == ans2[j][2] && ans[i][3] == ans2[j][3] && ans[i][4] == ans2[j][4])
            {
                ans3[i][0] = ans[i][0];
                ans3[i][1] = ans[i][1];
                ans3[i][2] = ans[i][2];
                ans3[i][3] = ans[i][3];
                ans3[i][4] = ans[i][4];
                break;
            }
        }
    }

    for(int i = 0; i < 81; i++)
    {
        ans[i][0] = ans3[i][0];
        ans[i][1] = ans3[i][1];
        ans[i][2] = ans3[i][2];
        ans[i][3] = ans3[i][3];
        ans[i][4] = ans3[i][4];
    }
}

int main()
{
freopen("lock.in","r",stdin);
freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        cin >> a[i][1];
        cin >> a[i][2];
        cin >> a[i][3];
        cin >> a[i][4];
    }


    int t = 0;
    for(int j = 0; j < 81; j++)
    {
        ans[j][0] = a[0][0];
        ans[j][1] = a[0][1];
        ans[j][2] = a[0][2];
        ans[j][3] = a[0][3];
        ans[j][4] = a[0][4];
    }

    for(int x = 0; x < 5; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            ans[(x * 9) + y][x] = (ans[(x * 9) + y][x] + y + 1) % 10;
        }
    }

    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            ans[46 + (x * 9) + y][x] = (ans[46 + (x * 9) + y ][x] + y + 1) % 10;
            ans[46 + (x * 9) + y][x + 1] = (ans[46 + (x * 9) + y][x + 1] + y + 1) % 10;
        }
    }
if(n >= 2)
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 81; j++)
        {
            ans3[j][0] = 0;
            ans3[j][1] = 0;
            ans3[j][2] = 0;
            ans3[j][3] = 0;
            ans3[j][4] = 0;
        }
        pd(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
    }
    aa-=3;
}
    for(int j = 0; j < 81; j++)
    {
        if(ans[j][0] + ans[j][1] + ans[j][2] + ans[j][3] + ans[j][4] != 0)
        {
            aa++;
        }
    }

    cout << aa;
    fclose(stdin);
    fclose(stdout);
    return 0;
}