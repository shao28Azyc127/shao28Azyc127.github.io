//#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("run.in");
ofstream cout("run.out");

struct seg {
    int left, right, val;
    bool operator<(const seg& rhs) const {
        if(right != rhs.right) return right < rhs.right;
        return left < rhs.left;
    }
} segs[100005];
int pos[200005];

long long dp[2003][2003];
long long dp2[200005][102];

int main()
{
    int C, T;
    cin >> C >> T;
    while(T--)
    {
        int n, m, k;
        long long d;
        cin >> n >> m >> k >> d;
        for(int i = 1; i <= m; i++)
        {
            cin >> segs[i].right >> segs[i].left >> segs[i].val;
            segs[i].left = segs[i].right - segs[i].left + 1;
            pos[2 * i - 1] = segs[i].left;
            pos[2 * i] = segs[i].right;
        }
        sort(segs + 1, segs + m + 1);
        int segptr = 1;
        sort(pos + 1, pos + 2 * m + 1);
        int poscnt = unique(pos + 1, pos + 2 * m + 1) - pos - 1;
        if(C == 17 || C == 18)
        {
            long long ans = 0;
            for(int i = 1; i <= m; i++)
            {
                if(segs[i].right - segs[i].left + 1 <= k && (segs[i].right - segs[i].left + 1) * d <= segs[i].val)
                {
                    ans += segs[i].val - (segs[i].right - segs[i].left + 1) * d;
                }
            }
            cout << ans << endl;
            continue;
        }
        if(C == 15 || C == 16)
        {
            for(int i = 1; i <= poscnt; i++)
            {
                for(int j = 0; j <= k + 1; j++)
                {
                    dp2[i][j] = 0;
                }
            }
            for(int i = 1; i <= poscnt; i++)
            {
                dp2[i][k + 1] = dp2[i - 1][k + 1];
                dp2[i][0] = -d;
                if(pos[i] - pos[i - 1] > 1) dp2[i][0] += dp2[i - 1][k + 1];
                else dp2[i][0] += dp2[i - 2][k + 1];
                for(int j = i - 1; j >= 1 && pos[i] - pos[j] < k; j--)
                {
                    dp2[i][i - j] = dp2[i - 1][i - j - 1] - (pos[i] - pos[i - 1]) * d;
                }
                while(segs[segptr].right == pos[i])
                {
                    for(int j = i; j >= 1 && pos[i] - pos[j] < k; j--)
                    {
                        if(pos[j] <= segs[segptr].left) dp2[i][i - j] += segs[segptr].val;
                    }
                    ++segptr;
                }
                for(int j = i; j >= 1 && pos[i] - pos[j] < k; j--)
                {
                    if(dp2[i][k + 1] < dp2[i][i - j]) dp2[i][k + 1] = dp2[i][i - j];
                }
            }
            /*for(int i = 1; i <= poscnt; i++)
            {
                for(int j = 0; j <= k + 1; j++)
                {
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }*/
            cout << dp2[poscnt][k + 1] << endl;
            continue;
        }
/*
        for(int i = 1; i <= m; i++)
        {
            cout << segs[i].left << " " << segs[i].right << " " << segs[i].val << endl;
        }
        cout << poscnt << endl;
        for(int i = 1; i <= poscnt; i++)
        {
            cout << pos[i] << " ";
        }
        cout << endl;
*/
        for(int i = 1; i <= poscnt; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= poscnt; i++)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][i] = -d;
            if(pos[i] - pos[i - 1] > 1) dp[i][i] += dp[i - 1][0];
            else dp[i][i] += dp[i - 2][0];
            for(int j = i - 1; j >= 1 && pos[i] - pos[j] < k; j--)
            {
                dp[i][j] = dp[i - 1][j] - (pos[i] - pos[i - 1]) * d;
                //cout << "dp[" << i << "][" << j << "]=" << dp[i][j] << endl;
            }
            while(segs[segptr].right == pos[i])
            {
                for(int j = i; j >= 1 && pos[i] - pos[j] < k; j--)
                {
                    if(pos[j] <= segs[segptr].left) dp[i][j] += segs[segptr].val;// cout << "seg " << segptr << ": dp[" << i << "][" << j << "]+=" << segs[segptr].val << endl;
                }
                ++segptr;
            }
            for(int j = i; j >= 1 && pos[i] - pos[j] < k; j--)
            {
                if(dp[i][0] < dp[i][j]) dp[i][0] = dp[i][j];
            }
        }
        /*for(int i = 1; i <= poscnt; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        cout << dp[poscnt][0] << endl;
    }
}
