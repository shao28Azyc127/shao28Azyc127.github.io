#include<bits/stdc++.h>
using namespace std;

long long n, cnt;

map<string, int> m;
string a[10005];

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    while(n > 0)
    {
        n--;
        int op;
        cin >> op;
        if(op == 2)
        {
            string t, k;
            cin >> t >> k;
            if(t == "long")
            {
                if(cnt % 8 != 0) cnt = cnt + 8 - cnt % 8;
                m[k] = cnt;
                for(int i = 1; i <= 8; i++)
                {
                    a[cnt] = k;
                    cnt++;
                }
            }
            if(t == "byte")
            {
                m[k] = cnt;
                for(int i = 1; i <= 1; i++)
                {
                    a[cnt] = k;
                    cnt++;
                }
            }
            if(t == "short")
            {
                if(cnt % 2 != 0) cnt = cnt + 2 - cnt % 2;
                m[k] = cnt;
                for(int i = 1; i <= 2; i++)
                {
                    a[cnt] = k;
                    cnt++;
                }
            }
            if(t == "int")
            {
                if(cnt % 4 != 0) cnt = cnt + 4 - cnt % 4;
                m[k] = cnt;
                for(int i = 1; i <= 4; i++)
                {
                    a[cnt] = k;
                    cnt++;
                }
            }
        }
        if(op == 3)
        {
            string s;
            cin >> s;
            cout << m[s] << endl;
        }
        if(op == 4)
        {
            long long addr;
            cin >> addr;
            if(a[addr].size() > 0) cout << a[addr] << endl;
            else cout << "ERR" << endl;
        }
    }
    return 0;
}
