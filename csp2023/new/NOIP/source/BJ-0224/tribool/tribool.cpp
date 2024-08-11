#include <bits/stdc++.h> //rp++

using namespace std;
const int MAXN = 100002;

int cccccc,t;
int bb34[MAXN];

int n56,m56;
int v56[MAXN];
bool bb56[MAXN];
int pre56[MAXN];
int Find56(int x)
{
    if(pre56[x] == x)
        return x;
    return pre56[x] = Find56(pre56[x]);
}
inline void Join56(int x,int y)
{
    int fx = Find56(x);
    int fy = Find56(y);
    if(fx != fy)
    {
        pre56[fx] = min(fx,fy);
        pre56[fy] = min(fx,fy);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);

    cin >> cccccc >> t;
    if(cccccc == 3 || cccccc == 4)
    {
        while(t--)
        {
            int n,m;
            cin >> n >> m;
            for(register int i = 1;i <= m;++i)
            {
                int x;
                char v;
                cin >> v >> x;
                if(v == 'T')
                    bb34[x] = 1;
                else if(v == 'F')
                    bb34[x] = 2;
                else
                    bb34[x] = 3;
            }

            int cc34 = 0;
            for(register int i = 1;i <= n;++i)
                if(bb34[i] == 3)
                    cc34++;
            cout << cc34 << endl;
            memset(bb34,0,sizeof(bb34));
        }

        return 0;
    }

/*

*/
    if(cccccc == 5 || cccccc == 6)
    {
        while(t--)
        {
            cin >> n56 >> m56;
            for(register int i = 1;i <= n56;++i)
                pre56[i] = i;
            
            for(register int i = 1;i <= m56;++i)
            {
                char type;
                int u,v;
                cin >> type >> u;
                if(type == 'U')
                    v56[u] = 1;
                else
                {
                    cin >> v;
                    if(u != v)
                        Join56(u,v);
                }
            }

            for(register int i = 1;i <= n56;++i)
                pre56[i] = Find56(pre56[i]);
            /*
            cout << "pre: ";
            for(int i = 1;i <= n56;i++)
                cout << pre56[i] << " ";
            cout << endl;
            cout << "v: ";
            for(int i = 1;i <= n56;i++)
                cout << v56[i] << " ";
            cout << endl;
            */
            for(register int i = 1;i <= n56;++i)
                if(v56[i] == 1)
                    bb56[pre56[i]] = true;
            /*
            cout << "bb: ";
            for(int i = 1;i <= n56;i++)
                cout << bb56[i] << " ";
            cout << endl;
            */
            
            int cntans = 0;
            for(register int i = 1;i <= n56;++i)
                if(bb56[pre56[i]])
                    cntans++;//,cout << i << " ";
            //cout << endl;
            cout << cntans << endl;
            memset(v56,0,sizeof(v56));
            memset(bb56,false,sizeof(bb56));
            //cout << "-------------------------------------------------\n";
        }

        return 0;
    }

    if(cccccc == 7 || cccccc == 8)
    {
        while(t--)
        {
            
        }

        return 0;
    }

    return 0;
}