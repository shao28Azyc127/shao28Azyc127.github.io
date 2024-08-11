#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int rd[3010], Minn[3010], Maxn[3010];
int minn[3010][3010], maxn[3010][3010]; //the min and max dict_order without i
int premax[3010][3010], lastmax[3010][3010]; //0 = min, 1 = max


bool cmp(char a, char b)
{
    return a > b;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    scanf("%d%d",&n,&m);

    if(n == 1)
    {
        printf("1\n");
        return 0;
    }

    for(int i = 1; i <= n; i++)
    {
        char lj = getchar();
        for(int j = 1; j <= m; j++)
        {
            rd[j] = getchar();
            Minn[j] = Maxn[j] = rd[j];
        }
        sort(Minn+1, Minn+m+1);
        sort(Maxn+1, Maxn+m+1, cmp) ;
        for(int j = 1; j <= m; j++)
        {
            minn[i][j] = Minn[j];
            maxn[i][j] = Maxn[j];
        }
    }
    for(int j = 1; j <= m; j++)
        premax[0][j] = 200;
    for(int i = 1; i <= n; i++)
    {
        bool flag = false;
        for(int j = 1; j <= m; j++)
        {
            if(maxn[i][j] < premax[i-1][j])
            {
                flag = true;
                break;
            }
            if(maxn[i][j] > premax[i-1][j])
            {
                break;
            }
        }
        if(flag)
        {
            for(int j = 1; j <= m; j++)
            {
                premax[i][j] = maxn[i][j];
            }
        }
        else
        {
            for(int j = 1; j <= m; j++)
            {
                premax[i][j] = premax[i-1][j];
            }
        }
    }
    for(int j = 1; j <= m; j++)
        lastmax[n+1][j] = 200;
    for(int i = n; i >= 1; i--)
    {
        bool flag = false;
        for(int j = 1; j <= m; j++)
        {
            if(maxn[i][j] < lastmax[i+1][j])
            {
                flag = true;
                break;
            }
            if(maxn[i][j] > lastmax[i+1][j])
            {
                break;
            }
        }
        if(flag)
        {
            for(int j = 1; j <= m; j++)
            {
                lastmax[i][j] = maxn[i][j];
            }
        }
        else
        {
            for(int j = 1; j <= m; j++)
            {
                lastmax[i][j] = lastmax[i+1][j];
            }
        }
    }

    for(int i = 1; i <= n; i++) // minn[i] and lastmax[i+1] and premax[i-1]
    {
        bool flag = true;
        if(i > 1)
        {
            for(int j = 1; j <= m; j++)
            {
                if(minn[i][j] > premax[i-1][j])
                {
                    flag = false;
                    break;
                }
                if(minn[i][j] < premax[i-1][j])
                    break;
            }
        }
        if(i < n)
        {
            for(int j = 1; j <= m; j++)
            {
                if(minn[i][j] > lastmax[i+1][j])
                {
                    flag = false;
                    break;
                }
                if(minn[i][j] < lastmax[i+1][j])
                    break;
            }
        }
        if(flag) printf("1");
        else printf("0");
    }
    printf("\n");

    // cout <<"debug : \n";
    
    // for(int i = 1; i <= n; i++)
    // {
    //     cout<<"minn["<<i<<"] = ";
    //     for(int j = 1; j <= m; j++)
    //         cout<<char(minn[i][j]);
    //     cout<<endl;
    // }
    // for(int i = 1; i <= n; i++)
    // {
    //     cout<<"premax["<<i<<"] = ";
    //     for(int j = 1; j <= m; j++)
    //         cout<<char(premax[i][j]);
    //     cout<<endl;
    // }
    // for(int i = 1; i <= n; i++)
    // {
    //     cout<<"lastmax["<<i<<"] = ";
    //     for(int j = 1; j <= m; j++)
    //         cout<<char(lastmax[i][j]);
    //     cout<<endl;
    // }
    return 0;
}