#include<iostream>
#include<limits.h>
#include<cstring>
#include<vector>
#include<unordered_map>
typedef unsigned long long ull;
using namespace std;
const int maxn = 200000;
int n, op;
struct stru
{
    int num;
    vector<string> type;
    vector<string> names;
    int length;
};
unordered_map<string, stru> strus; //struct name, content
unordered_map<string, int> types; // typename, length
unordered_map<string, bool> basic; // true: stop false: continue
unordered_map<string, string> global; // name, type
unordered_map<string, unsigned long long> globalm; // name, place


int main()
{
    types["byte"] = 1;
    types["short"] = 2;
    types["int"] = 4;
    types["long"] = 8;
    basic["byte"] = basic["short"] = basic["int"] = basic["long"] = true;
    ios::sync_with_stdio(false);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    unsigned long long memory = 0;
    unsigned long long vis = 0;
    cin >> n;
    cin.get();
    for (unsigned i = 0;i<n;++i)
    {
        cin >> op;
        if (op == 1)
        {
            stru s;
            string na;
            cin >> na >> s.num;
            int ans2 = 0;
            for (int j = 0;j<s.num;j++)
            {
                string t, q;
                cin >> t >> q;
                s.type.push_back(t);
                s.names.push_back(q);
                ans2 = max(ans2, types[t]);
            }
            strus[na] = s;
            types[na] = ans2 * s.num;
            cout << ans2 * s.num << " " << ans2 << endl;
        }
        else if (op == 2)
        {
            string t, n;
            cin >> t >> n;
            cout << vis << endl;
            global[n] = t;
            globalm[n] = vis;
            vis += types[t];
        }
        else if (op == 3)
        {
            string s = "";
            ull ans = 0;
            char l;
            cin.get();
            l = cin.get();
            string input[200];
            unsigned count = 0;
            while(l != '\n')
            {
                while(l != '.' && l != '\n')
                {
                    s += l;
                    l = cin.get();
                }
                input[count] = s;
                count++;
            }
            if (count == 1) ans = globalm[input[0]];


            cout << ans << endl;
        }
        else // op == 4
        {
            ull addr;
            cin >> addr;

        }
    }
    return 0;
}
// short类型的成员aa占据第0 ? 1字节地址,int类型的成员ab占据第4 ? 7字节地址。
