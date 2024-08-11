#include<bits/stdc++.h>
using namespace std;
string neicun[100010];
void New(int x, int lst, string t)
{
    for(int i = 1; i <= x; i++) neicun[lst++] = t;
}
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    int lst = 0;
    while(n--)
    {
        int op;
        cin >> op;
        if(op == 2)
        {
            string s, t;
            cin >> s >> t;
            if(s == "byte")
            {
                cout << lst << '\n';
                New(1, lst, t);
            }
            else if(s == "short")
            {
                lst = (lst + 1) / 2 * 2;
                cout << lst << '\n';
                New(2, lst, t);
            }
            else if(s == "int")
            {
                lst = (lst + 3) / 4 * 4;
                cout << lst << '\n';
                New(4, lst, t);
            }
            else
            {
                lst = (lst + 7) / 8 * 8;
                cout << lst << '\n';
                New(8, lst, t);
            }
        }
        if(op == 3)
        {
            string s;
            cin >> s;
            for(int i = 1; i <= 100000; i++)
            {
                if(neicun[lst] == s)
                {
                    cout << i << '\n';
                    break;
                }
            }
        }
        if(op == 4)
        {
            long long x;
            cin >> x;
            if(x <= lst && neicun[x].size()) cout << neicun[x];
            else cout << -1;
        }
    }
    return 0;
}
