#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool chk(string t)
{
    int n = t.size();
    char lst = t[0];
    int lsn = 0;
    int cnt = 0;
    int flag = 0;
    while(true)
    {
        for(int i=0; i<n; i++)
        {
            if(t[i] != '0')
            {
                lst = t[i];
                lsn = i;
                break;
            }
        }
        flag = 0;
        for(int i=lsn+1; i<n; i++)
        {
            if(t[i] == '0') continue;
            if(t[i] == lst)
            {
                t[i] = '0';
                t[lsn] = '0';
                lst = t[i + 1];
                lsn = i + 1;
                i ++;
                flag = 1;
                cnt += 2;
            }
            else
            {
                lst = t[i];
                lsn = i;
            }
        }
        if(!flag) break;
    }
    return cnt == n;
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    int total = 0;
    for(register int i=0; i<n-1; i++)
    {
        for(register int j=i+1; j<n; j++)
        {
            if((j - i + 1) & 1) continue;
            string t = s.substr(i, j - i + 1);
            // cout << i << " " << j << " " << chk(t) << endl;
            total += chk(t);
        }
    }
    cout << total << endl;
}
