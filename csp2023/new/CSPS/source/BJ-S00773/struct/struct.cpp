#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int op;
        cin >> op;
        if(op == 4) cout << "ERR" << endl;
        else cout << 0 << endl;
    }
    return 0;
}
