#include <bits/stdc++.h>
#define N 120
#define STRUCT true
#define PUTONG false
using namespace std;
struct node
{
    string struct_name;
    int struct_size=0;
    vector < pair <string, int> > structt;
    int duiqi;
    vector <string> name;
} ;
map <string, node> a;
map <string, int> ma;
map <string, bool> types;
vector < pair <string, pair <int, int> > > memoriess;
map <string, string> bianliangs;
int finds(string s)
{
    bool flagg = 0;
    /*for (int i = 0; i < s.length(); i ++)
        if (s[i] == '.')
            flagg=1;
    if (flagg == 0)
    {
        for(int i=0;i<memoriess.size();i++)
        {
            if ()
        }
    }*/
    int ret = -1;
    string subs1 = "";
    queue <string> subss;
    int pre_poin = 0;
    for (int i = 0; i <= s.length(); i ++)
    {
        if (i == s.length() || s[i] == '.')
        {
            for (int j = pre_poin; j < i; j ++)
                subs1+=s[i];
            subss.push(subs1);
            subs1 = "";
            pre_poin = i + 1;
        }
    }
    int yy = 0;
    int zz;
    for (int i=0;i<memoriess.size();i++)
    {
        if (memoriess[i+1].first==subss.front())
        {
            cout << memoriess[i].second.first << ' ';
            zz = memoriess[i].second.first;
            yy = memoriess[i].second.first;
        }
        else if (memoriess[i].first== subss.front())
        {
            subss.pop();
            string nowleixing, nowname;
            nowname = memoriess[i].first;
            nowleixing = bianliangs[nowname];
            while (types[nowleixing] == STRUCT)
            {
                for (int j = 0; j < a[nowleixing].name.size(); j ++)
                {
                    if (nowname == a[nowleixing].structt[j].first)
                    {
                        nowleixing = a[nowleixing].name[j];
                        break;
                    }
                    else
                    {
                        yy += a[nowleixing].structt[j].second;
                    }
                }
                subss.pop();
            }
        }
    }
    cout << yy + zz << endl;
}
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ma["byte"]=1;
    types["byte"]=PUTONG;
    ma["short"]=2;
    types["short"]=PUTONG;
    ma["int"]=4;
    types["int"]=PUTONG;
    ma["long"]=8;
    types["long"]=PUTONG;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        short op;
        cin >> op;//yuanlai...!
        switch(op)
        {
        case 1:
            string s;
            int k;
            cin >> s >> k;
            node nn;
            nn.struct_name = s;
            for (int j = 1; j <= k; j ++)
            {
                string ti,ni;
                cin>>ti>>ni;
                nn.struct_size = max(nn.struct_size, ma[ti]);
                nn.struct_name.push_back(ti);
                nn.structt.push_back({ni, ma[ni]});
            }
            nn.duiqi = nn.struct_size;
            nn.struct_size *= k;
            ma[s] = nn.struct_size;
            types[s]=STRUCT;
            a[s] = nn;
            break;
        case 2:
            string t, nnn;
            cin >> t >> nnn;
            cout << memoriess[memoriess.size() - 1].second.first << ' ';
            memoriess.push_back({nnn, {memoriess[memoriess.size() - 1].second.first + t, t});
            break;
        case 3:
            string s;
            cin >> s;
            int sum = -1;
            finds(s);
            break;

        }
    }
    return 0;
}
