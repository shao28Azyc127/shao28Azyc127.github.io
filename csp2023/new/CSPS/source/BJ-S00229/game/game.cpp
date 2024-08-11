#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

bool vis[100010];

bool check(string pre)
{
    string now;
    while(pre.size() != 0)
    {
        memset(vis,0,sizeof(vis));
        int cnt = 0;
        for(int i = 1; i < pre.size(); i++)
        {
            if(pre[i - 1] != pre[i])
            {
                now += pre[i - 1];
                now += pre[i];
            }
            else if(vis[i - 1] == 0 && vis[i] == 0)
            {
                vis[i - 1] = 1;
                vis[i] = 1;
                cnt++;
                i++;
            }
        }
        if(cnt == 0) return false;
        pre = now;
        now = "";
    }
    return true;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            string t = "";
            for(int k = i; k <= j; k++)
                t += s[k];
            if(check(t) && t.size() % 2 == 0)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
