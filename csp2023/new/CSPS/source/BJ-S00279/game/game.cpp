#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

const int N = 2e6 + 10;

int n,ans;
char s[N];

bool check(char ss[],int x)
{
    bool flag = true,f[x + 1];
    int cnt = 0;
    memset(f,0,sizeof(f));
    while(1)
    {
        if(!flag)
            break;
        flag = false;
        for(int i = 1;i <= x;i++)
        {
            while(f[i] && i <= x - 1)i++;
            int j = i + 1;
            while(f[j] && j <= x)j++;
            if(ss[i] == ss[j])
            {
                // cout << '*' << i << ' ' << ss[i] << ' ' << j << ' ' << ss[j] << endl;
                cnt += 2;
                flag = true;
                f[i] = f[j] = true;
            }
        }
    }
    if(cnt == x)
        return true;
    return false;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s + 1;
    for(int i = 2;i <= n;i++)
    {
        for(int j = 0;i + j <= n;j++)
        {
            char ss[i + 1];
            // cout << "#";
            for(int k = 1;k <= i;k++)
            {
                ss[k] = s[j + k];
                // cout << ss[k];
            }
            // cout << endl;
            if(check(ss,i))
            {
                // cout << "++++++\n"; 
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
