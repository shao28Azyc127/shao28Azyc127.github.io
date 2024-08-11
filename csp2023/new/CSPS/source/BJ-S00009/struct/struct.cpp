#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;

struct st{
    string id;
    int k;
    int a[101]; // type
    string nm[101]; // name
    int o[101], maxa, oo; // pian
}s[110];
struct ele{
    string id;
    st structure;
}e[110];
int cnte = 0;
int cnt = 5;
map<long long, string> mp1;
map<string, int> mp2;
map<string, long long> mp3;

int addr;

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {

            //init
            string strname;int k;
            cin >> strname >> k;
            s[++cnt].id = strname;
            s[cnt].k = k;
            mp2[strname] = cnt;
            int maxa = 0;
            int o = 0;
            for(int i = 1;i <= k;i++)
            {
                string type;
                cin >> type >> s[cnt].nm[i];
                if(type == "byte")
                    s[cnt].a[i] = 1;
                else if(type == "short")
                    s[cnt].a[i] = 2;
                else if(type == "int")
                    s[cnt].a[i] = 4;
                else
                    s[cnt].a[i] = 8;
                int memo = s[cnt].a[i];
                maxa = max(maxa, memo);
                o = ((o+memo-1)/memo) * memo;
                s[cnt].o[i] = o;
                o += memo;
                //cout << memo << "\n";
            }
            // output
            cout << o << " " << maxa << "\n";
            s[cnt].oo = o;s[cnt].maxa = maxa;

        }
        else if(op == 2)
        {
            string type, nm;
            cin >> type >> nm;
            e[++cnte].id = nm;
            int maxa;
            if(type == "byte")
            {
                maxa = 1;addr = ((addr + maxa-1)/maxa) * maxa;cout << addr << "\n";
            }
            else if(type == "short")
            {
                maxa = 2;addr = ((addr + maxa-1)/maxa) * maxa;cout << addr << "\n";
            }
            else if(type == "int")
            {
                maxa = 4;addr = ((addr + maxa-1)/maxa) * maxa;cout << addr << "\n";
            }
            else if(type == "long")
            {
                maxa = 8;addr = ((addr + maxa-1)/maxa) * maxa;cout << addr << "\n";
            }
            else{
                e[cnte].structure = s[mp2[type]];
                maxa = e[cnte].structure.maxa;
                if(maxa == 0) {cout << e[cnte].structure.id << "\n";continue;}
                addr = ((addr + maxa-1)/maxa) * maxa;
                // output
                cout << addr << "\n";
                for(int i = 1;i <= e[cnte].structure.k;i++)
                {
                    int memo = e[cnte].structure.a[i];
                    if(memo == 0) continue;
                    addr = ((addr+memo-1)/memo) * memo;
                    string dizhi = nm + "." + e[cnte].structure.nm[i];
                    mp1[addr] = dizhi;
                    mp3[dizhi] = addr;
                    for(int i = 1;i <= memo;i++)
                    {
                        addr++;
                        mp1[addr] = dizhi;
                    }
                }
            }

        }
        else if(op == 3)
        {
            string finding;
            cin >> finding;
            cout << mp3[finding] << "\n";
        }
        else{
            int finding;
            cin >> finding;
            if(mp1.count(finding)) cout << mp1[finding] << "\n";
            else cout << "ERR" << "\n";
        }
    }
    return 0;
}
