#include <bits/stdc++.h>
#define int long long
using namespace std;

int read()
{
    int x=0,f=1;
    char c=getchar();
    while (!isdigit(c))
    {
        if (c=='-')
        {
            f=-1;
        }
        c=getchar();
    }
    while (isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
const int maxn=105;
int place[maxn];
int length[maxn];
string type[maxn];
string name[maxn];
int n;
int cnt;
int max_len;
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    n=read();
    for (int i=1;i<=n;i++)
    {
        int op=read();
        if (op==1)
        {
            continue;
        }
        else if (op==2)
        {
            cnt++;
            cin >> type[cnt] >> name[cnt];
            if (type[cnt]=="byte")
            {
                length[cnt]=1;
            }
            else if (type[cnt]=="short")
            {
                length[cnt]=2;
            }
            else if (type[cnt]=="int")
            {
                length[cnt]=4;
            }
            else
            {
                length[cnt]=8;
            }
            max_len=max(max_len,length[cnt]);
        }
        else if (op==3)
        {
            string query;
            cin >> query;
            for (int i=1;i<=cnt;i++)
            {
                if (name[i]==query)
                {
                    cout << (i-1)*max_len << endl;
                    break;
                }
            }
        }
        else
        {
            int addr=read();
            int pla=addr/max_len+1;
            if ((pla-1)*max_len+length[pla]<addr||pla>cnt)
            {
                printf("ERR\n");
            }
            else
            {
                cout << name[pla] << endl;
            }
        }
    }
    return 0;
}
