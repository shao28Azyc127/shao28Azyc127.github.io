#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXT = 105;

int q1;

int T;
string typ[MAXT], nme[MAXT];
int sz[MAXT];
LL st;
LL add[MAXT];

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("strcut.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    st = 0;
    int cnt = 0;
    while (T--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            break;
        }
        else if (op == 2)
        {
            cnt++;
            cin >> typ[cnt] >> nme[cnt];

            if (typ[cnt] == "byte")
            {
                sz[cnt] = 1;
            }
            if (typ[cnt] == "short")
            {
                sz[cnt] = 2;
            }
            if (typ[cnt] == "int")
            {
                sz[cnt] = 4;
            }
            if (typ[cnt] == "long")
            {
                sz[cnt] = 8;
            }

            while (st % sz[cnt] != 0)
            {
                st++;
            }

            add[cnt] = st;
            st += sz[cnt];
        }
        else if (op == 3)
        {
            string name;
            cin >> name;

            for (int i = 1; i <= cnt; i++)
            {
                if (nme[i] == name)
                {
                    cout << add[i] << "\n";
                    break;
                }
            }
        }
        else
        {
            LL addr;
            cin >> addr;

            if (addr >= st)
            {
                cout << "ERR\n";
                continue;
            }

            int pos = upper_bound(add+1, add+1+cnt, addr) - add;
            pos--;

            if (add[pos] + sz[pos] - 1 < addr)
            {
                cout << "ERR\n";
                continue;
            }

            cout << nme[pos] << "\n";
        }
    }
    return 0;
}