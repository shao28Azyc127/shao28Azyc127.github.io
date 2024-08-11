#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
vector <string> v;
map <string,int> mp;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    cin >> s;
    s = " " + s;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i + 1;j <= n;j += 2)
        {
            string s1 = "";
            for(int k = i;k <= j;k++) s1 += s[k];
            v.push_back(s1);
        }
    }
    for(int i = 0;i < v.size();++i)
    {
        bool flag = false;
        string s = v[i];
        string pre = "";
        string raw = s;
        if(mp[s] == -1) continue;
        if(mp[s] == 1)
        {
            ans++;
            continue;
        }
        while(s != pre)
        {
            pre = s;
            string s1 = "";
            int len = s.length();
            for(int j = 0;j <= len - 1;++j)
            {
                if(j < len - 1 && s[j] == s[j + 1])
                {
                    j++;
                    continue;
                }
                s1 += s[j];
            }
            s = s1;
            if(s == "")
            {
                ans++;
                mp[raw] = 1;
                flag = true;
                break;
            }
        }
        if(!flag) mp[raw] = -1;
    }
    cout << ans;
    return 00;
}
