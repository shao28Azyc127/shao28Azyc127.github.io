#include <bits/stdc++.h>
using namespace std;
int n,question[20][6];
bool flag[6];
int ans = 0;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= 5;j++)
        {
            scanf("%d",&question[i][j]);
            if (i >= 2)
            {
                if(question[i - 1][j] == question[i][j])
                {
                    continue;
                }
                else flag[j] = true;
            }
        }
    }
    if (n == 1)
    {
        printf("81");
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for (int i = 1;i <= 5;i++)
    {
        if (flag[i] == true)
        {
            ans += 10;
        }
    }
    printf("%d",ans - 10);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
