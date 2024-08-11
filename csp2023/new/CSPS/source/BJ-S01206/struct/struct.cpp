#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n, op, k, t, n2, addr, len;
    string s, s1, ti, ni;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> s >> k;
            for(int i = 0; i < k; i++)
            {
                cin >> ti >> ni;
                len = k;
                if(ti[0] == 's')
                {
                    cout << 2 * 2 * len << " " << 2 * 2 << endl;
                }
                if(ti[0] == 'i')
                {
                    cout << len * 4 * 2 << " " << 2 * 4 << endl;
                }
            }
        }
        else if(op == 2)
        {
            cin >> t >> n2;
            cout << "0";
        }
        if(op == 3)
        {
            cin >> s1;
            cout << 2 * len;
        }
        if(op == 4)
        {
            cin >> addr;
            cout << "ERR";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
