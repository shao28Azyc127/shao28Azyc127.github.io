#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    int op;
    for(int i = 1; i <= n; i++)
    {
        cin >> op;
        if(op == 1)
        {
            string s;
            int k;
            cin >> s >> k;
            string t, n;
            int ans = 0, maxx = 0;
            for(int i = 1; i <= k; i++)
            {
                cin >> t >> n;
                if(t == "byte")
                {
                    ans += 1;
                    maxx = max(1, maxx);
                }
                if(t == "short")
                {
                    ans += 2;
                    maxx = max(2, maxx);
                }
                if(t == "int")
                {
                    ans += 4;
                    maxx = max(4, maxx);
                }
                if(t == "long")
                {
                    ans += 8;
                    maxx = max(8, maxx);
                }
            }
            if(ans % maxx == 0)
            {
                cout << ans << " " << maxx << endl;
            }
            else
            {
                cout << (ans / maxx + 1) * maxx << " " << maxx << endl;
            }
        }
        else if(op == 2)
        {
            string t, n;
            cin >> t >> n;
            cout << 0 << endl;
        }
        else if(op == 3)
        {
            string s;
            cin >> s;
            cout << 0 << endl;
        }
        else if(op == 4)
        {
            int addr;
            cin >> addr;
            cout << "ERR" << endl;
        }
    }
    return 0;
}
