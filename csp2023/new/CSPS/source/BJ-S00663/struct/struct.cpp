#include <bits/stdc++.h>

using namespace std;

struct yuan_su
{
    string ming;
    long long int dz;
};

/*
string t[105], na[105];

map <string, vector<string> > jgt;
*/



map <string, int> mp;
vector <yuan_su> v;


map <string, long long int> bu_fen;
map <string, string> bufen;

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int i, j;
    int n, op;
    cin >> n;
    long long int di_zhi = 0;
    mp.clear();

    mp["byte"] = 1;
    mp["short"] = 2;
    mp["int"] = 4;
    mp["long"] = 8;

    for(i=1; i<=n; i++)
    {
        cin >> op;
        if(op == 1)
        {
            /*
            string s;
            int k;
            cin >> s;
            cin >> k;
            int ans = 0;
            for(j=1; j<=k; j++)
            {
                cin >> t[j] >> na[j];
                jgt[s].push_back(t[j]);
                ans = max(ans, mp[t[j]]);
            }
            mp[s] = k * ans;
            cout << k * ans << " " << ans << endl;

            for(j=1; j<=k; j++)
            {
                string x = s + "_" + na[j];
                mp[x] = ans * (j - 1);
            }
            */

        }
        else if(op == 2)
        {
            string tt, nn;
            cin >> tt >> nn;
            yuan_su d;
            d.ming = nn;
            d.dz = di_zhi;
            v.push_back(d);
            bu_fen[nn] = di_zhi;
            bufen[nn] = tt;
            cout << di_zhi << endl;
            di_zhi += mp[tt];
        }
        else if(op == 3)
        {
            string s;
            cin >> s;

            cout << bu_fen[s] << endl;
            /*
            int x, y;
            string z = "", cun = "";
            y = 0;
            int cs = 0;
            for(j=0; j<s.size(); j++)
            {
                if(s[j] == '.')
                {
                    if(cs == 0)
                    {
                        cs++;
                        for(int k=0; k<v.size(); k++)
                        {
                            if(v[k].ming == z)
                            {
                                x = v[k].dz;
                                break;
                            }
                        }
                        // x wei qi shi di zhi

                        y = x;
                        cun = z;
                    }
                    else
                    {
                        string xx = cun + "_" + z;
                        y += mp[xx];
                        cun = z;
                    }
                    z = "";
                }
                else
                {
                    z += s[j];
                }
            }
            cout << y << endl;


            */
        }
        else if(op == 4)
        {
            long long addr;
            long long diz;
            cin >> addr;

            bool flag = 0;
            for(j=0; j<v.size(); j++)
            {
                if(v[j].dz <= addr && v[j].dz + mp[bufen[v[j].ming]] >= addr)
                {
                    flag = 1;
                    cout << v[j].ming << endl;
                }

            }
            if(flag == 0) cout << "ERR\n";



            /*
            for(j=0; j<v.size(); j++)
            {
                if(v[j].dz == addr || (v[j].dz < addr && v[j+1].dz > addr))
                {
                    diz = v[j].dz;
                    break;
                }
            }
            string s = v[j].ming;

            if(s != "byte" && s != "short" && s != "int" && s != "long")
            {
                string ans = "";
                ans += s + ".";
                bool flag = 0;
                if(s != "byte" && s != "short" && s != "int" && s != "long")
                {
                    for(j=0; j<jgt[s].size(); j++)
                    {
                        string x = s + "_" + jgt[s][j];
                        if(diz + mp[x] > addr)
                        {
                            flag = 1;
                            ans += jgt[s][j];
                        }

                    }
                }
                if(flag)
                {
                    cout << ans << endl;
                }
                else
                {
                    cout << "ERR" << endl;
                }
            }
            else
            {
                if(diz + mp[s] < addr)
                {
                    cout << "ERR" << endl;
                }
                else
                {
                    cout << s << endl;
                }
            }
            */

        }
    }
    return 0;
}
