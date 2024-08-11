#include<bits/stdc++.h>
using namespace std;
int n, m;
char op;
int f, s, c, t;
struct oper{
    char type;
    int first, second;
}opers[100005];
bool vis[100005];
short val[100005], val2[100005];


int main()
{
    ios::sync_with_stdio(false);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        bool flagtf = false, flagu = false;
        bool jia = false, jian = false;
        cin >> n >> m;
        for (int i = 0;i<m;i++)
        {
            cin >> op;
            if (op == '+' || op == '-')
            {
                if (op == '+') jia = true;
                if (op == '-') jian = true;
                cin >> f >> s;
                opers[i].type = op;
                opers[i].first = f;
                opers[i].second = s;
            }
            else
            {
                if (op == 'U') flagu =true;
                else flagtf = true;
                cin >> f;
                opers[i].type = op;
                opers[i].first = f;
            }
        }
        if (!jia&&!jian)
        {
            memset(vis, 0, sizeof(vis));
            for (int i = 0;i<m;i++)
            {
                if (opers[i].type == 'U')
                {
                    vis[opers[i].first] = (opers[i].type == 'U');
                }
            }
            int cnt = n;
            for (int i = 1;i<=n;i++)
            {
                if (vis[i]) cnt--;
            }
            cout << cnt << endl;
        }
        //else if (flagu && jia)
        //{
            //memset(vis, 0, sizeof(vis));
            //for (int i = 0;i<m;i++)
            //{
            //    if (opers[i].type == 'U')
            //    {
            //        vis[opers[i].first] = (opers[i].type == 'U');
            //    }
            //    if (opers[i].type == '+')
            //    {
            //        if (vis[opers[i].first] == true)
            //        {
            //            vis[opers[i].second] = true;
            //        }
            //        else
            //        {
            //            vis[opers[i].second] = false;
            //        }
            //    }
            //}
            //int cnt = n;
            //for (int i = 1;i<=n;i++)
            //{
            //    if (vis[i]) cnt--;
            //}
            //cout << cnt << endl;
        //}
        else
        {
            srand(time(0));
            int res = n;
            for (int tt = 0; n != 0 && tt < 100000;tt++)
            {
                int ucnt = 0;
                for (int i = 1;i<=n;i++)
                {
                    val[i] = int(abs(rand())) % 3; // 0: Unknown, 1:T, 2:F
                    val2[i] = val[i];
                    if (val[i] == 0)  ucnt++;
                    if (ucnt >= res)
                    {
                        continue;
                    }
                }
                //cout << "ucnt" << ucnt << endl;
                for (int i = 0;i<m;i++)
                {
                    oper o = opers[i];
                    if (o.type == 'U')
                    {
                        val[o.first] = 0;
                    }
                    if (o.type == 'T')
                    {
                        val[o.first] = 1;
                    }
                    if (o.type == 'F')
                    {
                        val[o.first] = 2;
                    }
                    if (o.type == '-')
                    {
                        if (val[o.second] == 0)
                        {
                            val[o.first] = 0;
                        }
                        //else val[o.first] = (val[o.second] == 1?2:1);
                        else if (val[o.second] == 1)
                        {
                            val[o.first] = 2;
                        }
                        else if (val[o.second] == 2)
                         {
                                val[o.first] = 1;
                         }
                    }
                    else
                    {
                        val[o.first] = val[o.second];
                    }
                }
                bool flag = true;
                for (int i = 1;i<=n;i++)
                {
                    if (val[i] != val2[i])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    //if (ucnt == res)
                    //{
                    //    best_in_row++;
                    //}
                    //else
                    //{
                    //    best_in_row = 0;
                    //}
                    if (res != ucnt)
                    {
                        tt -= n*5;
                    }
                    res = min(res, ucnt);

                    //if(res == ucnt)
                    //{

                    //for (int i = 1;i<=n;i++)
                    //{
//
                    //    cout << val[i] << val2[i] << " ";
                    //}
                    //cout << endl << endl;
                    //}
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
//1? 2? 3 4 5? 6?     /10
