#include <bits/stdc++.h>
using namespace std;

int ovralladr = -1, ovrallcnt = 0;
int n;

struct cls
{
    int sz, matreq, szconlst;
    string conlst[110];
    string typlst[110];
    int strlst[110];
    cls()
    {
        sz = 0, matreq = 0;
        memset(conlst, 0, sizeof(conlst));
        memset(typlst, 0, sizeof(typlst));
        memset(strlst, 0, sizeof(strlst));
    }
    cls(int tmpsz, int tmpmatreq, int conlstsz)
    {
        sz = tmpsz, matreq = tmpmatreq, szconlst = conlstsz;
        memset(conlst, 0, sizeof(conlst));
        memset(typlst, 0, sizeof(typlst));
        memset(strlst, 0, sizeof(strlst));
    }
};

struct clsdf
{
    string typnam;
    int bgnadr, finadr;
};

map <string, cls> clsmp;
map <int, clsdf> clsdef;
map <string, int> defpos;

int fndnxtmat(int matreq, int cur)
{
    return (cur + matreq - 1) / matreq * matreq;
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    clsmp["byte"] = cls(1, 1, 0);
    clsmp["short"] = cls(2, 2, 0);
    clsmp["int"] = cls(4, 4, 0);
    clsmp["long"] = cls(8, 8, 0);
    cin >> n;
    while(n--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            cls thiss;
            int thissadr = 0;
            string clsnam;
            int clssz;
            cin >> clsnam >> clssz;
            thiss = cls();
            int clsmatreq = 0, clsmem = 0;
            for(int i = 1; i <= clssz; i++)
            {
                string tmps, tmpnam;
                thiss.szconlst++;
                cin >> thiss.typlst[thiss.szconlst] >> thiss.conlst[thiss.szconlst];
                thissadr = fndnxtmat(clsmp[thiss.typlst[thiss.szconlst]].matreq, thissadr + 1);
                thiss.strlst[thiss.szconlst] = thissadr;
                thissadr = thissadr + clsmp[thiss.typlst[thiss.szconlst]].sz - 1;
                thiss.matreq = max(thiss.matreq, clsmp[thiss.typlst[thiss.szconlst]].matreq);
            }
            thiss.sz = thissadr;
            clsmp[clsnam] = thiss;
        }
        else if(op == 2)
        {
            string clsnam, defnam;
            cin >> clsnam >> defnam;
            clsdf thiss;
            thiss.typnam = clsnam;
            thiss.bgnadr = fndnxtmat(clsmp[clsnam].matreq, ovralladr);
            thiss.finadr = fndnxtmat(clsmp[clsnam].matreq, ovralladr) + clsmp[clsnam].sz - 1;
            clsdef[++ovrallcnt] = thiss;
            defpos[defnam] = ovrallcnt;
        }
        else if(op == 3)
        {
            string inp = "";
            char inpc = getchar();
            int queadr = 0, ;
            bool flag = false;
            while(true)
            {
                if((inpc = getchar()) == '.')
                {
                    if(!flag)
                    {
                        flag = true;
                        queadr = clsdef[defpos[inp]].bgnadr;

                        inp = "";
                    }
                    else
                    {

                    }
                }
                else if((inpc = getchar()) == '\n')
                {
                    cout << queadr << endl;
                }
                else
                {
                    inp += inpc;
                }
            }
        }
        else
        {

        }
    }
    return 0;
}