#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int n,m = 4,ct = 0,cv = 0,cs = 0,tk[105],tson[105][105],vtyp[105];
long long mx[109],siz[10005],ts[105][105],vpos[105];
char nme[105][15],vnme[105][15],snme[105][105][15],st[1105];
map <string,int> stt,stv,sts;
string s,s1 = "byte",s2 = "short",s3 = "int",s4 = "long";
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
inline long long readll()
{
    long long x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
inline void write(long long x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    stt[s1] = 1;
    stt[s2] = 2;
    stt[s3] = 3;
    stt[s4] = 4;
    siz[1] = 1;
    siz[2] = 2;
    siz[3] = 4;
    siz[4] = 8;
    n = read();
    while (n--)
    {
        int op = read();
        if (op == 1)
        {
            int len = 0;
            char ch = getchar();
            ct++;
            while (ch < 'a' || ch > 'z')
                ch = getchar();
            while (ch >= 'a' && ch <= 'z')
            {
                len++;
                nme[ct][len] = ch;
                ch = getchar();
            }
            tk[ct] = read();
            s.clear();
            len = strlen(nme[ct]) + 1;
            for (int i = 1;i <= len;i++)
                s += nme[ct][i];
            m++;
            stt[s] = m;
            for (int i = 1;i <= tk[ct];i++)
            {
                len = 0;
                ch = getchar();
                while (ch < 'a' || ch > 'z')
                    ch = getchar();
                while (ch >= 'a' && ch <= 'z')
                {
                    len++;
                    snme[ct][i][len] = ch;
                    ch = getchar();
                }
                s.clear();
                for (int j = 1;j <= len;j++)
                    s += snme[ct][i][j];
                tson[ct][i] = stt[s];
                ts[ct][i] = ts[ct][i - 1] + siz[stt[s]];
                len = 0;
                ch = getchar();
                while (ch < 'a' || ch > 'z')
                    ch = getchar();
                while (ch >= 'a' && ch <= 'z')
                {
                    len++;
                    snme[ct][i][len] = ch;
                    ch = getchar();
                }
                s.clear();
                for (int j = 1;j <= len;j++)
                    s += snme[ct][i][j];
                sts[s] = i;
                mx[m] = max(mx[m],siz[tson[ct][i]]);
            }
            siz[m] = ts[ct][tk[ct]];
            if (siz[m] % mx[m])
                siz[m] = (siz[m] / mx[m] + 1) * mx[m];
        }
        else
        {
            if (op == 2)
            {
                int len = 0;
                char ch = getchar();
                cv++;
                while (ch < 'a' || ch > 'z')
                    ch = getchar();
                while (ch >= 'a' && ch <= 'z')
                {
                    len++;
                    vnme[cv][len] = ch;
                    ch = getchar();
                }
                s.clear();
                for (int i = 1;i <= len;i++)
                    s += vnme[cv][i];
                vtyp[cv] = stt[s];
                vpos[cv] = vpos[cv - 1] + siz[vtyp[cv - 1]];
                len = 0;
                ch = getchar();
                while (ch < 'a' || ch > 'z')
                    ch = getchar();
                while (ch >= 'a' && ch <= 'z')
                {
                    len++;
                    vnme[cv][len] = ch;
                    ch = getchar();
                }
                s.clear();
                for (int i = 1;i <= len;i++)
                    s += vnme[cv][i];
                stv[s] = cv;
            }
            else
            {
                if (op == 3)
                {
                    int len = 0,pos = 0;
                    char ch = getchar();
                    while ((ch < 'a' || ch > 'z') && ch != '.')
                        ch = getchar();
                    while ((ch >= 'a' && ch <= 'z') || ch == '.')
                    {
                        len++;
                        st[len] = ch;
                        ch = getchar();
                    }
                    for (int i = 1;i <= len;i++)
                        if (st[i] == '.')
                        {
                            pos = i;
                            break;
                        }
                    if (!pos)
                    {
                        s.clear();
                        for (int i = 1;i <= len;i++)
                            s += st[i];
                        write(vpos[stv[s]]);
                    }
                    else
                    {
                        int id1,id2;
                        s.clear();
                        for (int i = 1;i <= pos - 1;i++)
                            s += st[i];
                        id1 = stv[s];
                        s.clear();
                        for (int i = pos + 1;i <= len;i++)
                            s += st[i];
                        id2 = sts[s];
                        write(vpos[id1] + ts[vtyp[id1]][id2 - 1]);
                    }
                    putchar('\n');
                }
                else
                {
                    long long pos = readll();
                    bool flag = false;
                    for (int i = 1;i <= cv;i++)
                        if (vpos[i] <= pos && (i == cv || vpos[i + 1] > pos))
                        {
                            printf("%s",vnme[i]);
                            if (vtyp[i] > 4)
                            {
                                putchar('.');
                                for (int j = 1;j <= tk[vtyp[i]];j++)
                                    if (ts[vtyp[i]][j] > pos - vpos[i])
                                    {
                                        printf("%s",snme[vtyp[i]][j]);
                                        break;
                                    }
                            }
                            flag = true;
                            break;
                        }
                    if (!flag)
                        printf("ERR");
                    printf("\n");
                }
            }
        }
    }
    return 0;
}