#include<bits/stdc++.h>
#define long long
using namespace std;
map<string, long long> mp;
map<long long, string> mp2;
struct Node
{
    int z;
    string c[10010], d[10010];
};
map<string, Node> mp3;
map<string, long long> mp4;
string a[10010], b[10010];
signed main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    mp["byte"] = 1;
    mp["short"] = 2;
    mp["int"] = 4;
    mp["long"] = 8;
    long long ans = 0;
    while(n--)
    {
        int l;
        cin >> l;
        if(l == 1)
        {
            string s;
            long long t, mx = 0;
            cin >> s >> t;
            mp3[s].z = t;
            for(int i = 1; i <= t; i++)
            {
                cin >> a[i] >> b[i];
                mp3[s].c[i] = a[i];
                mp3[s].d[i] = b[i];
                mx = max(mx, mp[a[i]]);
            }
            cout << mx * t << ' ' << mx << endl;
        }
        else if(l == 2)
        {
            string x, y;
            cin >> x >> y;
            cout << ans << endl;
            if(x == "byte" || x == "short" || x == "int" || x == "long")
            {
                mp4[y] = ans;
                for(int i = 1; i <= mp[x]; i++)
                {
                    mp2[ans] = y;
                    ans++;
                }
            }
            else
            {
                string g = y;
                g += ".";
                for(int i = 1; i <= mp3[x].z; i++)
                {
                    mp4[g + mp3[x].d[i]] = ans;
                    for(int j = 1; j <= mp[x] / mp3[x].z; j++)
                    {
                        if(j < mp[mp3[x].c[i]]) mp2[ans++] = g + mp3[x].d[i];
                        else break;
                    }
                }
            }
        }
        else if(l == 4)
        {
            long long x;
            cin >> x;
            if(mp2[x] == "")
            {
                cout << "ERR" << endl;
            }
            cout << mp2[x] << endl;
        }
        else
        {
            string x;
            cin >> x;
            cout << mp4[x] << endl;
        }
    }
    return 0;
}

