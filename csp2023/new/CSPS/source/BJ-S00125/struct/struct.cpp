#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 110, K = 8e4 + 10, M = 2e7 + 10;


struct type
{
    int id;
    string name;
    int tsize, allign;
}t[N];

struct var
{
    int type_id, loc;
    string name;
}v[N];

int a[M], idv, idx;

map<string, int> fv, ft;

void get_loc(int i)
{
    int tsize = t[v[i].type_id].tsize;
    while(idx % tsize != 0) ++ idx;
    v[i].loc = idx;
    for (int j = idx; j < idx + tsize; ++ j )
        a[j] = i;
    idx += tsize;
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    t[0].id = 0; t[0].name = "byte"; t[0].tsize = t[0].allign = 1; ft["byte"] = 0;
    t[1].id = 1; t[1].name = "short"; t[1].tsize = t[1].allign = 2; ft["short"] = 1;
    t[2].id = 2; t[2].name = "int"; t[2].tsize = t[2].allign = 4; ft["int"] = 2;
    t[3].id = 3; t[3].name = "long"; t[3].tsize = t[3].allign = 8; ft["long"] = 3;

    int T;
    cin >> T;
    memset(a, -1, sizeof a);
    while(T -- )
    {
        int op;
        cin >> op;
        if (op == 2)
        {
            string c, d;
            cin >> c >> d;
            v[idv].type_id = ft[c], v[idv].name = d;
            fv[d] = idv;
            get_loc(idv);
            printf("%d\n", v[idv].loc);
            ++ idv;
        }
        else if (op == 3)
        {
            string s;
            cin >> s;
            printf("%d\n", v[fv[s]].loc);
        }
        else if (op == 4)
        {
            long long add;
            cin >> add;
            if (add > 1e9 || a[add] == -1)
                puts("ERR");
            else
                cout<<v[a[add]].name<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
