#include <bits/stdc++.h>
using namespace std;

string mem[10000];
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    int head = 0;
    for (int i = 0; i < 10000; i++)
    {
        mem[i] = "";
    }
    for (int i = 1; i <= n; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string s;
            cin >> s;
            int k;
            cin >> k;
            for (int i = 1; i <= k; i++)
            {
                string zwh, sxq;
                cin >> zwh >> sxq;
            }
        }
        else if (op == 2)
        {
            string csr, lxy;
            cin >> csr >> lxy;
            cout << head << endl;
            if (csr == "byte")
            {
                mem[head++] = lxy;
            }
            else if (csr == "short")
            {
                for (int j = 0; j < 2; i++)
                {
                    mem[head++] = lxy;
                }
            }
            else if (csr == "int")
            {
                for (int j = 0; j < 4; j++)
                {
                    mem[head++] = lxy;
                }
            }
            else if (csr == "long")
            {
                for (int j = 0; j < 8; j++)
                {
                    mem[head++] = lxy;
                }
            }
        }
        else if (op == 3)
        {
            string mkc;
            cin >> mkc;
            for (int j = 0; j < 10000; j++)
            {
                if (mem[j] == mkc)
                {
                    cout << j << endl;
                    break;
                }
            }
        }
        else if (op == 4)
        {
            int addr;
            cin >> addr;
            if (mem[addr] == "")
            {
                cout << "ERR" << endl;
            }
            else
            {
                cout << mem[addr] << endl;
            }
        }
    }
    return 0;
}