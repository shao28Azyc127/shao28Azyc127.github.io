#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define PII pair<int,int>
#define x first
#define y second

map <string, PII> mp1;
map <ll, string> mp2;
int n;
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    ll lst = 0;
    for(int r = 1; r <= n; ++ r)
    {
        int op; cin >> op;
        if(op == 2)
        {
            string s, t;
            cin >> s >> t;
            if(s == "byte")
            {
                cout << lst << endl;
                mp1[t] = make_pair(lst, lst);
                for(ll i = lst; i <= lst; ++ i) mp2[i] = t;
                ++ lst;
            }
            else if(s == "short")
            {
                if(!lst)
                {
                    cout << lst << endl;
                    mp1[t] = make_pair(lst, lst + 1);
                    for(ll i = lst; i <= lst + 1; ++ i) mp2[i] = t;
                    lst += 2;
                }
                else
                {
                    while(lst % 2 != 0) ++ lst;
                    cout << lst << endl;
                    mp1[t] = make_pair(lst, lst + 1);
                    for(ll i = lst; i <= lst + 1; ++ i) mp2[i] = t;
                    lst += 2;
                }
            }
            else if(s == "int")
            {
                if(lst) while(lst % 4 != 0) ++ lst;
                cout << lst << endl;
                mp1[t] = make_pair(lst, lst + 3);
                for(ll i = lst; i <= lst + 3; ++ i) mp2[i] = t;
                lst += 4;
            }
            else
            {
                if(lst) while(lst % 8 != 0) ++ lst;
                cout << lst << endl;
                mp1[t] = make_pair(lst, lst + 7);
                for(ll i = lst; i <= lst + 7; ++ i) mp2[i] = t;
                lst += 8;
            }
        }
        else if(op == 3)
        {
            string s;
            cin >> s;
            cout << mp1[s].x << endl;
        }
        else
        {
            ll k;
            cin >> k;
            if(mp2[k] == "") puts("ERR");
            else cout << mp2[k] << endl;
        }
    }
    return 0;
}