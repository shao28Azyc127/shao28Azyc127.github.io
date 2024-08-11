#include <bits/stdc++.h>
using namespace std;
int n,m;
char words[3005][3005];
char cmpa1[3005][3005],cmpa2[3005][3005];

bool cmp1(char x,char y)
{
    return x < y;
}

bool cmp2(char x,char y)
{
    return x > y;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            cin >> words[i][j];
        }
    }
    if (n == 1) printf("1");
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            //cout << words[i][j];
            cmpa1[i][j] = words[i][j];
            cmpa2[i][j] = words[i][j];
        }
        //cout << endl;
    }
    for (int i = 1;i <= n;i++)
    {
        sort(cmpa1[i] + 1,cmpa1[i] + m + 1,cmp1);
        sort(cmpa2[i] + 1,cmpa2[i] + m + 1,cmp2);
    }
    bool flag = false;
    for (int i = 1;i <= n;i++)
    {
        for (int k = 1;k <= n;k++)
        {
            for (int j = 1;j <= m;j++)
            {
                //cout << cmpa1[i][j] << " " << cmpa2[k][j];
                if(cmpa1[i][j] == cmpa2[k][j])
                {
                    //cout << " =" << endl;
                    continue;
                }
                else if(cmpa1[i][j] < cmpa2[k][j])
                {
                    flag = true;
                    //cout << " <" << endl;
                    break;
                }
                else if (cmpa1[i][j] > cmpa2[k][j])
                {
                    flag = false;
                    //cout << " >" << endl;
                    break;
                }
            }
            if (flag == false) break;
        }
        if (flag == true)
        {
            printf("1");
            flag = false;
        }
        else printf("0");
    }
    return 0;
}
