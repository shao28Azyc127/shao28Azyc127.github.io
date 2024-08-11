#include <bits/stdc++.h>
using namespace std;

string s, mis[3005], mxs[3005];
int n, m;

string mx(string x)
{
    for(int i = 0; i < m/2; i++)
    {
        char a = x[i];
        x[i] = x[m-1];
        x[m-1] = a;
    }
    return x;
}

string mi(string x)
{
    int a[100005];
    string xx;
    for(int i = 0; i < x.size(); i++)
    {
        a[i+1] = int(x[i]);
    }
    sort(a + 1, a + x.size()+ 1);
    for(int i = 1; i <= x.size(); i++)
    {
        xx += char(a[i]);
    }
    return xx;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    if(n == 1 && m == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        mis[i] = mi(s);
    }
    for(int i = 1; i <= n; i++)
    {
        mxs[i] = mx(mis[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        bool vis = true;
        for(int j = 1; j <= n; j++)
        {
            if(mis[i] > mxs[j] && j != i)
            {
                vis = false;
                cout << 0;
                break;
            }
        }
        if(vis == true)
            cout << 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
