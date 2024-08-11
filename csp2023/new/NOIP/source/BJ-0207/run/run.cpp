#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define int long long
using namespace std;

int read()
{
    int ans = 0;
    char c = 'c';
    while(c > '9' || c < '0') c = getchar();
    while(c <= '9' && c >= '0')
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}

int f[1010]; //f[i]��ʾ����i����ս����ɵ�i����ս���ܹ��е�����ֵ 17~18
int dp[1010][1010]; //dp[i][j]��ʾ�����i������������j��,�ܹ���õ�����ܼ�ֵ 1~7
int sum[1010][1010]; //sum[i][j]��ʾ��������j��,�ڵ�i�������������ս���ܹ���õ�����ֵ 1~7
int cnt, pre[1010]; //����sum����

struct C
{
    int l, r, w, lst;
}ch[100010], calc[1010];

bool cmp(C x, C y)
{
    return x.lst < y.lst;
}

int n, m, k, d;

signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);

    int c = read(), t = read();
    for(int times = 1; times <= t; times++)
    {
        n = read();
        m = read();
        k = read();
        d = read();
        for(int i = 1; i <= m; i++)
        {
            ch[i].r = read();
            ch[i].lst = read();
            ch[i].w = read();
            ch[i].l = ch[i].r - ch[i].lst + 1;
        }
        if(c <= 7) // 28 pts
        {
            memset(calc, 0, sizeof(calc));
            memset(dp, 0, sizeof(dp));

            for(int i = 1; i <= n; i++)
            {
                cnt = 0;
                for(int j = 1; j <= m; j++)
                    if(ch[j].r == i) calc[++cnt] = ch[j];
                sort(calc+1, calc+cnt+1, cmp);
                for(int j = 1; j <= cnt; j++) pre[j] = pre[j-1] + calc[j].w;
                int cur = 1;
                for(int j = 1; j <= i; j++)
                {
                    while(calc[cur].lst <= j && cur <= cnt) cur++;
                    sum[i][j] = pre[cur-1];
                }
                
            }
            int maxdp = 0;
            for(int i = 1; i <= n; i++)
            {
                for(int j = 0; j <= i && j <= k; j++)
                {
                    if(j == 0) //���ܲ�
                    {
                        dp[i][j] = maxdp;
                    }
                    else //�ܲ�
                    {
                        dp[i][j] = dp[i-1][j-1] - d + sum[i][j];
                    }

                }
                maxdp = 0;
                for(int j = 0; j <= i && j <= k; j++)
                {
                    maxdp = max(maxdp, dp[i][j]);
                }

            }

            int ans = 0;
            for(int i = 0; i <= n; i++)
                ans = max(ans, dp[n][i]);
            printf("%lld\n",ans);
        }
        else if(c == 17 || c == 18) // 8 pts
        {
            int ans = 0;
            for(int i = 1; i <= m; i++)
            {
                if(ch[i].lst <= k && ch[i].w > ch[i].lst * d)
                {
                    ans += ch[i].w - ch[i].lst * d;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}