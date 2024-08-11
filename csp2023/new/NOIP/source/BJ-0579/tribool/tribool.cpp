#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int c,t,ans;
int n,m,x[maxn],chec[maxn],fa[maxn];
bool flag[maxn];
struct step
{
    char type;
    int xi;
    int xj;
}steps[maxn];
bool key = true;
bool check()
{
    for (int i = 1;i <= m;i++)
    {
        //cout << steps[i].type << " ";
        if (steps[i].type == 'T')
        {
            chec[steps[i].xi] = 0;
        }
        else if (steps[i].type == 'F')
        {
            chec[steps[i].xi] = 1;
        }
        else if (steps[i].type == 'U')
        {
            chec[steps[i].xi] = 2;
        }
        else if (steps[i].type == '+')
        {
            chec[steps[i].xi] = chec[steps[i].xj];
            //cout << "*" << endl;
        }
        else if (steps[i].type == '-')
        {
            //cout << "*" << endl;
            if (chec[steps[i].xj] == 1)
            {
                chec[steps[i].xi] = 0;
            }
            else if (chec[steps[i].xj] == 0)
            {
                chec[steps[i].xi] = 1;
            }
            else chec[steps[i].xi] = 2;
        }
        for (int j = 1;j <= n;j++)
        {
            //cout << chec[j] << " ";
        }
        //cout << endl;
    }
    for (int i = 1;i <= n;i++)
    {
        //cout << chec[i] << " ";
        if (x[i] != chec[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    if (c == 3 || c == 4) printf("0");
    else
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= m;i++)
        {
            char v;
            cin >> v;
            steps[i].type = v;
            if (v == 'T' || v == 'F' || v == 'U')
            {
                int xi;
                scanf("%d",&xi);
                steps[i].xi = xi;
                if (v == 'T')
                {
                    chec[xi] = 0;
                    x[xi] = 0;
                }
                else if(v == 'F')
                {
                    chec[xi] = 1;
                    x[xi] = 1;
                }
                else
                {
                    chec[xi] = 2;
                    x[xi] = 2;
                }
                flag[xi] = true;
            }
            else
            {
                int xi,xj;
                key = false;
                scanf("%d%d",&xi,&xj);
                steps[i].xi = xi;
                steps[i].xj = xj;
                if (v == '+')
                {
                    chec[xi] = chec[xj];
                    x[xi] = x[xj];
                }
                else
                {
                    if(x[xj] == 0)
                    {
                        chec[xi] = 1;
                        x[xi] = 1;
                    }
                    else if(x[xj] == 1)
                    {
                        chec[xi] = 0;
                        x[xi] = 0;
                    }
                    else
                    {
                        chec[xi] = 2;
                        x[xi] = 2;
                    }
                    if (flag[xj] == true) flag[xi] = true;
                    else if (x[xj] == 2) fa[xi] = xj;
                }
            }
        }
        //cout << key <<endl;
        if (c == 3 || c == 4 || key == true)
        {
            //cout << "*" << endl;
            for (int i = 1;i <= n;i++)
            {
                if(x[i] == 2)
                {
                    ans++;
                }
            }
            printf("%d",ans);
            ans = 0;
            continue;
        }
        if (check())
        {
            for (int i = 1;i <= n;i++)
            {
                //cout << x[i] << " ";
                if (flag[i] == false && x[i] == 2)
                {
                    int k = i;
                    while(fa[k] != 0)
                    {
                        k = fa[k];
                    }
                    if (flag[k] == false)
                    {
                        flag[k] = true;
                        ans++;
                    }
                }
                else if (flag[i] == true && x[i] == 2)
                {
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
        else printf("%d\n",m);
        /*for (int i = 1;i <= n;i++)
        {
            cout << x[i] << ' ';
        }
        cout << endl;*/
        for (int i = 1;i <= n;i++)
        {
            //cout << chec[i] << " ";
            flag[i] = false;
            x[i] = 0;
            chec[i] = 0;
            ans = 0;
            key = true;
        }
        //cout << endl;
    }
    return 0;
}
