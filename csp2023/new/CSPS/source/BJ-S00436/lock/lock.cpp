#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("lock.in", ios::in);
    ofstream fout("lock.out", ios::out);
    int n;
    fin >> n;
    int f[n][5];
    int ans = 0;
    for(int i = 0;i < n;i++) fin >> f[i][0] >> f[i][1] >> f[i][2] >> f[i][3] >> f[i][4];
    for(int i = 0;i <= 9;i++)
    {
        for(int j = 0;j <= 9;j++)
        {
            for(int k = 0;k <= 9;k++)
            {
                for(int l = 0;l <= 9;l++)
                {
                    for(int m = 0;m <= 9;m++)
                    {
                        int c = 0, d = -100;
                        int manzu = 0;
                        for(int s = 0;s < n;s++)
                        {
                            /**
                            9 1
                            2 -8
                            12 2
                            2 2
                            7 9
                            **/
                            int cnt = 0;
                            int a = f[s][0], b = f[s][1], c = f[s][2], d = f[s][3], e = f[s][4];
                            int ca = (a - i + 10) % 10;
                            int cb = (b - j + 10) % 10;
                            int cc = (c - k + 10) % 10;
                            int cd = (d - l + 10) % 10;
                            int ce = (e - m + 10) % 10;
                            if((!ca && !cb && !cc && !cd && ce)
                               || (!ca && !cb && !cc && cd && !ce)
                               || (!ca && !cb && cc && !cd && !ce)
                               || (!ca && cb && !cc && !cd && !ce)
                               || (ca && !cb && !cc && !cd && !ce)) manzu++;
                            else
                            {
                                if((ca && cb && !cc && !cd && !ce && ca == cb)
                                   || (!ca && cb && cc && !cd && !ce && cb == cc)
                                   || (!ca && !cb && cc && cd && !ce && cc == cd)
                                   || (!ca && !cb && !cc && cd && ce && cd == ce))
                                {
                                    manzu++;
                                }
                            }
                        }
                        if(manzu == n) ans++;
                    }
                }
            }
        }
    }
    fout << ans << endl;
    return 0;
}
