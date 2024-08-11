#include<bits/stdc++.h>
using namespace std;
string f[10005];
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    long long las = 0;
    for(int i = 1;i <= n;i++)
    {
        int op;
        cin >> op;
        if(op == 2)
        {
            string s, t;
            cin >> s >> t;
            if(s == "short")
            {
                f[++las] = t;
                f[++las] = t;
            }
            if(s == "byte")
            {
                f[++las] = t;
            }
            if(s == "int")
            {
                f[++las] = t;
                f[++las] = t;
                f[++las] = t;
                f[++las] = t;
            }
            if(s == "long")
            {
                f[++las] = t;
                f[++las] = t;
                f[++las] = t;
                f[++las] = t;
                f[++las] = t;
                f[++las] = t;
                f[++las] = t;
                f[++las] = t;
            }
        }
        if(op == 4)
        {
            long long adds;
            cin >> adds;
            if(adds > las) cout << "ERR" << endl;
            else cout << f[adds] << endl;
        }
        if(op == 3)
        {
            string s;
            cin >> s;
            for(int i = 1;i <= 1000000;i++)
            {
                if(f[i] == s) cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
