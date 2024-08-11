#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int a[19][16]; //a[i][j]表示第i个锁的第j个数
int kind[19][182][16]; //kind[i][j][k]代表第i个锁环的第j种情况的第k个数字
bool flag[10][10][10][10][10][10]; //代表一种情况是否可行
long long ans;


int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    memset(flag, false, sizeof(flag));

    scanf("%d",&n);
    for(int i = 1; i <= n ;i++) 
        for(int j = 1; j <= 5; j++)
            scanf("%d",&a[i][j]);


    for(int i = 1; i <= n; i++) //第几个锁环
    {
        int cnt = 0;

        //复制数字

        for(int j = 1; j <= 81; j++)
        {
            for(int k = 1; k <= 5; k++)
            {
                kind[i][j][k] = a[i][k];
            }
        }

        //改变一个数字

        for(int j = 1; j <= 5; j++) //改变的是第几个数字
        {
            for(int k = 1; k <= 9; k++) //这个数字加几
            {
                kind[i][++cnt][j] = (a[i][j] + k) % 10;
            }
        }

        //改变两个数字
        
        for(int j = 1; j <= 4; j++)
        {
            for(int k = 1; k <= 9; k++)
            {
                kind[i][++cnt][j] = (a[i][j] + k) % 10;
                kind[i][cnt][j+1] = (a[i][j+1] + k) % 10;
            }
        }

        //打表
        
        for(int j = 1; j <= 81; j++)
        {
            // for(int k = 1; k <= 5; k++) printf("%d ",kind[i][j][k]);
            // printf("\n");

            int a1 = kind[i][j][1];
            int a2 = kind[i][j][2];
            int a3 = kind[i][j][3];
            int a4 = kind[i][j][4];
            int a5 = kind[i][j][5];
            flag[i][a1][a2][a3][a4][a5] = true;
        }
    }

    for(int i = 0; i <= 9; i++)
        for(int j = 0; j <= 9; j++)
            for(int k = 0; k <= 9; k++)
                for(int l = 0; l <= 9; l++)
                    for(int m = 0; m <= 9; m++)
                    {
                        bool f = true;
                        for(int t = 1; t <= n; t++)
                        {
                            if(!flag[t][i][j][k][l][m])
                            {
                                f = false;
                            }
                        }

                        if(f) 
                        {
                            ans++;
                            // printf("a[1][%d][%d][%d][%d][%d] = %d\n",i,j,k,l,m,flag[1][i][j][k][l][m]);
                        }
                    }


    printf("%lld\n",ans);
    return 0;
}