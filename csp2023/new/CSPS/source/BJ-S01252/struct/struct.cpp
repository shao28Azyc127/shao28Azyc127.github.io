#include <bits/stdc++.h>
#define int long long
using namespace std;

string types[101], names[101]; // For struct

map<string, int> mp; // Struct Name to id(all)
int previ; // Struct begin with

map<string, string> typeall; // All Type
map<string, int> idall; // All ID

int stsize;
string stname;

vector< pair<int, int> > inst; // In struct ID have
vector< pair<int, int> > inall; // In all ID have

string allforname[101];

int maxn;
int tuse(string t)
{
    if(t == "byte") return 1;
    if(t == "short") return 2;
    if(t == "int") return 4;
    if(t == "long") return 8;
    return maxn;
}

signed main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    int now = 0;
    int ucur = 0;
    while(n--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            string s;
            int k;
            cin >> s >> k;
            allforname[++ucur] = s;
            maxn = 0;
            for(int i=1; i<=k; i++)
            {
                cin >> types[i];
                cin >> names[i];
                maxn = max(maxn, tuse(types[i]));
            }
            if(now % maxn != 0) now += (maxn - (now % maxn));
            previ = now;
            int awhile = now;
            for(int i=1; i<=k; i++)
            {
                string typ = types[i];
                string nm = names[i];
                int us = tuse(typ);
                if(now % us != 0) now += (us - (now % us));
                mp[nm] = now;
                inst.push_back(make_pair(now, us));
                now += us;
                maxn = max(maxn, us);
            }
            cout << now - previ << " " << maxn << endl;
            stsize = now - previ;
            inall.push_back(make_pair(awhile, -stsize));
            stname = s;
            int y = inst.size();
            /*
            for(int i=0; i<y; i++)
            {
                cout << inst[i].first << " * " << inst[i].second << endl;
            }
            */
        }
        if(op == 2)
        {
            string typ, nm;
            cin >> typ >> nm;
            allforname[++ucur] = nm;
            int us = tuse(typ);
            if(now % us != 0) now += (us - (now % us));
            if(typ == stname)
            {
                inall.push_back(make_pair(now, -us));
            }
            else inall.push_back(make_pair(now, us));
            cout << now << endl;
            idall[nm] = now;
            typeall[nm] = typ;
            now += us;
        }
        if(op == 3)
        {
            string ask;
            cin >> ask;
            int y = ask.size();
            int flag = 0;
            for(int i=0; i<y; i++)
            {
                if(ask[i] == '.')
                {
                    string lastname = ask.substr(i + 1);
                    cout << mp[lastname] << endl;
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            cout << idall[ask] << endl;
        }
        if(op == 4)
        {
            int id;
            cin >> id;
            int g = inall.size();
            /*
            for(int i=0; i<g; i++)
            {
                cout << inall[i].first << " *** " << inall[i].second << endl;
            }
            */
            for(int i=0; i<g; i++)
            {
                if(id < inall[i].first)
                {
                    cout << "ERR" << endl;
                    break;
                }
                if(id >= inall[i].first && id < inall[i].first + abs(inall[i].second))
                {
                    if(inall[i].second < 0)
                    {
                        bool flag = 1;
                        // id -= inall[i].first;
                        int h = inst.size();
                        for(int j=0; j<h; j++)
                        {
                            if(id < inst[j].first)
                            {
                                cout << "ERR" << endl;
                                flag = 0;
                                break;
                            }
                            if(id >= inst[j].first && id < inst[j].first + inst[j].second)
                            {
                                cout << stname << "." << names[j + 1] << endl;
                                break;
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout << allforname[i + 1] << endl;
                    }
                    break;
                }
            }

        }
    }
}
