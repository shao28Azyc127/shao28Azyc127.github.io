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
        for(int i = 1; i <= n; i++) //ö�����е����
        {
            top = 0;
            for(int j = i; j <= n; j++) //��ǰ��λ��
            {
                sta[++top] = a[j];
                if(top >= 2 && sta[top]==sta[top-1])//��������
                {
                    // printf("�����ˣ�i=%d��j=%d\n",i,j);
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
    else //��n=200000����
    {
        printf("hello world!\n"); //
    }
    return 0;
}