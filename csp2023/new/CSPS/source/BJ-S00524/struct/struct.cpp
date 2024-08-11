#include <map>
#include <string>
#include <iostream>
using namespace std;
string a[105];
map<string,int> b;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,now = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int k;
            cin >> k;
            string s;
            for (int i = 1;i <= k;i++) cin >> s >> s;
        }
        if (op == 2)
        {
            string s;
            cin >> s;
            cin >> s;
            a[now] = s;
            b[s] = now;
            cout << now * 8 << endl;
            now++;
        }
        if (op == 3)
        {
            string s;
            cin >> s;
            cout << b[s] << endl;
        }
        if (op == 4)
        {
            int addr;
            cin >> addr;
            if (addr >= now) cout << "ERR\n";
            else cout << a[addr / 8 * 8];
        }
    }
    return 0;
}
