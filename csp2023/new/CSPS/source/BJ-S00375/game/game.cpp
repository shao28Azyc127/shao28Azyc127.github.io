#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int a[200010], n;

int sta[200010], top;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    scanf("%d",&n);
    char c = getchar();
    for(int i = 1; i <= n; i++)
    {
        c = getchar();
        a[i] = c;
    }

    int ans = 0;

    if(n <= 8000000) //
    {
        for(int i = 1; i <= n; i++) //枚举序列的起点
        {
            top = 0;
            for(int j = i; j <= n; j++) //当前的位置
            {
                sta[++top] = a[j];
                if(top >= 2 && sta[top]==sta[top-1])//可以消除
                {
                    // printf("消除了，i=%d，j=%d\n",i,j);
                    top -= 2;
                    if(top == 0)
                    {
                        ans++;
                        // printf("ans++, i=%d, j=%d\n",i,j);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    else //用n=200000计算
    {
        printf("hello world!\n"); //
    }
    return 0;
}