#include <bits/stdc++.h>
using namespace std;

int c, t;

int x[100005]; // 1 : t ;;; 2 : f ;;; 3 : u ;;;

int bian(int p)
{
    if(p == 1)
        return 2;
    if(p == 2)
        return 1;
    return 3;
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out ", "w", stdout);
    cin >> c >> t;
    if(c == 3 || c == 4)
    {
        while(t--)
        {
            int n, m, ans = 0;
            cin >> n >> m;
            for(int i = 1 ; i <= n; i++)
            {
                string s;
                int a;
                cin >> s >> a;
                if(s == "U")
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    if( c == 5 || c == 6)
    {
        while(t--)
        {
            int n, m, ans = 0;
            cin >> n >> m;
            int a[100005], b[100005], cnt = 1;
            for(int i = 1 ; i <= n; i++)
            {
                string s;
                cin >> s;
                int temp;
                if(s == "U")
                {
                    cin >> temp;
                    x[temp] = 3;
                }
                if(s == "+")
                {
                    cin >> a[cnt] >> b[cnt];
                    ++cnt;
                }
            }
            while(1)
            {
                for(int i = 1 ; i <= cnt - 1; i++)
                {
                    if(x[b[i]] == 3)
                        x[a[i]] = 3;
                }
                bool vis = false;
                for(int i = 1; i <= cnt - 1; i++)
                {
                    if(x[a[i]] == 3)
                        continue;
                    if(x[b[i]] == 3)
                    {
                        break;
                    }
                    if(i == cnt - 1)
                    {
                        vis = true;
                        break;
                    }
                }
                if(vis == true)
                    break;
            }
            for(int i = 1; i <= n; i++)
            {
                if(x[i] == 3)
                    ans++;
            }
            cout << ans << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
