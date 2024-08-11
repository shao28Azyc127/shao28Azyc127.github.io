#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
const int NR = 2e6 + 5;
int n;
char s[NR];
bool check(string c)
{
    bool flag[NR] = {};
    while(true)
    {
        //int flag = false;
        int last_pos = -1;
        int cnt = 0;
        bool xiao = false;
        for(int i = 0; i < c.size(); i++)
        {
            if(flag[i]) continue;
            if(last_pos == -1){last_pos = i;continue;}

            if(c[i] == c[last_pos])
            {
                flag[i] = flag[last_pos] = true;
                last_pos = -1;
                xiao = true;
            }
            else last_pos = i;
            cnt += !flag[i];
        }
        if(!xiao) return cnt == 0;
    }
}
char st[NR];
char cfc[NR];
bool check2(int nn)
{
    int cnt = 0;
    for(int i = 0; i <= nn; i++)
    {
        st[++cnt] = cfc[i];
//cout << cnt << " " << cfc[i] <<endl;
        while(cnt >= 2)
        {
            char now = st[cnt--];
            char last = st[cnt--];
//cout << now << " " << last <<endl;
            if(now != last){st[++cnt] = last, st[++cnt] = now; break;}
//cout << "pop" << endl;
        }
    }
    return (cnt == 0);
}

void workO()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 1; i + j - 1 < n; j ++)
        {
            st[++cnt] = s[i+j-1];//cfc += s[i+j-1];
            while(cnt >= 2)
            {
                char now = st[cnt--];
                char last = st[cnt--];
                if(now != last)
                    {st[++cnt] = last, st[++cnt] = now; break;}
            }
            if(cnt == 0)ans++;
//cout << cnt << " ";for(int i = 1; i <= cnt; i++) cout << st[i]; cout <<endl;
        }
    }
    cout << ans << endl;
}
int main()
{
    //freopen("game2.in", "r", stdin);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    workO();
    return 0;
}
